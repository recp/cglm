/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat_simd_avx_h
#define cglm_mat_simd_avx_h
#ifdef __AVX__

#include "../../common.h"
#include "../intrin.h"

CGLM_INLINE
void
glm_mat4_scale_avx(mat4 m, float s) {
  __m256 y0, y1, y2, y3, y4;

  y0 = glmm_load256(m[0]);            /* h g f e d c b a */
  y1 = glmm_load256(m[2]);            /* p o n m l k j i */

  y2 = _mm256_broadcast_ss(&s);

  y3 = _mm256_mul_ps(y0, y2);
  y4 = _mm256_mul_ps(y1, y2);

  glmm_store256(m[0], y3);
  glmm_store256(m[2], y4);
}

/* TODO: this must be tested and compared to SSE version, may be slower!!! */
CGLM_INLINE
void
glm_mat4_transp_avx(mat4 m, mat4 dest) {
  __m256 y0, y1, y2, y3;

  y0 = glmm_load256(m[0]);                   /* h g f e d c b a */
  y1 = glmm_load256(m[2]);                   /* p o n m l k j i */

  y2 = _mm256_unpacklo_ps(y0, y1);           /* n f m e j b i a */
  y3 = _mm256_unpackhi_ps(y0, y1);           /* p h o g l d k c */
  
  y0 = _mm256_permute2f128_ps(y2, y3, 0x20); /* l d k c j b i a */
  y1 = _mm256_permute2f128_ps(y2, y3, 0x31); /* p h o g n f m e */

  y2 = _mm256_unpacklo_ps(y0, y1);           /* o k g c m i e a */
  y3 = _mm256_unpackhi_ps(y0, y1);           /* p l h d n j f b */

  y0 = _mm256_permute2f128_ps(y2, y3, 0x20); /* n j f b m i e a */
  y1 = _mm256_permute2f128_ps(y2, y3, 0x31); /* p l h d o k g c */

  glmm_store256(dest[0], y0);
  glmm_store256(dest[2], y1);
}

CGLM_INLINE
void
glm_mat4_mul_avx(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */

  __m256  y0, y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12, y13;
  __m256i yi0, yi1, yi2, yi3;

  y0 = glmm_load256(m2[0]); /* h g f e d c b a */
  y1 = glmm_load256(m2[2]); /* p o n m l k j i */

  y2 = glmm_load256(m1[0]); /* h g f e d c b a */
  y3 = glmm_load256(m1[2]); /* p o n m l k j i */

  /* 0x03: 0b00000011 */
  y4 = _mm256_permute2f128_ps(y2, y2, 0x03); /* d c b a h g f e */
  y5 = _mm256_permute2f128_ps(y3, y3, 0x03); /* l k j i p o n m */

  yi0 = _mm256_set_epi32(1, 1, 1, 1, 0, 0, 0, 0);
  yi1 = _mm256_set_epi32(3, 3, 3, 3, 2, 2, 2, 2);
  yi2 = _mm256_set_epi32(0, 0, 0, 0, 1, 1, 1, 1);
  yi3 = _mm256_set_epi32(2, 2, 2, 2, 3, 3, 3, 3);
  
  /* f f f f a a a a */
  /* h h h h c c c c */
  /* e e e e b b b b */
  /* g g g g d d d d */
  y6 = _mm256_permutevar_ps(y0, yi0);
  y7 = _mm256_permutevar_ps(y0, yi1);
  y8 = _mm256_permutevar_ps(y0, yi2);
  y9 = _mm256_permutevar_ps(y0, yi3);

  /* n n n n i i i i */
  /* p p p p k k k k */
  /* m m m m j j j j */
  /* o o o o l l l l */
  y10 = _mm256_permutevar_ps(y1, yi0);
  y11 = _mm256_permutevar_ps(y1, yi1);
  y12 = _mm256_permutevar_ps(y1, yi2);
  y13 = _mm256_permutevar_ps(y1, yi3);

  y0 = _mm256_mul_ps(y2, y6);
  y1 = _mm256_mul_ps(y2, y10);

  y0 = glmm256_fmadd(y3, y7, y0);
  y1 = glmm256_fmadd(y3, y11, y1);

  y0 = glmm256_fmadd(y4, y8, y0);
  y1 = glmm256_fmadd(y4, y12, y1);

  y0 = glmm256_fmadd(y5, y9, y0);
  y1 = glmm256_fmadd(y5, y13, y1);

  glmm_store256(dest[0], y0);
  glmm_store256(dest[2], y1);
}

#endif
#endif /* cglm_mat_simd_avx_h */
