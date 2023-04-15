/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_affine_mat_wasm_h
#define cglm_affine_mat_wasm_h
#if defined(__wasm__) && defined(__wasm_simd128__)

#include "../../common.h"
#include "../intrin.h"

CGLM_INLINE
void
glm_mul_wasm(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */
  glmm_128 l, r0, r1, r2, r3, v0, v1, v2, v3;

  l  = glmm_load(m1[0]);
  r0 = glmm_load(m2[0]);
  r1 = glmm_load(m2[1]);
  r2 = glmm_load(m2[2]);
  r3 = glmm_load(m2[3]);

  v0 = wasm_f32x4_mul(glmm_splat_x(r0), l);
  v1 = wasm_f32x4_mul(glmm_splat_x(r1), l);
  v2 = wasm_f32x4_mul(glmm_splat_x(r2), l);
  v3 = wasm_f32x4_mul(glmm_splat_x(r3), l);

  l  = glmm_load(m1[1]);
  v0 = glmm_fmadd(glmm_splat_y(r0), l, v0);
  v1 = glmm_fmadd(glmm_splat_y(r1), l, v1);
  v2 = glmm_fmadd(glmm_splat_y(r2), l, v2);
  v3 = glmm_fmadd(glmm_splat_y(r3), l, v3);

  l  = glmm_load(m1[2]);
  v0 = glmm_fmadd(glmm_splat_z(r0), l, v0);
  v1 = glmm_fmadd(glmm_splat_z(r1), l, v1);
  v2 = glmm_fmadd(glmm_splat_z(r2), l, v2);
  v3 = glmm_fmadd(glmm_splat_z(r3), l, v3);

  l  = glmm_load(m1[3]);
  v3 = glmm_fmadd(glmm_splat_w(r3), l, v3);

  glmm_store(dest[0], v0);
  glmm_store(dest[1], v1);
  glmm_store(dest[2], v2);
  glmm_store(dest[3], v3);
}

CGLM_INLINE
void
glm_mul_rot_wasm(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */

  glmm_128 l, r0, r1, r2, v0, v1, v2;

  l  = glmm_load(m1[0]);
  r0 = glmm_load(m2[0]);
  r1 = glmm_load(m2[1]);
  r2 = glmm_load(m2[2]);

  v0 = wasm_f32x4_mul(glmm_splat_x(r0), l);
  v1 = wasm_f32x4_mul(glmm_splat_x(r1), l);
  v2 = wasm_f32x4_mul(glmm_splat_x(r2), l);

  l  = glmm_load(m1[1]);
  v0 = glmm_fmadd(glmm_splat_y(r0), l, v0);
  v1 = glmm_fmadd(glmm_splat_y(r1), l, v1);
  v2 = glmm_fmadd(glmm_splat_y(r2), l, v2);

  l  = glmm_load(m1[2]);
  v0 = glmm_fmadd(glmm_splat_z(r0), l, v0);
  v1 = glmm_fmadd(glmm_splat_z(r1), l, v1);
  v2 = glmm_fmadd(glmm_splat_z(r2), l, v2);

  glmm_store(dest[0], v0);
  glmm_store(dest[1], v1);
  glmm_store(dest[2], v2);
  glmm_store(dest[3], glmm_load(m1[3]));
}

CGLM_INLINE
void
glm_inv_tr_wasm(mat4 mat) {
  glmm_128 r0, r1, r2, r3, x0, x1, x2, x3, x4, x5;

  r0 = glmm_load(mat[0]);
  r1 = glmm_load(mat[1]);
  r2 = glmm_load(mat[2]);
  r3 = glmm_load(mat[3]);
  x1 = wasm_f32x4_const(0.0f, 0.0f, 0.0f, 1.0f);

  /* _MM_TRANSPOSE4_PS(r0, r1, r2, x1); */
  x2 = wasm_i32x4_shuffle(r0, r1, 0, 4, 1, 5);
  x3 = wasm_i32x4_shuffle(r0, r1, 2, 6, 3, 7);
  x4 = wasm_i32x4_shuffle(r2, x1, 0, 4, 1, 5);
  x5 = wasm_i32x4_shuffle(r2, x1, 2, 6, 3, 7);
  /* r0 = _mm_movelh_ps(x2, x4); */
  r0 = wasm_i32x4_shuffle(x2, x4, 0, 1, 4, 5);
  /* r1 = _mm_movehl_ps(x4, x2); */
  r1 = wasm_i32x4_shuffle(x4, x2, 6, 7, 2, 3);
  /* r2 = _mm_movelh_ps(x3, x5); */
  r2 = wasm_i32x4_shuffle(x3, x5, 0, 1, 4, 5);
  /* x1 = _mm_movehl_ps(x5, x3); */
  x1 = wasm_i32x4_shuffle(x5, x3, 6, 7, 2, 3);

  x2 = glmm_shuff1(r3, 0, 0, 0, 0);
  x3 = glmm_shuff1(r3, 1, 1, 1, 1);
  x4 = glmm_shuff1(r3, 2, 2, 2, 2);

  x0 = glmm_fmadd(r0, x2,
                  glmm_fmadd(r1, x3, wasm_f32x4_mul(r2, x4)));
  x0 = wasm_f32x4_neg(x0);

  x0 = wasm_f32x4_add(x0, x1);

  glmm_store(mat[0], r0);
  glmm_store(mat[1], r1);
  glmm_store(mat[2], r2);
  glmm_store(mat[3], x0);
}

#endif
#endif /* cglm_affine_mat_wasm_h */
