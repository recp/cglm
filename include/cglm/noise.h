/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 *
 * Based on the work of Stefan Gustavson and Ashima Arts on "webgl-noise":
 * https://github.com/stegu/webgl-noise
 * Following Stefan Gustavson's paper "Simplex noise demystified":
 * http://www.itn.liu.se/~stegu/simplexnoise/simplexnoise.pdf
 * 
 * Implementation based on glm::perlin function:
 * https://github.com/g-truc/glm/blob/master/glm/gtc/noise.inl
 */

#ifndef cglm_noise_h
#define cglm_noise_h

#include "vec4.h"
#include "vec4-ext.h"

#include "vec3.h"
#include "vec3-ext.h"

#include "vec2.h"
#include "vec2-ext.h"

#define glm__noiseDetail_mod289(x) (x - floorf(x * (1.0f / 289.0f)) * 289.0f)

/* glm__noiseDetail_permute(vec4 x, vec4 dest) */
#define glm__noiseDetail_permute(x, dest) { \
  dest[0] = glm__noiseDetail_mod289((x[0] * 34.0f + 1.0f) * x[0]); \
  dest[1] = glm__noiseDetail_mod289((x[1] * 34.0f + 1.0f) * x[1]); \
  dest[2] = glm__noiseDetail_mod289((x[2] * 34.0f + 1.0f) * x[2]); \
  dest[3] = glm__noiseDetail_mod289((x[3] * 34.0f + 1.0f) * x[3]); \
}

/* glm__noiseDetail_fade_vec4(vec4 t, vec4 dest) */
#define glm__noiseDetail_fade_vec4(t, dest) { \
  /* dest = (t * t * t) * (t * (t * 6.0f - 15.0f) + 10.0f) */ \
  vec4 temp; \
  glm_vec4_mul(t, t, temp); \
  glm_vec4_mul(temp, t, temp); \
  /* dest = (t * (t * 6.0f - 15.0f) + 10.0f) */ \
  glm_vec4_scale(t, 6.0f, dest); \
  glm_vec4_subs(dest, 15.0f, dest); \
  glm_vec4_mul(t, dest, dest); \
  glm_vec4_adds(dest, 10.0f, dest); \
  /* dest = temp * dest */ \
  glm_vec4_mul(temp, dest, dest); \
}

/* glm__noiseDetail_fade_vec3(vec3 t, vec3 dest) */
#define glm__noiseDetail_fade_vec3(t, dest) { \
  /* dest = (t * t * t) * (t * (t * 6.0f - 15.0f) + 10.0f) */ \
  /* temp = t * t * t */ \
  vec3 temp; \
  glm_vec3_mul(t, t, temp); \
  glm_vec3_mul(temp, t, temp); \
  /* dest = (t * (t * 6.0f - 15.0f) + 10.0f) */ \
  glm_vec3_scale(t, 6.0f, dest); \
  glm_vec3_subs(dest, 15.0f, dest); \
  glm_vec3_mul(t, dest, dest); \
  glm_vec3_adds(dest, 10.0f, dest); \
  /* dest = temp * dest */ \
  glm_vec3_mul(temp, dest, dest); \
}

/* glm__noiseDetail_fade_vec2(vec2 t, vec2 dest) */
#define glm__noiseDetail_fade_vec2(t, dest) { \
    /* dest = (t * t * t) * (t * (t * 6.0f - 15.0f) + 10.0f) */ \
    /* temp = t * t * t */ \
    vec2 temp; \
    glm_vec2_mul(t, t, temp); \
    glm_vec2_mul(temp, t, temp); \
    /* dest = (t * (t * 6.0f - 15.0f) + 10.0f) */ \
    glm_vec2_scale(t, 6.0f, dest); \
    glm_vec2_subs(dest, 15.0f, dest); \
    glm_vec2_mul(t, dest, dest); \
    glm_vec2_adds(dest, 10.0f, dest); \
    /* dest = temp * dest */ \
    glm_vec2_mul(temp, dest, dest); \
}

/* glm__noiseDetail_taylorInvSqrt(vec4 x, vec4 dest) */
#define glm__noiseDetail_taylorInvSqrt(x, dest) {                        \
  /* dest = 1.79284291400159f - 0.85373472095314f * x */                 \
  vec4 temp;                                                             \
  glm_vec4_scale(x, 0.85373472095314f, temp); /* temp = 0.853...f * x */ \
  glm_vec4_fill(dest, 1.79284291400159f); /* dest = 1.792...f */         \
  glm_vec4_sub(dest, temp, dest); /* dest = 1.79284291400159f - temp */  \
}

/* norm = taylorInvSqrt(vec4(
 *     dot(g00__, g00__),
 *     dot(g01__, g01__),
 *     dot(g10__, g10__),
 *     dot(g11__, g11__)
 * ));
*/

/* glm__noiseDetail_gradNorm_vec4(vec4 g00__, vec4 g01__, vec4 g10__, vec4 g11__) */
#define glm__noiseDetail_gradNorm_vec4(g00__, g01__, g10__, g11__) {           \
  vec4 norm;                                                                   \
  norm[0] = glm_vec4_dot(g00__, g00__); /* norm.x = dot(g00__, g00__) */       \
  norm[1] = glm_vec4_dot(g01__, g01__); /* norm.y = dot(g01__, g01__) */       \
  norm[2] = glm_vec4_dot(g10__, g10__); /* norm.z = dot(g10__, g10__) */       \
  norm[3] = glm_vec4_dot(g11__, g11__); /* norm.w = dot(g11__, g11__) */       \
  glm__noiseDetail_taylorInvSqrt(norm, norm); /* norm = taylorInvSqrt(norm) */ \
                                                                               \
  glm_vec4_scale(g00__, norm[0], g00__); /* g00__ *= norm.x */                 \
  glm_vec4_scale(g01__, norm[1], g01__); /* g01__ *= norm.y */                 \
  glm_vec4_scale(g10__, norm[2], g10__); /* g10__ *= norm.z */                 \
  glm_vec4_scale(g11__, norm[3], g11__); /* g11__ *= norm.w */                 \
}

