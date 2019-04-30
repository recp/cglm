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
  __m128 l0, l1, l2, l3, r;

  l0 = glmm_load(m1[0]);
  l1 = glmm_load(m1[1]);
  l2 = glmm_load(m1[2]);
  l3 = glmm_load(m1[3]);

  r = glmm_load(m2[0]);
  glmm_store(dest[0],
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 0), l0),
                                   _mm_mul_ps(glmm_shuff1x(r, 1), l1)),
                        _mm_mul_ps(glmm_shuff1x(r, 2), l2)));

  r = glmm_load(m2[1]);
  glmm_store(dest[1],
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 0), l0),
                                   _mm_mul_ps(glmm_shuff1x(r, 1), l1)),
                        _mm_mul_ps(glmm_shuff1x(r, 2), l2)));

  r = glmm_load(m2[2]);
  glmm_store(dest[2],
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 0), l0),
                                   _mm_mul_ps(glmm_shuff1x(r, 1), l1)),
                        _mm_mul_ps(glmm_shuff1x(r, 2), l2)));

  r = glmm_load(m2[3]);
  glmm_store(dest[3],
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 0), l0),
                                   _mm_mul_ps(glmm_shuff1x(r, 1), l1)),
                        _mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 2), l2),
                                   _mm_mul_ps(glmm_shuff1x(r, 3), l3))));
}

CGLM_INLINE
void
glm_mul_rot_sse2(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */
  __m128 l0, l1, l2, l3, r;

  l0 = glmm_load(m1[0]);
  l1 = glmm_load(m1[1]);
  l2 = glmm_load(m1[2]);
  l3 = glmm_load(m1[3]);

  r = glmm_load(m2[0]);
  glmm_store(dest[0],
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 0), l0),
                                   _mm_mul_ps(glmm_shuff1x(r, 1), l1)),
                        _mm_mul_ps(glmm_shuff1x(r, 2), l2)));

  r = glmm_load(m2[1]);
  glmm_store(dest[1],
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 0), l0),
                                   _mm_mul_ps(glmm_shuff1x(r, 1), l1)),
                        _mm_mul_ps(glmm_shuff1x(r, 2), l2)));

  r = glmm_load(m2[2]);
  glmm_store(dest[2],
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 0), l0),
                                   _mm_mul_ps(glmm_shuff1x(r, 1), l1)),
                        _mm_mul_ps(glmm_shuff1x(r, 2), l2)));

  glmm_store(dest[3], l3);
}

CGLM_INLINE
void
glm_inv_tr_sse2(mat4 mat) {
  __m128 r0, r1, r2, r3, x0, x1;

  r0 = glmm_load(mat[0]);
  r1 = glmm_load(mat[1]);
  r2 = glmm_load(mat[2]);
  r3 = glmm_load(mat[3]);
  x1 = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);

  _MM_TRANSPOSE4_PS(r0, r1, r2, x1);

  x0 = _mm_add_ps(_mm_mul_ps(r0, glmm_shuff1(r3, 0, 0, 0, 0)),
                  _mm_mul_ps(r1, glmm_shuff1(r3, 1, 1, 1, 1)));
  x0 = _mm_add_ps(x0, _mm_mul_ps(r2, glmm_shuff1(r3, 2, 2, 2, 2)));
  x0 = _mm_xor_ps(x0, _mm_set1_ps(-0.f));

  x0 = _mm_add_ps(x0, x1);

  glmm_store(mat[0], r0);
  glmm_store(mat[1], r1);
  glmm_store(mat[2], r2);
  glmm_store(mat[3], x0);
}

#endif
#endif /* cglm_affine_mat_sse2_h */
