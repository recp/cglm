/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_perlin_h
#define cglm_perlin_h

#include "vec4.h"
#include "vec4-ext.h"

// Based on glm::detail::mod289
// template<typename T>
// GLM_FUNC_QUALIFIER T mod289(T const& x)
// {
// 	return x - floor(x * (static_cast<T>(1.0) / static_cast<T>(289.0))) * static_cast<T>(289.0);
// }

CGLM_INLINE
float
_glm_detail_mod289(float x) {
    return x - floorf(x * (1.0f / 289.0f)) * 289.0f;
}

// Based on glm::detail::permute
// template<typename T, qualifier Q>
// 	GLM_FUNC_QUALIFIER vec<4, T, Q> permute(vec<4, T, Q> const& x)
// 	{
// 		return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
// 	}
CGLM_INLINE
void
_glm_detail_permute(vec4 x, vec4 dest) {
    dest[0] = _glm_detail_mod289(x[0] * 34.0f + 1.0f) * x[0];
    dest[1] = _glm_detail_mod289(x[1] * 34.0f + 1.0f) * x[1];
    dest[2] = _glm_detail_mod289(x[2] * 34.0f + 1.0f) * x[2];
    dest[3] = _glm_detail_mod289(x[3] * 34.0f + 1.0f) * x[3];
}

/*!
 * @brief floor each element of v, result is written to dest
 *
 * @param[in]  v    vector
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
_glm_vec4_floor(vec4 x, vec4 dest) {
    dest[0] = floorf(x[0]);
    dest[1] = floorf(x[1]);
    dest[2] = floorf(x[2]);
    dest[3] = floorf(x[3]);
}

/*!
 * @brief mod v by a scalar, result is written to dest (dest = v % s)
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
_glm_vec4_mods(vec4 x, float y, vec4 dest) {
    dest[0] = fmodf(x[0], y);
    dest[1] = fmodf(x[1], y);
    dest[2] = fmodf(x[2], y);
    dest[3] = fmodf(x[3], y);
}

/*!
 * @brief threshold function with scalar
 *
 * @param[in]   edge    threshold
 * @param[in]   x       value to test against threshold
 * @param[out]  dest    destination
 */
CGLM_INLINE
void
_glm_vec4_steps(vec4 edge, float x, vec4 dest) {
  dest[0] = glm_step(edge[0], x);
  dest[1] = glm_step(edge[1], x);
  dest[2] = glm_step(edge[2], x);
  dest[3] = glm_step(edge[3], x);
}

/*!
 * @brief Classic perlin noise
 *
 * @param[in]  point  4D vector
 * @returns           perlin noise value
 */