/* glm__noiseDetail_gradNorm_vec3(vec3 g00_, vec3 g01_, vec3 g10_, vec3 g11_) */
#define glm__noiseDetail_gradNorm_vec3(g00_, g01_, g10_, g11_) {               \
  vec4 norm;                                                                   \
  norm[0] = glm_vec3_dot(g00_, g00_); /* norm.x = dot(g00_, g00_) */           \
  norm[1] = glm_vec3_dot(g01_, g01_); /* norm.y = dot(g01_, g01_) */           \
  norm[2] = glm_vec3_dot(g10_, g10_); /* norm.z = dot(g10_, g10_) */           \
  norm[3] = glm_vec3_dot(g11_, g11_); /* norm.w = dot(g11_, g11_) */           \
  glm__noiseDetail_taylorInvSqrt(norm, norm); /* norm = taylorInvSqrt(norm) */ \
                                                                               \
  glm_vec3_scale(g00_, norm[0], g00_); /* g00_ *= norm.x */                    \
  glm_vec3_scale(g01_, norm[1], g01_); /* g01_ *= norm.y */                    \
  glm_vec3_scale(g10_, norm[2], g10_); /* g10_ *= norm.z */                    \
  glm_vec3_scale(g11_, norm[3], g11_); /* g11_ *= norm.w */                    \
}

/* glm__noiseDetail_gradNorm_vec2(vec2 g00, vec2 g01, vec2 g10, vec2 g11) */
#define glm__noiseDetail_gradNorm_vec2(g00, g01, g10, g11) {                   \
  vec4 norm;                                                                   \
  norm[0] = glm_vec2_dot(g00, g00); /* norm.x = dot(g00, g00) */               \
  norm[1] = glm_vec2_dot(g01, g01); /* norm.y = dot(g01, g01) */               \
  norm[2] = glm_vec2_dot(g10, g10); /* norm.z = dot(g10, g10) */               \
  norm[3] = glm_vec2_dot(g11, g11); /* norm.w = dot(g11, g11) */               \
  glm__noiseDetail_taylorInvSqrt(norm, norm); /* norm = taylorInvSqrt(norm) */ \
                                                                               \
  glm_vec2_scale(g00, norm[0], g00); /* g00 *= norm.x */                       \
  glm_vec2_scale(g01, norm[1], g01); /* g01 *= norm.y */                       \
  glm_vec2_scale(g10, norm[2], g10); /* g10 *= norm.z */                       \
  glm_vec2_scale(g11, norm[3], g11); /* g11 *= norm.w */                       \
}

/* glm__noiseDetail_i2gxyzw(vec4 ixy, vec4 gx, vec4 gy, vec4 gz, vec4 gw) */
#define glm__noiseDetail_i2gxyzw(ixy, gx, gy, gz, gw) {      \
  /* gx = ixy / 7.0 */                                       \
  glm_vec4_divs(ixy, 7.0f, gx); /* gx = ixy / 7.0 */         \
                                                             \
  /* gy = fract(gx) / 7.0 */                                 \
  glm_vec4_floor(gx, gy); /* gy = floor(gx) */               \
  glm_vec4_divs(gy, 7.0f, gy); /* gy /= 7.0 */               \
                                                             \
  /* gz = floor(gy) / 6.0 */                                 \
  glm_vec4_floor(gy, gz); /* gz = floor(gy) */               \
  glm_vec4_divs(gz, 6.0f, gz); /* gz /= 6.0 */               \
                                                             \
  /* gx = fract(gx) - 0.5f */                                \
  glm_vec4_fract(gx, gx); /* gx = fract(gx) */               \
  glm_vec4_subs(gx, 0.5f, gx); /* gx -= 0.5f */              \
                                                             \
  /* gy = fract(gy) - 0.5f */                                \
  glm_vec4_fract(gy, gy); /* gy = fract(gy) */               \
  glm_vec4_subs(gy, 0.5f, gy); /* gy -= 0.5f */              \
                                                             \
  /* gz = fract(gz) - 0.5f */                                \
  glm_vec4_fract(gz, gz); /* gz = fract(gz) */               \
  glm_vec4_subs(gz, 0.5f, gz); /* gz -= 0.5f */              \
                                                             \
  /* abs(gx), abs(gy), abs(gz) */                            \
  vec4 gxa, gya, gza;                                        \
  glm_vec4_abs(gx, gxa); /* gxa = abs(gx) */                 \
  glm_vec4_abs(gy, gya); /* gya = abs(gy) */                 \
  glm_vec4_abs(gz, gza); /* gza = abs(gz) */                 \
                                                             \
  /* gw = 0.75 - abs(gx) - abs(gy) - abs(gz) */              \
  glm_vec4_fill(gw, 0.75f); /* gw = 0.75 */                  \
  glm_vec4_sub(gw, gxa, gw); /* gw -= gxa */                 \
  glm_vec4_sub(gw, gza, gw); /* gw -= gza */                 \
  glm_vec4_sub(gw, gya, gw); /* gw -= gya */                 \
                                                             \
  /* sw = step(gw, 0.0); */                                  \
  vec4 sw;                                                   \
  glm_vec4_stepr(gw, 0.0f, sw); /* sw = step(gw, 0.0) */     \
                                                             \
  /* gx -= sw * (step(vec4(0), gx) - T(0.5)); */             \
  vec4 temp = {0.0f}; /* temp = 0.0 */                       \
  glm_vec4_step(temp, gx, temp); /* temp = step(temp, gx) */ \
  glm_vec4_subs(temp, 0.5f, temp); /* temp -= 0.5 */         \
  glm_vec4_mul(sw, temp, temp); /* temp *= sw */             \
  glm_vec4_sub(gx, temp, gx); /* gx -= temp */               \
                                                             \
  /* gy -= sw * (step(vec4(0), gy) - T(0.5)); */             \
  glm_vec4_zero(temp); /* reset temp */                      \
  glm_vec4_step(temp, gy, temp); /* temp = step(temp, gy) */ \
  glm_vec4_subs(temp, 0.5f, temp); /* temp -= 0.5 */         \
  glm_vec4_mul(sw, temp, temp); /* temp *= sw */             \
  glm_vec4_sub(gy, temp, gy); /* gy -= temp */               \
}

