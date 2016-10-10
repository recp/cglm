/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_affine_mat_avx_h
#define cglm_affine_mat_avx_h
#ifdef __AVX__

#include "cglm-intrin.h"
#include <immintrin.h>

CGLM_INLINE
void
glm_affine_mul_avx(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */

  __m256 y0, y1, y2, y3, y4, y5, y6, y7, y8, y9;

  y0 = _mm256_load_ps(m2[0]); /* h g f e d c b a */
  y1 = _mm256_load_ps(m2[2]); /* p o n m l k j i */

  y2 = _mm256_load_ps(m1[0]); /* h g f e d c b a */
  y3 = _mm256_load_ps(m1[2]); /* p o n m l k j i */

  y4 = _mm256_permute2f128_ps(y2, y2, 0b00000011); /* d c b a h g f e */
  y5 = _mm256_permute2f128_ps(y3, y3, 0b00000000); /* l k j i l k j i */

  /* f f f f a a a a */
  /* g g g g c c c c */
  /* e e e e b b b b */
  y7 = _mm256_permute_ps(y0, 0b10101010);
  y6 = _mm256_permutevar_ps(y0, _mm256_set_epi32(1, 1, 1, 1, 0, 0, 0, 0));
  y8 = _mm256_permutevar_ps(y0, _mm256_set_epi32(0, 0, 0, 0, 1, 1, 1, 1));

  _mm256_store_ps(dest[0],
                  _mm256_add_ps(_mm256_add_ps(_mm256_mul_ps(y2, y6),
                                              _mm256_mul_ps(y4, y8)),
                                _mm256_mul_ps(y5, y7)));


  /* n n n n i i i i */
  /* p p p p k k k k */
  /* m m m m j j j j */
  /* o o o o l l l l */
  y6 = _mm256_permutevar_ps(y1, _mm256_set_epi32(1, 1, 1, 1, 0, 0, 0, 0));
  y7 = _mm256_permutevar_ps(y1, _mm256_set_epi32(3, 3, 3, 3, 2, 2, 2, 2));
  y8 = _mm256_permutevar_ps(y1, _mm256_set_epi32(0, 0, 0, 0, 1, 1, 1, 1));
  y9 = _mm256_permutevar_ps(y1, _mm256_set_epi32(2, 2, 2, 2, 3, 3, 3, 3));

  _mm256_store_ps(dest[2],
                  _mm256_add_ps(_mm256_add_ps(_mm256_mul_ps(y2, y6),
                                              _mm256_mul_ps(y3, y7)),
                                _mm256_add_ps(_mm256_mul_ps(y4, y8),
                                              _mm256_mul_ps(y5, y9))));
}

#endif
#endif /* cglm_affine_mat_avx_h */