CGLM_INLINE
float
glm_perlin(vec4 point) {
    // Integer part of p for indexing
    vec4 Pi0 = {0.0f};
    _glm_vec4_floor(point, Pi0); // Pi0 = floor(point);

    // Integer part + 1
    vec4 Pi1 = {0.0f};
    glm_vec4_adds(Pi0, 1.0f, Pi1); // Pi1 = Pi0 + 1.0f;
    
    _glm_vec4_mods(Pi0, 289.0f, Pi0); // Pi0 = mod(Pi0, 289.0f);
    _glm_vec4_mods(Pi1, 289.0f, Pi1); // Pi1 = mod(Pi1, 289.0f);

    // Fractional part of p for interpolation
    vec4 Pf0;
    glm_vec4_fract(point, Pf0);

    // Fractional part - 1.0
    vec4 Pf1;
    glm_vec4_subs(Pf0, 1.0f, Pf1);

    vec4 ix = {Pi0[0], Pi1[0], Pi0[0], Pi1[0]};
    vec4 iy = {Pi0[1], Pi0[1], Pi1[1], Pi1[1]};
    vec4 iz0 = {Pi0[2], Pi0[2], Pi0[2], Pi0[2]};
    vec4 iz1 = {Pi1[2], Pi1[2], Pi1[2], Pi1[2]};
    vec4 iw0 = {Pi0[3], Pi0[3], Pi0[3], Pi0[3]};
    vec4 iw1 = {Pi1[3], Pi1[3], Pi1[3], Pi1[3]};

    // ixy = permute(permute(ix) + iy)
    vec4 ixy = {0.0f};
    _glm_detail_permute(ix, ixy); // ixy = permute(ix)
    glm_vec4_add(ixy, iy, ixy); // ixy += iy;
    _glm_detail_permute(ixy, ixy); // ixy = permute(ixy)

    // ixy0 = permute(ixy + iz0)
    vec4 ixy0 = {0.0f};
    glm_vec4_add(ixy, iz0, ixy0); // ixy0 = ixy + iz0
    _glm_detail_permute(ixy0, ixy0); // ixy0 = permute(ixy0)

    // ixy1 = permute(ixy + iz1)
    vec4 ixy1 = {0.0f};
    glm_vec4_add(ixy, iz1, ixy1); // ixy1 = ixy, iz1
    _glm_detail_permute(ixy1, ixy1); // ixy1 = permute(ixy1)

    // ixy00 = permute(ixy0 + iw0)
    vec4 ixy00 = {0.0f};
    glm_vec4_add(ixy0, iw0, ixy00); // ixy00 = ixy0 + iw0
    _glm_detail_permute(ixy00, ixy00); // ixy00 = permute(ixy00)

    // ixy01 = permute(ixy0 + iw1)
    vec4 ixy01 = {0.0f};
    glm_vec4_add(ixy0, iw1, ixy01); // ixy01 = ixy0 + iw1
    _glm_detail_permute(ixy01, ixy01); // ixy01 = permute(ixy01)

    // ixy10 = permute(ixy1 + iw0)
    vec4 ixy10 = {0.0f};
    glm_vec4_add(ixy1, iw0, ixy10); // ixy10 = ixy1 + iw0
    _glm_detail_permute(ixy10, ixy10); // ixy10 = permute(ixy10)

    // ixy11 = permute(ixy1 + iw1)
    vec4 ixy11 = {0.0f};
    glm_vec4_add(ixy1, iw1, ixy11); // ixy11 = ixy1 + iw1
    _glm_detail_permute(ixy11, ixy11); // ixy11 = permute(ixy11)

    // ------------

    // gx00 = ixy00 / 7.0
    vec4 gx00 = {0.0f};
    glm_vec4_divs(ixy00, 7.0f, gx00); // gx00 = ixy00 / 7.0

    // gy00 = fract(gx00) / 7.0
    vec4 gy00 = {0.0f};
    _glm_vec4_floor(gx00, gy00); // gy00 = floor(gx00)
    glm_vec4_divs(gy00, 7.0f, gy00); // gy00 /= 7.0

    // gz00 = floor(gy00) / 6.0
    vec4 gz00 = {0.0f};
    _glm_vec4_floor(gy00, gz00); // gz00 = floor(gy00)
    glm_vec4_divs(gz00, 6.0f, gz00); // gz00 /= 6.0

    // gx00 = fract(gx00) - 0.5f
    glm_vec4_fract(gx00, gx00); // gx00 = fract(gx00)
    glm_vec4_subs(gx00, 0.5f, gx00); // gx00 -= 0.5f

    // gy00 = fract(gy00) - 0.5f
    glm_vec4_fract(gy00, gy00); // gy00 = fract(gy00)
    glm_vec4_subs(gy00, 0.5f, gy00); // gy00 -= 0.5f

    // gz00 = fract(gz00) - 0.5f
    glm_vec4_fract(gz00, gz00); // gz00 = fract(gz00)
    glm_vec4_subs(gz00, 0.5f, gz00); // gz00 -= 0.5f

    // abs(gx00), abs(gy00), abs(gz00)
    vec4 gx00a = {0.0f};
    glm_vec4_abs(gx00, gx00a); // gx00a = abs(gx00)
    vec4 gy00a = {0.0f};
    glm_vec4_abs(gy00, gy00a); // gy00a = abs(gy00)
    vec4 gz00a = {0.0f};
    glm_vec4_abs(gz00, gz00a); // gz00a = abs(gz00)

    // gw00 = 0.75 - abs(gx00) - abs(gy00) - abs(gz00)
    vec4 gw00 = {0.75f}; // init to 0.75
    glm_vec4_sub(gw00, gx00a, gw00); // gw00 -= gx00a
    glm_vec4_sub(gw00, gz00a, gw00); // gw00 -= gz00a
    glm_vec4_sub(gw00, gy00a, gw00); // gw00 -= gy00a

    // sw00 = step(gw00, 0.0);
    vec4 sw00 = {0.0f};
    _glm_vec4_steps(gw00, 0.0f, sw00); // sw00 = step(gw00, 0.0)

    // gx00 -= sw00 * (step(vec4(0), gx00) - T(0.5));
    vec4 temp = {0.0f}; // temp = 0.0
    glm_vec4_step(temp, gx00, temp); // temp = step(temp, gx00)
    glm_vec4_subs(temp, 0.5f, temp); // temp -= 0.5
    glm_vec4_mul(sw00, temp, temp); // temp *= sw00
    glm_vec4_sub(gx00, temp, gx00); // gx00 -= temp

    // gy00 -= sw00 * (step(vec4(0), gy00) - T(0.5));
    glm_vec4_zero(temp); // reset temp
    glm_vec4_step(temp, gy00, temp); // temp = step(temp, gy00)
    glm_vec4_subs(temp, 0.5f, temp); // temp -= 0.5
    glm_vec4_mul(sw00, temp, temp); // temp *= sw00
    glm_vec4_sub(gy00, temp, gy00); // gy00 -= temp

    // ------------

    // Work in progress...



    

    



    return point[0] + point[1] + point[2] + point[3];
}


#endif /* cglm_perlin_h */