/* NOTE: This function is not *quite* analogous to glm__noiseDetail_i2gxyzw
 * to try to match the output of glm::perlin. I think it might be a bug in
 * in the original implementation, but for now I'm keeping it consistent. -MK
 * 
 * Follow up: The original implementation (glm v 1.0.1) does:
 * 
 *   vec<4, T, Q> gx0 = ixy0 * T(1.0 / 7.0);
 * 
 * as opposed to:
 * 
 *   vec<4, T, Q> gx0 = ixy0 / T(7);
 * 
 * This ends up mapping to different simd instructions, at least on AMD.
 * The delta is tiny but it gets amplified by the rest of the noise function.
 * Hence we too need to do `glm_vec4_scale` as opposed to `glm_vec4_divs`, to
 * match it. -MK
 */

/* glm__noiseDetail_i2gxyz(vec4 i, vec4 gx, vec4 gy, vec4 gz) */
#define glm__noiseDetail_i2gxyz(ixy, gx, gy, gz) {               \
  /* gx = ixy / 7.0 */                                           \
  glm_vec4_scale(ixy, 1.0f / 7.0f, gx); /* gx = ixy * (1/7.0) */\
                                                                 \
  /* gy = fract(floor(gx0) / 7.0)) - 0.5; */                     \
  glm_vec4_floor(gx, gy); /* gy = floor(gx) */                   \
  glm_vec4_scale(gy, 1.0f / 7.0f, gy); /* gy *= 1 / 7.0 */       \
  glm_vec4_fract(gy, gy); /* gy = fract(gy) */                   \
  glm_vec4_subs(gy, 0.5f, gy); /* gy -= 0.5f */                  \
                                                                 \
  /* gx = fract(gx); */                                          \
  glm_vec4_fract(gx, gx); /* gx = fract(gx) */                   \
                                                                 \
  /* abs(gx), abs(gy) */                                         \
  vec4 gxa, gya;                                                 \
  glm_vec4_abs(gx, gxa); /* gxa = abs(gx) */                     \
  glm_vec4_abs(gy, gya); /* gya = abs(gy) */                     \
                                                                 \
  /* gz = vec4(0.5) - abs(gx0) - abs(gy0); */                    \
  glm_vec4_fill(gz, 0.5f); /* gz = 0.5 */                        \
  glm_vec4_sub(gz, gxa, gz); /* gz -= gxa */                     \
  glm_vec4_sub(gz, gya, gz); /* gz -= gya */                     \
                                                                 \
  /* sz = step(gw, 0.0); */                                      \
  vec4 sz;                                                       \
  glm_vec4_stepr(gz, 0.0f, sz); /* sz = step(gz, 0.0) */         \
                                                                 \
  /* gx0 -= sz0 * (step(0.0, gx0) - T(0.5)); */                  \
  vec4 temp = {0.0f}; /* temp = 0.0 */                           \
  glm_vec4_step(temp, gx, temp); /* temp = step(temp, gx) */     \
  glm_vec4_subs(temp, 0.5f, temp); /* temp -= 0.5 */             \
  glm_vec4_mul(sz, temp, temp); /* temp *= sz */                 \
  glm_vec4_sub(gx, temp, gx); /* gx -= temp */                   \
                                                                 \
  /* gy0 -= sz0 * (step(0.0, gy0) - T(0.5)); */                  \
  glm_vec4_zero(temp); /* reset temp */                          \
  glm_vec4_step(temp, gy, temp); /* temp = step(temp, gy) */     \
  glm_vec4_subs(temp, 0.5f, temp); /* temp -= 0.5 */             \
  glm_vec4_mul(sz, temp, temp); /* temp *= sz */                 \
  glm_vec4_sub(gy, temp, gy); /* gy -= temp */                   \
}

/* glm__noiseDetail_i2gxy(vec4 i, vec4 gx, vec4 gy) */
#define glm__noiseDetail_i2gxy(i, gx, gy) {                      \
  /* gx = 2.0 * fract(i / 41.0) - 1.0; */                        \
  glm_vec4_divs(i, 41.0f, gx); /* gx = i / 41.0 */               \
  glm_vec4_fract(gx, gx); /* gx = fract(gx) */                   \
  glm_vec4_scale(gx, 2.0f, gx); /* gx *= 2.0 */                  \
  glm_vec4_subs(gx, 1.0f, gx); /* gx -= 1.0 */                   \
                                                                 \
  /* gy = abs(gx) - 0.5; */                                      \
  glm_vec4_abs(gx, gy); /* gy = abs(gx) */                       \
  glm_vec4_subs(gy, 0.5f, gy); /* gy -= 0.5 */                   \
                                                                 \
  /* tx = floor(gx + 0.5); */                                    \
  vec4 tx;                                                       \
  glm_vec4_adds(gx, 0.5f, tx); /* tx = gx + 0.5 */               \
  glm_vec4_floor(tx, tx); /* tx = floor(tx) */                   \
                                                                 \
  /* gx = gx - tx; */                                            \
  glm_vec4_sub(gx, tx, gx); /* gx -= tx */                       \
}

