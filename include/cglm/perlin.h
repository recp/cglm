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

#include "vec2.h"
#include "vec2-ext.h"

//////////////////////////////


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
 * @brief set all elements of dest to value
 *
 * @param[in]   vector  threshold
 * @param[in]   x       value
 */
CGLM_INLINE
void
_glm_vec4_sets(vec4 v, float x) {
  v[0] = x;
  v[1] = x;
  v[2] = x;
  v[3] = x;
}

/*!
 * @brief mul v by a scalar, result is written to dest (dest = v * s)
 *
 * @param[in]  v    vector
 * @param[in]  s    scalar
 * @param[out] dest destination vector
 */
CGLM_INLINE
void
_glm_vec4_muls(vec4 x, float y, vec4 dest) {
    dest[0] = x[0] * y;
    dest[1] = x[1] * y;
    dest[2] = x[2] * y;
    dest[3] = x[3] * y;
}


//////////////////////////////



// Based on glm::detail::mod289
// template<typename T>
// GLM_FUNC_QUALIFIER T mod289(T const& x)
// {
//     return x - floor(x * (static_cast<T>(1.0) / static_cast<T>(289.0))) * static_cast<T>(289.0);
// }

CGLM_INLINE
float
_glm_perlinDetail_mod289(float x) {
    return x - floorf(x * (1.0f / 289.0f)) * 289.0f;
}

// Based on glm::detail::permute
// template<typename T, qualifier Q>
//     GLM_FUNC_QUALIFIER vec<4, T, Q> permute(vec<4, T, Q> const& x)
//     {
//         return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
//     }
CGLM_INLINE
void
_glm_perlinDetail_permute(vec4 x, vec4 dest) {
    dest[0] = _glm_perlinDetail_mod289((x[0] * 34.0f + 1.0f) * x[0]);
    dest[1] = _glm_perlinDetail_mod289((x[1] * 34.0f + 1.0f) * x[1]);
    dest[2] = _glm_perlinDetail_mod289((x[2] * 34.0f + 1.0f) * x[2]);
    dest[3] = _glm_perlinDetail_mod289((x[3] * 34.0f + 1.0f) * x[3]);
}


// GLM_FUNC_QUALIFIER vec<4, T, Q> taylorInvSqrt(vec<4, T, Q> const& r)
// {
//     return static_cast<T>(1.79284291400159) - static_cast<T>(0.85373472095314) * r;
// }

CGLM_INLINE
void
_glm_perlinDetail_taylorInvSqrt(vec4 x, vec4 dest) {
    dest[0] = 1.79284291400159f - 0.85373472095314f * x[0];
    dest[1] = 1.79284291400159f - 0.85373472095314f * x[1];
    dest[2] = 1.79284291400159f - 0.85373472095314f * x[2];
    dest[3] = 1.79284291400159f - 0.85373472095314f * x[3];
}

// template<typename T, qualifier Q>
// GLM_FUNC_QUALIFIER vec<4, T, Q> fade(vec<4, T, Q> const& t)
// {
//     return (t * t * t) * (t * (t * static_cast<T>(6) - static_cast<T>(15)) + static_cast<T>(10));
// }

CGLM_INLINE
void
_glm_perlinDetail_fade(vec4 t, vec4 dest) {
    dest[0] = (t[0] * t[0] * t[0]) * (t[0] * (t[0] * 6.0f - 15.0f) + 10.0f);
    dest[1] = (t[1] * t[1] * t[1]) * (t[1] * (t[1] * 6.0f - 15.0f) + 10.0f);
    dest[2] = (t[2] * t[2] * t[2]) * (t[2] * (t[2] * 6.0f - 15.0f) + 10.0f);
    dest[3] = (t[3] * t[3] * t[3]) * (t[3] * (t[3] * 6.0f - 15.0f) + 10.0f);
}

