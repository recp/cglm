/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_affine_mat_sse2_h
#define cglm_affine_mat_sse2_h
#if defined( __SSE__ ) || defined( __SSE2__ )

#include "../../common.h"
#include "../intrin.h"

CGLM_INLINE
void
glm_mul_sse2(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */
  glmm_128 l, r0, r1, r2, r3, v0, v1, v2, v3;

  l  = glmm_load(m1[0]);
  r0 = glmm_load(m2[0]);
  r1 = glmm_load(m2[1]);
  r2 = glmm_load(m2[2]);
  r3 = glmm_load(m2[3]);

  v0 = _mm_mul_ps(glmm_splat_x(r0), l);
  v1 = _mm_mul_ps(glmm_splat_x(r1), l);
  v2 = _mm_mul_ps(glmm_splat_x(r2), l);
  v3 = _mm_mul_ps(glmm_splat_x(r3), l);

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
glm_mul_rot_sse2(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */

  glmm_128 l, r0, r1, r2, v0, v1, v2;

  l  = glmm_load(m1[0]);
  r0 = glmm_load(m2[0]);
  r1 = glmm_load(m2[1]);
  r2 = glmm_load(m2[2]);

  v0 = _mm_mul_ps(glmm_splat_x(r0), l);
  v1 = _mm_mul_ps(glmm_splat_x(r1), l);
  v2 = _mm_mul_ps(glmm_splat_x(r2), l);

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
glm_inv_tr_sse2(mat4 mat) {
  __m128 r0, r1, r2, r3, x0, x1, x2, x3, x4, x5;

  r0 = glmm_load(mat[0]);
  r1 = glmm_load(mat[1]);
  r2 = glmm_load(mat[2]);
  r3 = glmm_load(mat[3]);
  x1 = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);

  _MM_TRANSPOSE4_PS(r0, r1, r2, x1);

  x2 = glmm_shuff1(r3, 0, 0, 0, 0);
  x3 = glmm_shuff1(r3, 1, 1, 1, 1);
  x4 = glmm_shuff1(r3, 2, 2, 2, 2);
  x5 = _mm_set1_ps(-0.f);

  x0 = glmm_fmadd(r0, x2, glmm_fmadd(r1, x3, _mm_mul_ps(r2, x4)));
  x0 = _mm_xor_ps(x0, x5);

  x0 = _mm_add_ps(x0, x1);

  glmm_store(mat[0], r0);
  glmm_store(mat[1], r1);
  glmm_store(mat[2], r2);
  glmm_store(mat[3], x0);
}

#endif
#endif /* cglm_affine_mat_sse2_h */