/* ============================================================================
 * Classic perlin noise
 * ============================================================================
 */

/*!
 * @brief Classic perlin noise
 *
 * @param[in]  point  4D vector
 * @returns           perlin noise value
 */
CGLM_INLINE
float
glm_perlin_vec4(vec4 point) {
  /* Integer part of p for indexing */
  vec4 Pi0;
  glm_vec4_floor(point, Pi0); /* Pi0 = floor(point); */

  /* Integer part + 1 */
  vec4 Pi1;
  glm_vec4_adds(Pi0, 1.0f, Pi1); /* Pi1 = Pi0 + 1.0f; */

  glm_vec4_mods(Pi0, 289.0f, Pi0); /* Pi0 = mod(Pi0, 289.0f); */
  glm_vec4_mods(Pi1, 289.0f, Pi1); /* Pi1 = mod(Pi1, 289.0f); */

  /* Fractional part of p for interpolation */
  vec4 Pf0;
  glm_vec4_fract(point, Pf0);

  /* Fractional part - 1.0 */
  vec4 Pf1;
  glm_vec4_subs(Pf0, 1.0f, Pf1);

  vec4 ix = {Pi0[0], Pi1[0], Pi0[0], Pi1[0]};
  vec4 iy = {Pi0[1], Pi0[1], Pi1[1], Pi1[1]};
  vec4 iz0 = {Pi0[2], Pi0[2], Pi0[2], Pi0[2]}; /* iz0 = vec4(Pi0.z); */
  vec4 iz1 = {Pi1[2], Pi1[2], Pi1[2], Pi1[2]}; /* iz1 = vec4(Pi1.z); */
  vec4 iw0 = {Pi0[3], Pi0[3], Pi0[3], Pi0[3]}; /* iw0 = vec4(Pi0.w); */
  vec4 iw1 = {Pi1[3], Pi1[3], Pi1[3], Pi1[3]}; /* iw1 = vec4(Pi1.w); */

  /* ------------ */

  /* ixy = permute(permute(ix) + iy) */
  vec4 ixy;
  glm__noiseDetail_permute(ix, ixy); /* ixy = permute(ix) */
  glm_vec4_add(ixy, iy, ixy); /* ixy += iy; */
  glm__noiseDetail_permute(ixy, ixy); /* ixy = permute(ixy) */

  /* ixy0 = permute(ixy + iz0) */
  vec4 ixy0;
  glm_vec4_add(ixy, iz0, ixy0); /* ixy0 = ixy + iz0 */
  glm__noiseDetail_permute(ixy0, ixy0); /* ixy0 = permute(ixy0) */

  /* ixy1 = permute(ixy + iz1) */
  vec4 ixy1;
  glm_vec4_add(ixy, iz1, ixy1); /* ixy1 = ixy, iz1 */
  glm__noiseDetail_permute(ixy1, ixy1); /* ixy1 = permute(ixy1) */

  /* ixy00 = permute(ixy0 + iw0) */
  vec4 ixy00;
  glm_vec4_add(ixy0, iw0, ixy00); /* ixy00 = ixy0 + iw0 */
  glm__noiseDetail_permute(ixy00, ixy00); /* ixy00 = permute(ixy00) */

  /* ixy01 = permute(ixy0 + iw1) */
  vec4 ixy01;
  glm_vec4_add(ixy0, iw1, ixy01); /* ixy01 = ixy0 + iw1 */
  glm__noiseDetail_permute(ixy01, ixy01); /* ixy01 = permute(ixy01) */

  /* ixy10 = permute(ixy1 + iw0) */
  vec4 ixy10;
  glm_vec4_add(ixy1, iw0, ixy10); /* ixy10 = ixy1 + iw0 */
  glm__noiseDetail_permute(ixy10, ixy10); /* ixy10 = permute(ixy10) */

  /* ixy11 = permute(ixy1 + iw1) */
  vec4 ixy11;
  glm_vec4_add(ixy1, iw1, ixy11); /* ixy11 = ixy1 + iw1 */
  glm__noiseDetail_permute(ixy11, ixy11); /* ixy11 = permute(ixy11) */

  /* ------------ */

  vec4 gx00, gy00, gz00, gw00;
  glm__noiseDetail_i2gxyzw(ixy00, gx00, gy00, gz00, gw00);

  vec4 gx01, gy01, gz01, gw01;
  glm__noiseDetail_i2gxyzw(ixy01, gx01, gy01, gz01, gw01);

  vec4 gx10, gy10, gz10, gw10;
  glm__noiseDetail_i2gxyzw(ixy10, gx10, gy10, gz10, gw10);

  vec4 gx11, gy11, gz11, gw11;
  glm__noiseDetail_i2gxyzw(ixy11, gx11, gy11, gz11, gw11);

  /* ------------ */

  vec4 g0000 = {gx00[0], gy00[0], gz00[0], gw00[0]}; /* g0000 = vec4(gx00.x, gy00.x, gz00.x, gw00.x); */
  vec4 g0100 = {gx00[2], gy00[2], gz00[2], gw00[2]}; /* g0100 = vec4(gx00.z, gy00.z, gz00.z, gw00.z); */
  vec4 g1000 = {gx00[1], gy00[1], gz00[1], gw00[1]}; /* g1000 = vec4(gx00.y, gy00.y, gz00.y, gw00.y); */
  vec4 g1100 = {gx00[3], gy00[3], gz00[3], gw00[3]}; /* g1100 = vec4(gx00.w, gy00.w, gz00.w, gw00.w); */

  vec4 g0001 = {gx01[0], gy01[0], gz01[0], gw01[0]}; /* g0001 = vec4(gx01.x, gy01.x, gz01.x, gw01.x); */
  vec4 g0101 = {gx01[2], gy01[2], gz01[2], gw01[2]}; /* g0101 = vec4(gx01.z, gy01.z, gz01.z, gw01.z); */
  vec4 g1001 = {gx01[1], gy01[1], gz01[1], gw01[1]}; /* g1001 = vec4(gx01.y, gy01.y, gz01.y, gw01.y); */
  vec4 g1101 = {gx01[3], gy01[3], gz01[3], gw01[3]}; /* g1101 = vec4(gx01.w, gy01.w, gz01.w, gw01.w); */

  vec4 g0010 = {gx10[0], gy10[0], gz10[0], gw10[0]}; /* g0010 = vec4(gx10.x, gy10.x, gz10.x, gw10.x); */
  vec4 g0110 = {gx10[2], gy10[2], gz10[2], gw10[2]}; /* g0110 = vec4(gx10.z, gy10.z, gz10.z, gw10.z); */
  vec4 g1010 = {gx10[1], gy10[1], gz10[1], gw10[1]}; /* g1010 = vec4(gx10.y, gy10.y, gz10.y, gw10.y); */
  vec4 g1110 = {gx10[3], gy10[3], gz10[3], gw10[3]}; /* g1110 = vec4(gx10.w, gy10.w, gz10.w, gw10.w); */
  
  vec4 g0011 = {gx11[0], gy11[0], gz11[0], gw11[0]}; /* g0011 = vec4(gx11.x, gy11.x, gz11.x, gw11.x); */
  vec4 g0111 = {gx11[2], gy11[2], gz11[2], gw11[2]}; /* g0111 = vec4(gx11.z, gy11.z, gz11.z, gw11.z); */
  vec4 g1011 = {gx11[1], gy11[1], gz11[1], gw11[1]}; /* g1011 = vec4(gx11.y, gy11.y, gz11.y, gw11.y); */
  vec4 g1111 = {gx11[3], gy11[3], gz11[3], gw11[3]}; /* g1111 = vec4(gx11.w, gy11.w, gz11.w, gw11.w); */

  glm__noiseDetail_gradNorm_vec4(g0000, g0100, g1000, g1100);
  glm__noiseDetail_gradNorm_vec4(g0001, g0101, g1001, g1101);
  glm__noiseDetail_gradNorm_vec4(g0010, g0110, g1010, g1110);
  glm__noiseDetail_gradNorm_vec4(g0011, g0111, g1011, g1111);

  /* ------------ */

  float n0000 = glm_vec4_dot(g0000, Pf0); /* n0000 = dot(g0000, Pf0) */

  /* n1000 = dot(g1000, vec4(Pf1.x, Pf0.y, Pf0.z, Pf0.w)) */
  vec4 n1000d = {Pf1[0], Pf0[1], Pf0[2], Pf0[3]};
  float n1000 = glm_vec4_dot(g1000, n1000d);
  
  /* n0100 = dot(g0100, vec4(Pf0.x, Pf1.y, Pf0.z, Pf0.w)) */
  vec4 n0100d = {Pf0[0], Pf1[1], Pf0[2], Pf0[3]};
  float n0100 = glm_vec4_dot(g0100, n0100d);
  
  /* n1100 = dot(g1100, vec4(Pf1.x, Pf1.y, Pf0.z, Pf0.w)) */
  vec4 n1100d = {Pf1[0], Pf1[1], Pf0[2], Pf0[3]};
  float n1100 = glm_vec4_dot(g1100, n1100d);
  
  /* n0010 = dot(g0010, vec4(Pf0.x, Pf0.y, Pf1.z, Pf0.w)) */
  vec4 n0010d = {Pf0[0], Pf0[1], Pf1[2], Pf0[3]};
  float n0010 = glm_vec4_dot(g0010, n0010d);

  /* n1010 = dot(g1010, vec4(Pf1.x, Pf0.y, Pf1.z, Pf0.w)) */
  vec4 n1010d = {Pf1[0], Pf0[1], Pf1[2], Pf0[3]};
  float n1010 = glm_vec4_dot(g1010, n1010d);

  /* n0110 = dot(g0110, vec4(Pf0.x, Pf1.y, Pf1.z, Pf0.w)) */
  vec4 n0110d = {Pf0[0], Pf1[1], Pf1[2], Pf0[3]};
  float n0110 = glm_vec4_dot(g0110, n0110d);

  /* n1110 = dot(g1110, vec4(Pf1.x, Pf1.y, Pf1.z, Pf0.w)) */
  vec4 n1110d = {Pf1[0], Pf1[1], Pf1[2], Pf0[3]};
  float n1110 = glm_vec4_dot(g1110, n1110d);

  /* n0001 = dot(g0001, vec4(Pf0.x, Pf0.y, Pf0.z, Pf1.w)) */
  vec4 n0001d = {Pf0[0], Pf0[1], Pf0[2], Pf1[3]};
  float n0001 = glm_vec4_dot(g0001, n0001d);

  /* n1001 = dot(g1001, vec4(Pf1.x, Pf0.y, Pf0.z, Pf1.w)) */
  vec4 n1001d = {Pf1[0], Pf0[1], Pf0[2], Pf1[3]};
  float n1001 = glm_vec4_dot(g1001, n1001d);

  /* n0101 = dot(g0101, vec4(Pf0.x, Pf1.y, Pf0.z, Pf1.w)) */
  vec4 n0101d = {Pf0[0], Pf1[1], Pf0[2], Pf1[3]};
  float n0101 = glm_vec4_dot(g0101, n0101d);

  /* n1101 = dot(g1101, vec4(Pf1.x, Pf1.y, Pf0.z, Pf1.w)) */
  vec4 n1101d = {Pf1[0], Pf1[1], Pf0[2], Pf1[3]};
  float n1101 = glm_vec4_dot(g1101, n1101d);

  /* n0011 = dot(g0011, vec4(Pf0.x, Pf0.y, Pf1.z, Pf1.w)) */
  vec4 n0011d = {Pf0[0], Pf0[1], Pf1[2], Pf1[3]};
  float n0011 = glm_vec4_dot(g0011, n0011d);

  /* n1011 = dot(g1011, vec4(Pf1.x, Pf0.y, Pf1.z, Pf1.w)) */
  vec4 n1011d = {Pf1[0], Pf0[1], Pf1[2], Pf1[3]};
  float n1011 = glm_vec4_dot(g1011, n1011d);

  /* n0111 = dot(g0111, vec4(Pf0.x, Pf1.y, Pf1.z, Pf1.w)) */
  vec4 n0111d = {Pf0[0], Pf1[1], Pf1[2], Pf1[3]};
  float n0111 = glm_vec4_dot(g0111, n0111d);

  float n1111 = glm_vec4_dot(g1111, Pf1); /* n1111 = dot(g1111, Pf1) */

  /* ------------ */

  vec4 fade_xyzw;
  glm__noiseDetail_fade_vec4(Pf0, fade_xyzw); /* fade_xyzw = fade(Pf0) */
  
  /* n_0w = lerp(vec4(n0000, n1000, n0100, n1100), vec4(n0001, n1001, n0101, n1101), fade_xyzw.w) */
  vec4 n_0w1 = {n0000, n1000, n0100, n1100};
  vec4 n_0w2 = {n0001, n1001, n0101, n1101};
  vec4 n_0w;
  glm_vec4_lerp(n_0w1, n_0w2, fade_xyzw[3], n_0w);
  
  /* n_1w = lerp(vec4(n0010, n1010, n0110, n1110), vec4(n0011, n1011, n0111, n1111), fade_xyzw.w) */
  vec4 n_1w1 = {n0010, n1010, n0110, n1110};
  vec4 n_1w2 = {n0011, n1011, n0111, n1111};
  vec4 n_1w;
  glm_vec4_lerp(n_1w1, n_1w2, fade_xyzw[3], n_1w);
  
  /* n_zw = lerp(n_0w, n_1w, fade_xyzw.z) */
  vec4 n_zw;
  glm_vec4_lerp(n_0w, n_1w, fade_xyzw[2], n_zw);
  
  /* n_yzw = lerp(vec2(n_zw.x, n_zw.y), vec2(n_zw.z, n_zw.w), fade_xyzw.y) */
  vec2 n_yzw;
  vec2 n_yzw1 = {n_zw[0], n_zw[1]};
  vec2 n_yzw2 = {n_zw[2], n_zw[3]};
  glm_vec2_lerp(n_yzw1, n_yzw2, fade_xyzw[1], n_yzw);

  /* n_xyzw = lerp(n_yzw.x, n_yzw.y, fade_xyzw.x) */
  float n_xyzw = glm_lerp(n_yzw[0], n_yzw[1], fade_xyzw[0]);

  return n_xyzw * 2.2f;
}