CGLM_INLINE
void
_glm_perlinDetail_gNorm(vec4 g0000, vec4 g0100, vec4 g1000, vec4 g1100) {

    // norm = taylorInvSqrt(
    //              vec4(
    //                  dot(g0000, g0000),
    //                  dot(g0100, g0100),
    //                  dot(g1000, g1000),
    //                  dot(g1100, g1100)
    //              )
    //          );
    vec4 norm;
    norm[0] = glm_vec4_dot(g0000, g0000); // norm.x = dot(g0000, g0000)
    norm[1] = glm_vec4_dot(g0100, g0100); // norm.y = dot(g0100, g0100)
    norm[2] = glm_vec4_dot(g1000, g1000); // norm.z = dot(g1000, g1000)
    norm[3] = glm_vec4_dot(g1100, g1100); // norm.w = dot(g1100, g1100)
    _glm_perlinDetail_taylorInvSqrt(norm, norm); // norm = taylorInvSqrt(norm)
    
    _glm_vec4_muls(g0000, norm[0], g0000); // g0000 *= norm.x
    _glm_vec4_muls(g0100, norm[1], g0100); // g0100 *= norm.y
    _glm_vec4_muls(g1000, norm[2], g1000); // g1000 *= norm.z
    _glm_vec4_muls(g1100, norm[3], g1100); // g1100 *= norm.w
}

