/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_affine_mat_sse2_h
#define cglm_affine_mat_sse2_h
#if defined( __SSE__ ) || defined( __SSE2__ )

#include "cglm-intrin.h"
#include "cglm.h"

CGLM_INLINE
void
glm_affine_mul_sse2(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */
  __m128 l0, l1, l2, l3, r;

  l0 = _mm_load_ps(m1[0]);
  l1 = _mm_load_ps(m1[1]);
  l2 = _mm_load_ps(m1[2]);
  l3 = _mm_load_ps(m1[3]);

  r = _mm_load_ps(m2[0]);
  _mm_store_ps(dest[0],
               _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle1_ps1(r, 0), l0),
                                     _mm_mul_ps(_mm_shuffle1_ps1(r, 1), l1)),
                          _mm_mul_ps(_mm_shuffle1_ps1(r, 2), l2)));
  r = _mm_load_ps(m2[1]);
  _mm_store_ps(dest[1],
               _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle1_ps1(r, 0), l0),
                                     _mm_mul_ps(_mm_shuffle1_ps1(r, 1), l1)),
                          _mm_mul_ps(_mm_shuffle1_ps1(r, 2), l2)));
  r = _mm_load_ps(m2[2]);
  _mm_store_ps(dest[2],
               _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle1_ps1(r, 0), l0),
                                     _mm_mul_ps(_mm_shuffle1_ps1(r, 1), l1)),
                          _mm_mul_ps(_mm_shuffle1_ps1(r, 2), l2)));

  r = _mm_load_ps(m2[3]);
  _mm_store_ps(dest[3],
               _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle1_ps1(r, 0), l0),
                                     _mm_mul_ps(_mm_shuffle1_ps1(r, 1), l1)),
                          _mm_add_ps(_mm_mul_ps(_mm_shuffle1_ps1(r, 2), l2),
                                     _mm_mul_ps(_mm_shuffle1_ps1(r, 3), l3))));
}

#endif
#endif /* cglm_affine_mat_sse2_h */