/*!
 * @brief Classic perlin noise
 *
 * @param[in]  point  3D vector
 * @returns           perlin noise value
 */
CGLM_INLINE
float
glm_perlin_vec3(vec3 point) {
  /* Integer part of p for indexing */
  vec3 Pi0;
  glm_vec3_floor(point, Pi0); /* Pi0 = floor(point); */

  /* Integer part + 1 */
  vec3 Pi1;
  glm_vec3_adds(Pi0, 1.0f, Pi1); /* Pi1 = Pi0 + 1.0f; */

  glm_vec3_mods(Pi0, 289.0f, Pi0); /* Pi0 = mod(Pi0, 289.0f); */
  glm_vec3_mods(Pi1, 289.0f, Pi1); /* Pi1 = mod(Pi1, 289.0f); */

  /* Fractional part of p for interpolation */
  vec3 Pf0;
  glm_vec3_fract(point, Pf0);

  /* Fractional part - 1.0 */
  vec3 Pf1;
  glm_vec3_subs(Pf0, 1.0f, Pf1);

  vec4 ix = {Pi0[0], Pi1[0], Pi0[0], Pi1[0]};
  vec4 iy = {Pi0[1], Pi0[1], Pi1[1], Pi1[1]};
  vec4 iz0 = {Pi0[2], Pi0[2], Pi0[2], Pi0[2]}; /* iz0 = vec4(Pi0.z); */
  vec4 iz1 = {Pi1[2], Pi1[2], Pi1[2], Pi1[2]}; /* iz1 = vec4(Pi1.z); */

  /* ------------ */

  /* ixy = permute(permute(ix) + iy) */
  vec4 ixy;
  glm__noiseDetail_permute(ix, ixy); /* ixy = permute(ix) */
  glm_vec4_add(ixy, iy, ixy); /* ixy += iy; */
  glm__noiseDetail_permute(ixy, ixy); /* ixy = permute(ixy) */

  /* ixy0 = permute(ixy + iz0) */
  vec4 ixy0;
  glm_vec4_add(ixy, iz0, ixy0); /* ixy0 = ixy + iz0 */
  glm__noiseDetail_permute(ixy0, ixy0); /* ixy0 = permute(ixy0) */

  /* ixy1 = permute(ixy + iz1) */
  vec4 ixy1;
  glm_vec4_add(ixy, iz1, ixy1); /* ixy1 = ixy, iz1 */
  glm__noiseDetail_permute(ixy1, ixy1); /* ixy1 = permute(ixy1) */

  /* ------------ */

  vec4 gx0, gy0, gz0;
  glm__noiseDetail_i2gxyz(ixy0, gx0, gy0, gz0);

  vec4 gx1, gy1, gz1;
  glm__noiseDetail_i2gxyz(ixy1, gx1, gy1, gz1);

  /* ------------ */

  vec3 g000 = {gx0[0], gy0[0], gz0[0]}; /* g000 = vec3(gx0.x, gy0.x, gz0.x); */
  vec3 g100 = {gx0[1], gy0[1], gz0[1]}; /* g100 = vec3(gx0.y, gy0.y, gz0.y); */
  vec3 g010 = {gx0[2], gy0[2], gz0[2]}; /* g010 = vec3(gx0.z, gy0.z, gz0.z); */
  vec3 g110 = {gx0[3], gy0[3], gz0[3]}; /* g110 = vec3(gx0.w, gy0.w, gz0.w); */

  vec3 g001 = {gx1[0], gy1[0], gz1[0]}; /* g001 = vec3(gx1.x, gy1.x, gz1.x); */
  vec3 g101 = {gx1[1], gy1[1], gz1[1]}; /* g101 = vec3(gx1.y, gy1.y, gz1.y); */
  vec3 g011 = {gx1[2], gy1[2], gz1[2]}; /* g011 = vec3(gx1.z, gy1.z, gz1.z); */
  vec3 g111 = {gx1[3], gy1[3], gz1[3]}; /* g111 = vec3(gx1.w, gy1.w, gz1.w); */

  glm__noiseDetail_gradNorm_vec3(g000, g010, g100, g110);
  glm__noiseDetail_gradNorm_vec3(g001, g011, g101, g111);

  /* ------------ */

  float n000 = glm_vec3_dot(g000, Pf0); /* n000 = dot(g000, Pf0) */

  /* n100 = dot(g100, vec3(Pf1.x, Pf0.y, Pf0.z)) */
  vec3 n100d = {Pf1[0], Pf0[1], Pf0[2]};
  float n100 = glm_vec3_dot(g100, n100d);

  /* n010 = dot(g010, vec3(Pf0.x, Pf1.y, Pf0.z)) */
  vec3 n010d = {Pf0[0], Pf1[1], Pf0[2]};
  float n010 = glm_vec3_dot(g010, n010d);

  /* n110 = dot(g110, vec3(Pf1.x, Pf1.y, Pf0.z)) */
  vec3 n110d = {Pf1[0], Pf1[1], Pf0[2]};
  float n110 = glm_vec3_dot(g110, n110d);

  /* n001 = dot(g001, vec3(Pf0.x, Pf0.y, Pf1.z)) */
  vec3 n001d = {Pf0[0], Pf0[1], Pf1[2]};
  float n001 = glm_vec3_dot(g001, n001d);

  /* n101 = dot(g101, vec3(Pf1.x, Pf0.y, Pf1.z)) */
  vec3 n101d = {Pf1[0], Pf0[1], Pf1[2]};
  float n101 = glm_vec3_dot(g101, n101d);

  /* n011 = dot(g011, vec3(Pf0.x, Pf1.y, Pf1.z)) */
  vec3 n011d = {Pf0[0], Pf1[1], Pf1[2]};
  float n011 = glm_vec3_dot(g011, n011d);

  float n111 = glm_vec3_dot(g111, Pf1); /* n111 = dot(g111, Pf1) */

  /* ------------ */

  vec3 fade_xyz;
  glm__noiseDetail_fade_vec3(Pf0, fade_xyz); /* fade_xyz = fade(Pf0) */

  /* n_z = lerp(vec4(n000, n100, n010, n110), vec4(n001, n101, n011, n111), fade_xyz.z); */
  vec4 n_z;
  vec4 n_z1 = {n000, n100, n010, n110};
  vec4 n_z2 = {n001, n101, n011, n111};
  glm_vec4_lerp(n_z1, n_z2, fade_xyz[2], n_z);

  /* vec2 n_yz = lerp(vec2(n_z.x, n_z.y), vec2(n_z.z, n_z.w), fade_xyz.y); */
  vec2 n_yz;
  vec2 n_yz1 = {n_z[0], n_z[1]};
  vec2 n_yz2 = {n_z[2], n_z[3]};
  glm_vec2_lerp(n_yz1, n_yz2, fade_xyz[1], n_yz);

  /* n_xyz = lerp(n_yz.x, n_yz.y, fade_xyz.x); */
  float n_xyz = glm_lerp(n_yz[0], n_yz[1], fade_xyz[0]);

  return n_xyz * 2.2f;
}