CGLM_INLINE
void
_glm_perlinDetail_xy2g(
    vec4 ixy,
    /* out */
    vec4 gx,
    vec4 gy,
    vec4 gz,
    vec4 gw
) {
    // gx = ixy / 7.0
    glm_vec4_divs(ixy, 7.0f, gx); // gx = ixy / 7.0

    // gy = fract(gx) / 7.0
    _glm_vec4_floor(gx, gy); // gy = floor(gx)
    glm_vec4_divs(gy, 7.0f, gy); // gy /= 7.0

    // gz = floor(gy) / 6.0
    _glm_vec4_floor(gy, gz); // gz = floor(gy)
    glm_vec4_divs(gz, 6.0f, gz); // gz /= 6.0

    // gx = fract(gx) - 0.5f
    glm_vec4_fract(gx, gx); // gx = fract(gx)
    glm_vec4_subs(gx, 0.5f, gx); // gx -= 0.5f

    // gy = fract(gy) - 0.5f
    glm_vec4_fract(gy, gy); // gy = fract(gy)
    glm_vec4_subs(gy, 0.5f, gy); // gy -= 0.5f

    // gz = fract(gz) - 0.5f
    glm_vec4_fract(gz, gz); // gz = fract(gz)
    glm_vec4_subs(gz, 0.5f, gz); // gz -= 0.5f

    // abs(gx), abs(gy), abs(gz)
    vec4 gxa;
    glm_vec4_abs(gx, gxa); // gxa = abs(gx)
    vec4 gya;
    glm_vec4_abs(gy, gya); // gya = abs(gy)
    vec4 gza;
    glm_vec4_abs(gz, gza); // gza = abs(gz)

    // gw = 0.75 - abs(gx) - abs(gy) - abs(gz)
    _glm_vec4_sets(gw, 0.75f); // gw = 0.75
    glm_vec4_sub(gw, gxa, gw); // gw -= gxa
    glm_vec4_sub(gw, gza, gw); // gw -= gza
    glm_vec4_sub(gw, gya, gw); // gw -= gya

    // sw = step(gw, 0.0);
    vec4 sw;
    _glm_vec4_steps(gw, 0.0f, sw); // sw = step(gw, 0.0)

    // gx -= sw * (step(vec4(0), gx) - T(0.5));
    vec4 temp = {0.0f}; // temp = 0.0
    glm_vec4_step(temp, gx, temp); // temp = step(temp, gx)
    glm_vec4_subs(temp, 0.5f, temp); // temp -= 0.5
    glm_vec4_mul(sw, temp, temp); // temp *= sw
    glm_vec4_sub(gx, temp, gx); // gx -= temp

    // gy -= sw * (step(vec4(0), gy) - T(0.5));
    glm_vec4_zero(temp); // reset temp
    glm_vec4_step(temp, gy, temp); // temp = step(temp, gy)
    glm_vec4_subs(temp, 0.5f, temp); // temp -= 0.5
    glm_vec4_mul(sw, temp, temp); // temp *= sw
    glm_vec4_sub(gy, temp, gy); // gy -= temp
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
    vec4 Pi0;
    _glm_vec4_floor(point, Pi0); // Pi0 = floor(point);


    // Integer part + 1
    vec4 Pi1;
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
    vec4 iz0 = {Pi0[2], Pi0[2], Pi0[2], Pi0[2]}; // iz0 = vec4(Pi0.z);
    vec4 iz1 = {Pi1[2], Pi1[2], Pi1[2], Pi1[2]}; // iz1 = vec4(Pi1.z);
    vec4 iw0 = {Pi0[3], Pi0[3], Pi0[3], Pi0[3]}; // iw0 = vec4(Pi0.w);
    vec4 iw1 = {Pi1[3], Pi1[3], Pi1[3], Pi1[3]}; // iw1 = vec4(Pi1.w);

    // ixy = permute(permute(ix) + iy)
    vec4 ixy;
    _glm_perlinDetail_permute(ix, ixy); // ixy = permute(ix)
    glm_vec4_add(ixy, iy, ixy); // ixy += iy;
    _glm_perlinDetail_permute(ixy, ixy); // ixy = permute(ixy)

    // ixy0 = permute(ixy + iz0)
    vec4 ixy0;
    glm_vec4_add(ixy, iz0, ixy0); // ixy0 = ixy + iz0
    _glm_perlinDetail_permute(ixy0, ixy0); // ixy0 = permute(ixy0)

    // ixy1 = permute(ixy + iz1)
    vec4 ixy1;
    glm_vec4_add(ixy, iz1, ixy1); // ixy1 = ixy, iz1
    _glm_perlinDetail_permute(ixy1, ixy1); // ixy1 = permute(ixy1)

    // ixy00 = permute(ixy0 + iw0)
    vec4 ixy00;
    glm_vec4_add(ixy0, iw0, ixy00); // ixy00 = ixy0 + iw0
    _glm_perlinDetail_permute(ixy00, ixy00); // ixy00 = permute(ixy00)

    // ixy01 = permute(ixy0 + iw1)
    vec4 ixy01;
    glm_vec4_add(ixy0, iw1, ixy01); // ixy01 = ixy0 + iw1
    _glm_perlinDetail_permute(ixy01, ixy01); // ixy01 = permute(ixy01)

    // ixy10 = permute(ixy1 + iw0)
    vec4 ixy10;
    glm_vec4_add(ixy1, iw0, ixy10); // ixy10 = ixy1 + iw0
    _glm_perlinDetail_permute(ixy10, ixy10); // ixy10 = permute(ixy10)

    // ixy11 = permute(ixy1 + iw1)
    vec4 ixy11;
    glm_vec4_add(ixy1, iw1, ixy11); // ixy11 = ixy1 + iw1
    _glm_perlinDetail_permute(ixy11, ixy11); // ixy11 = permute(ixy11)

    // ------------

    vec4 gx00;
    vec4 gy00;
    vec4 gz00;
    vec4 gw00;
    _glm_perlinDetail_xy2g(ixy00, gx00, gy00, gz00, gw00);

    vec4 gx01;
    vec4 gy01;
    vec4 gz01;
    vec4 gw01;
    _glm_perlinDetail_xy2g(ixy01, gx01, gy01, gz01, gw01);

    vec4 gx10;
    vec4 gy10;
    vec4 gz10;
    vec4 gw10;
    _glm_perlinDetail_xy2g(ixy10, gx10, gy10, gz10, gw10);

    vec4 gx11;
    vec4 gy11;
    vec4 gz11;
    vec4 gw11;
    _glm_perlinDetail_xy2g(ixy11, gx11, gy11, gz11, gw11);

    // ------------

    vec4 g0000 = {gx00[0], gy00[0], gz00[0], gw00[0]}; // g0000 = vec4(gx00.x, gy00.x, gz00.x, gw00.x);
    vec4 g1000 = {gx00[1], gy00[1], gz00[1], gw00[1]}; // g1000 = vec4(gx00.y, gy00.y, gz00.y, gw00.y);
    vec4 g0100 = {gx00[2], gy00[2], gz00[2], gw00[2]}; // g0100 = vec4(gx00.z, gy00.z, gz00.z, gw00.z);
    vec4 g1100 = {gx00[3], gy00[3], gz00[3], gw00[3]}; // g1100 = vec4(gx00.w, gy00.w, gz00.w, gw00.w);
    vec4 g0010 = {gx10[0], gy10[0], gz10[0], gw10[0]}; // g0010 = vec4(gx10.x, gy10.x, gz10.x, gw10.x);
    vec4 g1010 = {gx10[1], gy10[1], gz10[1], gw10[1]}; // g1010 = vec4(gx10.y, gy10.y, gz10.y, gw10.y);
    vec4 g0110 = {gx10[2], gy10[2], gz10[2], gw10[2]}; // g0110 = vec4(gx10.z, gy10.z, gz10.z, gw10.z);
    vec4 g1110 = {gx10[3], gy10[3], gz10[3], gw10[3]}; // g1110 = vec4(gx10.w, gy10.w, gz10.w, gw10.w);
    vec4 g0001 = {gx01[0], gy01[0], gz01[0], gw01[0]}; // g0001 = vec4(gx01.x, gy01.x, gz01.x, gw01.x);
    vec4 g1001 = {gx01[1], gy01[1], gz01[1], gw01[1]}; // g1001 = vec4(gx01.y, gy01.y, gz01.y, gw01.y);
    vec4 g0101 = {gx01[2], gy01[2], gz01[2], gw01[2]}; // g0101 = vec4(gx01.z, gy01.z, gz01.z, gw01.z);
    vec4 g1101 = {gx01[3], gy01[3], gz01[3], gw01[3]}; // g1101 = vec4(gx01.w, gy01.w, gz01.w, gw01.w);
    vec4 g0011 = {gx11[0], gy11[0], gz11[0], gw11[0]}; // g0011 = vec4(gx11.x, gy11.x, gz11.x, gw11.x);
    vec4 g1011 = {gx11[1], gy11[1], gz11[1], gw11[1]}; // g1011 = vec4(gx11.y, gy11.y, gz11.y, gw11.y);
    vec4 g0111 = {gx11[2], gy11[2], gz11[2], gw11[2]}; // g0111 = vec4(gx11.z, gy11.z, gz11.z, gw11.z);
    vec4 g1111 = {gx11[3], gy11[3], gz11[3], gw11[3]}; // g1111 = vec4(gx11.w, gy11.w, gz11.w, gw11.w);

    _glm_perlinDetail_gNorm(g0000, g0100, g1000, g1100);
    _glm_perlinDetail_gNorm(g0001, g0101, g1001, g1101);
    _glm_perlinDetail_gNorm(g0010, g0110, g1010, g1110);
    _glm_perlinDetail_gNorm(g0011, g0111, g1011, g1111);

    // ------------

    float n0000 = glm_vec4_dot(g0000, Pf0); // n0000 = dot(g0000, Pf0)

    // n1000 = dot(g1000, vec4(Pf1.x, Pf0.y, Pf0.z, Pf0.w))
    vec4 n1000d = {Pf1[0], Pf0[1], Pf0[2], Pf0[3]};
    float n1000 = glm_vec4_dot(g1000, n1000d);
    
    // n0100 = dot(g0100, vec4(Pf0.x, Pf1.y, Pf0.z, Pf0.w))
    vec4 n0100d = {Pf0[0], Pf1[1], Pf0[2], Pf0[3]};
    float n0100 = glm_vec4_dot(g0100, n0100d);
    
    // n1100 = dot(g1100, vec4(Pf1.x, Pf1.y, Pf0.z, Pf0.w))
    vec4 n1100d = {Pf1[0], Pf1[1], Pf0[2], Pf0[3]};
    float n1100 = glm_vec4_dot(g1100, n1100d);
    
    // n0010 = dot(g0010, vec4(Pf0.x, Pf0.y, Pf1.z, Pf0.w))
    vec4 n0010d = {Pf0[0], Pf0[1], Pf1[2], Pf0[3]};
    float n0010 = glm_vec4_dot(g0010, n0010d);

    // n1010 = dot(g1010, vec4(Pf1.x, Pf0.y, Pf1.z, Pf0.w))
    vec4 n1010d = {Pf1[0], Pf0[1], Pf1[2], Pf0[3]};
    float n1010 = glm_vec4_dot(g1010, n1010d);

    // n0110 = dot(g0110, vec4(Pf0.x, Pf1.y, Pf1.z, Pf0.w))
    vec4 n0110d = {Pf0[0], Pf1[1], Pf1[2], Pf0[3]};
    float n0110 = glm_vec4_dot(g0110, n0110d);

    // n1110 = dot(g1110, vec4(Pf1.x, Pf1.y, Pf1.z, Pf0.w))
    vec4 n1110d = {Pf1[0], Pf1[1], Pf1[2], Pf0[3]};
    float n1110 = glm_vec4_dot(g1110, n1110d);

    // n0001 = dot(g0001, vec4(Pf0.x, Pf0.y, Pf0.z, Pf1.w))
    vec4 n0001d = {Pf0[0], Pf0[1], Pf0[2], Pf1[3]};
    float n0001 = glm_vec4_dot(g0001, n0001d);

    // n1001 = dot(g1001, vec4(Pf1.x, Pf0.y, Pf0.z, Pf1.w))
    vec4 n1001d = {Pf1[0], Pf0[1], Pf0[2], Pf1[3]};
    float n1001 = glm_vec4_dot(g1001, n1001d);

    // n0101 = dot(g0101, vec4(Pf0.x, Pf1.y, Pf0.z, Pf1.w))
    vec4 n0101d = {Pf0[0], Pf1[1], Pf0[2], Pf1[3]};
    float n0101 = glm_vec4_dot(g0101, n0101d);

    // n1101 = dot(g1101, vec4(Pf1.x, Pf1.y, Pf0.z, Pf1.w))
    vec4 n1101d = {Pf1[0], Pf1[1], Pf0[2], Pf1[3]};
    float n1101 = glm_vec4_dot(g1101, n1101d);

    // n0011 = dot(g0011, vec4(Pf0.x, Pf0.y, Pf1.z, Pf1.w))
    vec4 n0011d = {Pf0[0], Pf0[1], Pf1[2], Pf1[3]};
    float n0011 = glm_vec4_dot(g0011, n0011d);

    // n1011 = dot(g1011, vec4(Pf1.x, Pf0.y, Pf1.z, Pf1.w))
    vec4 n1011d = {Pf1[0], Pf0[1], Pf1[2], Pf1[3]};
    float n1011 = glm_vec4_dot(g1011, n1011d);

    // n0111 = dot(g0111, vec4(Pf0.x, Pf1.y, Pf1.z, Pf1.w))
    vec4 n0111d = {Pf0[0], Pf1[1], Pf1[2], Pf1[3]};
    float n0111 = glm_vec4_dot(g0111, n0111d);

    float n1111 = glm_vec4_dot(g1111, Pf1); // n1111 = dot(g1111, Pf1)

    // ------------

    // fade_xyzw = detail::fade(Pf0);
    // n_0w = lerp(
    //           vec4(n0000, n1000, n0100, n1100),
    //           vec4(n0001, n1001, n0101, n1101),
    //           fade_xyzw.w,
    //       );

    vec4 fade_xyzw;
    _glm_perlinDetail_fade(Pf0, fade_xyzw); // fade_xyzw = fade(Pf0)
    
    // n_0w = lerp(vec4(n0000, n1000, n0100, n1100), vec4(n0001, n1001, n0101, n1101), fade_xyzw.w)
    vec4 n_0w1 = {n0000, n1000, n0100, n1100};
    vec4 n_0w2 = {n0001, n1001, n0101, n1101};
    vec4 n_0w;
    glm_vec4_lerp(n_0w1, n_0w2, fade_xyzw[3], n_0w);
    
    // n_1w = lerp(vec4(n0010, n1010, n0110, n1110), vec4(n0011, n1011, n0111, n1111), fade_xyzw.w)
    vec4 n_1w1 = {n0010, n1010, n0110, n1110};
    vec4 n_1w2 = {n0011, n1011, n0111, n1111};
    vec4 n_1w;
    glm_vec4_lerp(n_1w1, n_1w2, fade_xyzw[3], n_1w);
    
    // n_zw = lerp(n_0w, n_1w, fade_xyzw.z)
    vec4 n_zw;
    glm_vec4_lerp(n_0w, n_1w, fade_xyzw[2], n_zw);
    
    // n_yzw = lerp(vec2(n_zw.x, n_zw.y), vec2(n_zw.z, n_zw.w), fade_xyzw.y)
    vec2 n_yzw;
    vec2 n_yzw1 = {n_zw[0], n_zw[1]};
    vec2 n_yzw2 = {n_zw[2], n_zw[3]};
    glm_vec2_lerp(n_yzw1, n_yzw2, fade_xyzw[1], n_yzw);

    // n_xyzw = lerp(n_yzw.x, n_yzw.y, fade_xyzw.x)
    float n_xyzw = glm_lerp(n_yzw[0], n_yzw[1], fade_xyzw[0]);

    return n_xyzw * 2.2f;
}


#endif /* cglm_perlin_h */
