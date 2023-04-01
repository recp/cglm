/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat3_wasm_h
#define cglm_mat3_wasm_h
#if defined(__wasm__) && defined(__wasm_simd128__)

#include "../../common.h"
#include "../intrin.h"

CGLM_INLINE
void
glm_mat3_mul_wasm(mat3 m1, mat3 m2, mat3 dest) {
  glmm_128 l0, l1, l2, r0, r1, r2, x0, x1, x2, x3, x4, x5, x6, x7, x8, x9;
  
  l0 = wasm_v128_load(m1[0]);
  l1 = wasm_v128_load(&m1[1][1]);

  r0 = wasm_v128_load(m2[0]);
  r1 = wasm_v128_load(&m2[1][1]);

  x8 = glmm_shuff1(l0, 0, 2, 1, 0);                     /* a00 a02 a01 a00 */
  x1 = glmm_shuff1(r0, 3, 0, 0, 0);                     /* b10 b00 b00 b00 */
  x2 = wasm_i32x4_shuffle(l0, l1, 3, 3, 4, 5);          /* a12 a11 a10 a10 */
  x3 = wasm_i32x4_shuffle(r0, r1, 1, 3, 4, 6);          /* b20 b11 b10 b01 */
  x0 = wasm_f32x4_mul(x8, x1);

  x6 = glmm_shuff1(l0, 1, 0, 2, 1);                     /* a01 a00 a02 a01 */
  x7 = glmm_shuff1(x3, 3, 3, 1, 1);                     /* b20 b20 b10 b10 */
  l2 = wasm_v128_load32_zero(&m1[2][2]);
  r2 = wasm_v128_load32_zero(&m2[2][2]);
  x1 = wasm_f32x4_mul(x6, x7);
  l2 = glmm_shuff1(l2, 0, 0, 1, 0);                     /* a22 a22 0.f a22 */
  r2 = glmm_shuff1(r2, 0, 0, 1, 0);                     /* b22 b22 0.f b22 */

  x4 = glmm_shuff1(x2, 0, 3, 2, 0);                     /* a10 a12 a11 a10 */
  x5 = glmm_shuff1(x2, 2, 0, 3, 2);                     /* a11 a10 a12 a11 */
  x6 = glmm_shuff1(x3, 2, 0, 0, 0);                     /* b11 b01 b01 b01 */
  x2 = glmm_shuff1(r1, 3, 3, 0, 0);                     /* b21 b21 b11 b11 */

  /* x8 = _mm_unpackhi_ps(x8, x4); */
  /* x9 = _mm_unpackhi_ps(x7, x2); */
  x8 = wasm_i32x4_shuffle(x8, x4, 2, 6, 3, 7);          /* a10 a00 a12 a02 */
  x9 = wasm_i32x4_shuffle(x7, x2, 2, 6, 3, 7);          /* b21 b20 b21 b20 */

  x0 = glmm_fmadd(x4, x6, x0);
  x1 = glmm_fmadd(x5, x2, x1);

  /* x2 = _mm_movehl_ps(l2, l1); */
  x2 = wasm_i32x4_shuffle(l2, l1, 6, 7, 2, 3);          /* a22 a22 a21 a20 */
  x3 = glmm_shuff1(x2, 0, 2, 1, 0);                     /* a20 a22 a21 a20 */
  x2 = glmm_shuff1(x2, 1, 0, 2, 1);                     /* a21 a20 a22 a21 */
  x4 = wasm_i32x4_shuffle(r0, r1, 2, 2, 5, 5);          /* b12 b12 b02 b02 */
  
  x5 = glmm_shuff1(x4, 3, 0, 0, 0);                     /* b12 b02 b02 b02 */
  /* x4 = _mm_movehl_ps(r2, x4); */
  x4 = wasm_i32x4_shuffle(r2, x4, 6, 7, 2, 3);          /* b22 b22 b12 b12 */
  x0 = glmm_fmadd(x3, x5, x0);
  x1 = glmm_fmadd(x2, x4, x1);

  /*
   Dot Product : dest[2][2] =  a02 * b20 +
                               a12 * b21 +
                               a22 * b22 +
                               0   * 00                                    */
  /* x2 = _mm_movelh_ps(x8, l2); */
  /* x3 = _mm_movelh_ps(x9, r2); */
  x2 = wasm_i32x4_shuffle(x8, l2, 0, 1, 4, 5);           /* 0.f a22 a12 a02 */
  x3 = wasm_i32x4_shuffle(x9, r2, 0, 1, 4, 5);           /* 0.f b22 b21 b20 */
  x2 = glmm_vdots(x2, x3);

  /* _mm_storeu_ps(&dest[0][0], x0); */
  wasm_v128_store(&dest[0][0], x0);
  /* _mm_storeu_ps(&dest[1][1], x1); */
  wasm_v128_store(&dest[1][1], x1);
  /* _mm_store_ss (&dest[2][2], x2); */
  wasm_v128_store32_lane(&dest[2][2], x2, 0);
}

#endif
#endif /* cglm_mat3_wasm_h */