/*!
 * @brief Classic perlin noise
 *
 * @param[in]  point  2D vector
 * @returns           perlin noise value
 */
CGLM_INLINE
float
glm_perlin_vec2(vec2 point) {

  /* Integer part of p for indexing */
  /* Pi = floor(vec4(point.x, point.y, point.x, point.y)) + vec4(0.0, 0.0, 1.0, 1.0); */
  vec4 Pi = {point[0], point[1], point[0], point[1]}; /* Pi = vec4(point.x, point.y, point.x, point.y) */
  glm_vec4_floor(Pi, Pi); /* Pi = floor(Pi) */
  Pi[2] += 1.0f; /* Pi.z += 1.0 */
  Pi[3] += 1.0f; /* Pi.w += 1.0 */

  /* Fractional part of p for interpolation */
  /* vec<4, T, Q> Pf = glm::fract(vec<4, T, Q>(Position.x, Position.y, Position.x, Position.y)) - vec<4, T, Q>(0.0, 0.0, 1.0, 1.0); */
  vec4 Pf = {point[0], point[1], point[0], point[1]}; /* Pf = vec4(point.x, point.y, point.x, point.y) */
  glm_vec4_fract(Pf, Pf); /* Pf = fract(Pf) */
  Pf[2] -= 1.0f; /* Pf.z -= 1.0 */
  Pf[3] -= 1.0f; /* Pf.w -= 1.0 */

  /* Mod to avoid truncation effects in permutation */
  glm_vec4_mods(Pi, 289.0f, Pi); /* Pi = mod(Pi, 289.0f); */

  vec4 ix = {Pi[0], Pi[2], Pi[0], Pi[2]}; /* ix = vec4(Pi.x, Pi.z, Pi.x, Pi.z) */
  vec4 iy = {Pi[1], Pi[1], Pi[3], Pi[3]}; /* iy = vec4(Pi.y, Pi.y, Pi.w, Pi.w) */
  vec4 fx = {Pf[0], Pf[2], Pf[0], Pf[2]}; /* fx = vec4(Pf.x, Pf.z, Pf.x, Pf.z) */
  vec4 fy = {Pf[1], Pf[1], Pf[3], Pf[3]}; /* fy = vec4(Pf.y, Pf.y, Pf.w, Pf.w) */

  /* ------------ */

  /* i = permute(permute(ix) + iy); */
  vec4 i;
  glm__noiseDetail_permute(ix, i); /* i = permute(ix) */
  glm_vec4_add(i, iy, i); /* i += iy; */
  glm__noiseDetail_permute(i, i); /* i = permute(i) */

  /* ------------ */

  vec4 gx, gy;
  glm__noiseDetail_i2gxy(i, gx, gy);

  /* ------------ */

  vec2 g00 = {gx[0], gy[0]}; /* g00 = vec2(gx.x, gy.x) */
  vec2 g10 = {gx[1], gy[1]}; /* g10 = vec2(gx.y, gy.y) */
  vec2 g01 = {gx[2], gy[2]}; /* g01 = vec2(gx.z, gy.z) */
  vec2 g11 = {gx[3], gy[3]}; /* g11 = vec2(gx.w, gy.w) */

  glm__noiseDetail_gradNorm_vec2(g00, g01, g10, g11);

  /* ------------ */

  /* n00 = dot(g00, vec2(fx.x, fy.x)) */
  vec2 n00d = {fx[0], fy[0]}; /* n00d = vec2(fx.x, fy.x) */
  float n00 = glm_vec2_dot(g00, n00d); /* n00 = dot(g00, n00d) */

  /* n10 = dot(g10, vec2(fx.y, fy.y)) */
  vec2 n10d = {fx[1], fy[1]}; /* n10d = vec2(fx.y, fy.y) */
  float n10 = glm_vec2_dot(g10, n10d); /* n10 = dot(g10, n10d) */

  /* n01 = dot(g01, vec2(fx.z, fy.z)) */
  vec2 n01d = {fx[2], fy[2]}; /* n01d = vec2(fx.z, fy.z) */
  float n01 = glm_vec2_dot(g01, n01d); /* n01 = dot(g01, n01d) */

  /* n11 = dot(g11, vec2(fx.w, fy.w)) */
  vec2 n11d = {fx[3], fy[3]}; /* n11d = vec2(fx.w, fy.w) */
  float n11 = glm_vec2_dot(g11, n11d); /* n11 = dot(g11, n11d) */

  /* ------------ */

  /* fade_xyz = fade(vec2(Pf.x, Pf.y)) */
  vec2 fade_xy;
  vec2 temp2 = {Pf[0], Pf[1]}; /* temp = vec2(Pf.x, Pf.y) */
  glm__noiseDetail_fade_vec2(temp2, fade_xy); /* fade_xy = fade(temp) */

  /* n_x = lerp(vec2(n00, n01), vec2(n10, n11), fade_xy.x); */
  vec2 n_x;
  vec2 n_x1 = {n00, n01}; /* n_x1 = vec2(n00, n01) */
  vec2 n_x2 = {n10, n11}; /* n_x2 = vec2(n10, n11) */
  glm_vec2_lerp(n_x1, n_x2, fade_xy[0], n_x); /* n_x = lerp(n_x1, n_x2, fade_xy.x) */

  /* T n_xy = mix(n_x.x, n_x.y, fade_xy.y); */
  /* n_xy = lerp(n_x.x, n_x.y, fade_xy.y); */
  float n_xy = glm_lerp(n_x[0], n_x[1], fade_xy[1]);

  return n_xy * 2.3f;
}

/* Undefine all helper macros */

#undef glm__noiseDetail_mod289
#undef glm__noiseDetail_permute
#undef glm__noiseDetail_fade_vec4
#undef glm__noiseDetail_fade_vec3
#undef glm__noiseDetail_fade_vec2
#undef glm__noiseDetail_taylorInvSqrt
#undef glm__noiseDetail_gradNorm_vec4
#undef glm__noiseDetail_gradNorm_vec3
#undef glm__noiseDetail_gradNorm_vec2
#undef glm__noiseDetail_i2gxyzw
#undef glm__noiseDetail_i2gxyz
#undef glm__noiseDetail_i2gxy

#endif /* cglm_noise_h */
