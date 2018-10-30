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

#include <immintrin.h>

CGLM_INLINE
void
glm_mat4_mul_avx(mat4 m1, mat4 m2, mat4 dest) {
  /* D = R * L (Column-Major) */

  __m256  y0, y1, y2, y3, y4, y5, y6, y7, y8, y9;
  __m256i yi0, yi1, yi2, yi3;

  y0  = glmm_load256(m2[0]); /* h g f e d c b a */
  y1  = glmm_load256(m2[2]); /* p o n m l k j i */

  y2  = glmm_load256(m1[0]); /* h g f e d c b a */
  y3  = glmm_load256(m1[2]); /* p o n m l k j i */

  /* 0x03: 0b00000011 */
  y4  = _mm256_permute2f128_ps(y2, y2, 0x03); /* d c b a h g f e */
  y5  = _mm256_permute2f128_ps(y3, y3, 0x03); /* l k j i p o n m */

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

  glmm_store256(dest[0],
                _mm256_add_ps(_mm256_add_ps(_mm256_mul_ps(y2, y6),
                                            _mm256_mul_ps(y3, y7)),
                              _mm256_add_ps(_mm256_mul_ps(y4, y8),
                                            _mm256_mul_ps(y5, y9))));

  /* n n n n i i i i */
  /* p p p p k k k k */
  /* m m m m j j j j */
  /* o o o o l l l l */
  y6 = _mm256_permutevar_ps(y1, yi0);
  y7 = _mm256_permutevar_ps(y1, yi1);
  y8 = _mm256_permutevar_ps(y1, yi2);
  y9 = _mm256_permutevar_ps(y1, yi3);

  glmm_store256(dest[2],
                _mm256_add_ps(_mm256_add_ps(_mm256_mul_ps(y2, y6),
                                            _mm256_mul_ps(y3, y7)),
                              _mm256_add_ps(_mm256_mul_ps(y4, y8),
                                            _mm256_mul_ps(y5, y9))));
}

CGLM_INLINE
void
glm_mat4_inv_avx(mat4 mat, mat4 dest) {
  __m256  y0, y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12, y13;
  __m256  yt0, yt1, yt2;
  __m256  t0, t1, t2;
  __m256  r1, r2;
  __m256  flpsign;
  __m256i yi1, yi2, yi3;

  y0  = glmm_load256(mat[0]); /* h g f e d c b a */
  y1  = glmm_load256(mat[2]); /* p o n m l k j i */

  y2  = _mm256_permute2f128_ps(y1, y1, 0x00); /* l k j i l k j i */
  y3  = _mm256_permute2f128_ps(y1, y1, 0x11); /* p o n m p o n m */
  y4  = _mm256_permute2f128_ps(y0, y0, 0x03); /* d c b a h g f e */
  y13 = _mm256_permute2f128_ps(y4, y4, 0x00); /* h g f e h g f e */

  yi1     = _mm256_set_epi32(0, 0, 0, 0, 0, 1, 1, 2);
  yi2     = _mm256_set_epi32(1, 1, 1, 2, 3, 2, 3, 3);
  flpsign = _mm256_set_ps(0.f, -0.f, 0.f, -0.f, -0.f, 0.f, -0.f, 0.f);

  /* i i i i i j j k */
  /* n n n o p o p p */
  /* m m m m m n n o */
  /* j j j k l k l l */
  /* e e e e e f f g */
  /* f f f g h g h h */
  y5  = _mm256_permutevar_ps(y2, yi1);
  y6  = _mm256_permutevar_ps(y3, yi2);
  y7  = _mm256_permutevar_ps(y3, yi1);
  y8  = _mm256_permutevar_ps(y2, yi2);
  y2  = _mm256_permutevar_ps(y13, yi1);
  y3  = _mm256_permutevar_ps(y13, yi2);

  yi1 = _mm256_set_epi32(2, 1, 0, 0, 2, 1, 0, 0);
  yi2 = _mm256_set_epi32(2, 1, 1, 0, 2, 1, 1, 0);
  yi3 = _mm256_set_epi32(3, 3, 2, 0, 3, 3, 2, 0);

  /*
   t0[0] = k * p - o * l;    t1[0] = g * p - o * h;    t2[0] = g * l - k * h;
   t0[1] = j * p - n * l;    t1[1] = f * p - n * h;    t2[1] = f * l - j * h;
   t0[2] = j * o - n * k;    t1[2] = f * o - n * g;    t2[2] = f * k - j * g;
   t0[3] = i * p - m * l;    t1[3] = e * p - m * h;    t2[3] = e * l - i * h;
   t0[4] = i * o - m * k;    t1[4] = e * o - m * g;    t2[4] = e * k - i * g;
   t0[5] = i * n - m * j;    t1[5] = e * n - m * f;    t2[5] = e * j - i * f;
   */
  yt0 = _mm256_sub_ps(_mm256_mul_ps(y5, y6), _mm256_mul_ps(y7, y8));
  yt1 = _mm256_sub_ps(_mm256_mul_ps(y2, y6), _mm256_mul_ps(y7, y3));
  yt2 = _mm256_sub_ps(_mm256_mul_ps(y2, y8), _mm256_mul_ps(y5, y3));

  /* t3 t2 t1 t0 t3 t2 t1 t0 */
  /* t5 t5 t5 t4 t5 t5 t5 t4 */
  y9  = _mm256_permute2f128_ps(yt0, yt0, 0x00);
  y10 = _mm256_permute2f128_ps(yt0, yt0, 0x11);
//
  /* t2 t1 t0 t0 t2 t1 t0 t0 */
  t0  = _mm256_permutevar_ps(y9, yi1);

  /* t4 t3 t3 t1 t4 t3 t3 t1 */
  y11 = _mm256_shuffle_ps(y9, y10, 0x4D);
  y12 = _mm256_permutevar_ps(y11, yi2);
  t1  = _mm256_permute2f128_ps(y12, y9, 0x00);

  /* t5 t5 t4 t2 t5 t5 t4 t2 */
  y11 = _mm256_shuffle_ps(y9, y10, 0x4A);
  y12 = _mm256_permutevar_ps(y11, yi3);
  t2  = _mm256_permute2f128_ps(y12, y12, 0x00);

  /* a a a b e e e f */
  /* b b c c f f g g */
  /* c d d d g h h h */
  y9  = _mm256_permute_ps(y4, 0x01);
  y10 = _mm256_permute_ps(y4, 0x5A);
  y11 = _mm256_permute_ps(y4, 0xBF);

  /*
   dest[0][0] =  f * t[0] - g * t[1] + h * t[2];
   dest[1][0] =-(e * t[0] - g * t[3] + h * t[4]);
   dest[2][0] =  e * t[1] - f * t[3] + h * t[5];
   dest[3][0] =-(e * t[2] - f * t[4] + g * t[5]);

   dest[0][1] =-(b * t[0] - c * t[1] + d * t[2]);
   dest[1][1] =  a * t[0] - c * t[3] + d * t[4];
   dest[2][1] =-(a * t[1] - b * t[3] + d * t[5]);
   dest[3][1] =  a * t[2] - b * t[4] + c * t[5];
   */
  r1 = _mm256_xor_ps(_mm256_add_ps(_mm256_sub_ps(_mm256_mul_ps(y9, t0),
                                                 _mm256_mul_ps(y10, t1)),
                                   _mm256_mul_ps(y11, t2)),
                     flpsign);

  /* d c b a d c b a */
  y2 = _mm256_permute2f128_ps(y0, y0, 0x0);

  /* a a a b a a a b */
  /* b b c c b b c c */
  /* c d d d c d d d */
  y3 = _mm256_permutevar_ps(y2, _mm256_set_epi32(0, 0, 0, 1, 0, 0, 0, 1));
  y4 = _mm256_permutevar_ps(y2, _mm256_set_epi32(1, 1, 2, 2, 1, 1, 2, 2));
  y5 = _mm256_permutevar_ps(y2, _mm256_set_epi32(2, 3, 3, 3, 2, 3, 3, 3));

  /* t2[3] t2[2] t2[1] t2[0] t1[3] t1[2] t1[1] t1[0] */
  /* t2[5] t2[5] t2[5] t2[4] t1[5] t1[5] t1[5] t1[4] */
  y6 = _mm256_permute2f128_ps(yt1, yt2, 0x20);
  y7 = _mm256_permute2f128_ps(yt1, yt2, 0x31);

  /* t2[2] t2[1] t2[0] t2[0] t1[2] t1[1] t1[0] t1[0] */
  t0 = _mm256_permutevar_ps(y6, yi1);

  /* t1[4] t1[3] t1[3] t1[1] t1[4] t1[3] t1[3] t1[1] */

  /* t1[4] t1[3] t1[3] t1[1] t1[4] t1[3] t1[3] t1[1] */
  y11 = _mm256_shuffle_ps(y6, y7, 0x4D);
  t1  = _mm256_permutevar_ps(y11, yi2);


  /* t2[5] t2[5] t2[4] t2[2] t1[5] t1[5] t1[4] t1[2] */
  y11 = _mm256_shuffle_ps(y6, y7, 0x4A);
  t2  = _mm256_permutevar_ps(y11, yi3);

  /*
   dest[0][2] =  b * t1[0] - c * t1[1] + d * t1[2];
   dest[1][2] =-(a * t1[0] - c * t1[3] + d * t1[4]);
   dest[2][2] =  a * t1[1] - b * t1[3] + d * t1[5];
   dest[3][2] =-(a * t1[2] - b * t1[4] + c * t1[5]);

   dest[0][3] =-(b * t2[0] - c * t2[1] + d * t2[2]);
   dest[1][3] =  a * t2[0] - c * t2[3] + d * t2[4];
   dest[2][3] =-(a * t2[1] - b * t2[3] + d * t2[5]);
   dest[3][3] =  a * t2[2] - b * t2[4] + c * t2[5];
   */
  r2 = _mm256_xor_ps(_mm256_add_ps(_mm256_sub_ps(_mm256_mul_ps(y3, t0),
                                                 _mm256_mul_ps(y4, t1)),
                                   _mm256_mul_ps(y5, t2)),
                     flpsign);

  /* determinant */

  y4 = _mm256_mul_ps(y0, r1);
  y4 = _mm256_permute2f128_ps(y4, y4, 0x30);
  y4 = _mm256_dp_ps(y0, r1, 0xff);

  y5 = _mm256_div_ps(_mm256_set1_ps(1.0f), y4);
  r1 = _mm256_mul_ps(r1, y5);
  r2 = _mm256_mul_ps(r2, y5);

  /* transpose */

  /* d c b a h g f e */
  /* l k j i p o n m */
  y0 = _mm256_permute2f128_ps(r1, r1, 0x03);
  y1 = _mm256_permute2f128_ps(r2, r2, 0x03);

  /* b a f e f e b a */
  /* j i n m n m j i */
  /* i m a e m i e a */
  /* j n b f n j f b */
  /* n j f b m i e a */
  y2 = _mm256_shuffle_ps(r1, y0, 0x44);
  y3 = _mm256_shuffle_ps(r2, y1, 0x44);
  y4 = _mm256_shuffle_ps(y2, y3, 0x88);
  y5 = _mm256_shuffle_ps(y2, y3, 0xDD);
  y6 = _mm256_permute2f128_ps(y4, y5, 0x20);

  /* d c h g h g d c */
  /* l k p o p o l k */
  /* k o c g o k g c */
  /* l p d h p l h d */
  /* p l h d o k g c */
  y2 = _mm256_shuffle_ps(r1, y0, 0xEE);
  y3 = _mm256_shuffle_ps(r2, y1, 0xEE);
  y4 = _mm256_shuffle_ps(y2, y3, 0x88);
  y5 = _mm256_shuffle_ps(y2, y3, 0xDD);
  y7 = _mm256_permute2f128_ps(y4, y5, 0x20);

  glmm_store256(dest[0], y6);
  glmm_store256(dest[2], y7);
}

CGLM_INLINE
void
glm_mat4_inv_fast_avx(mat4 mat, mat4 dest) {
  __m256  y0, y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12, y13;
  __m256  yt0, yt1, yt2;
  __m256  t0, t1, t2;
  __m256  r1, r2;
  __m256  flpsign;
  __m256i yi1, yi2, yi3;

  y0  = glmm_load256(mat[0]); /* h g f e d c b a */
  y1  = glmm_load256(mat[2]); /* p o n m l k j i */

  y2  = _mm256_permute2f128_ps(y1, y1, 0x00); /* l k j i l k j i */
  y3  = _mm256_permute2f128_ps(y1, y1, 0x11); /* p o n m p o n m */
  y4  = _mm256_permute2f128_ps(y0, y0, 0x03); /* d c b a h g f e */
  y13 = _mm256_permute2f128_ps(y4, y4, 0x00); /* h g f e h g f e */

  yi1     = _mm256_set_epi32(0, 0, 0, 0, 0, 1, 1, 2);
  yi2     = _mm256_set_epi32(1, 1, 1, 2, 3, 2, 3, 3);
  flpsign = _mm256_set_ps(0.f, -0.f, 0.f, -0.f, -0.f, 0.f, -0.f, 0.f);

  /* i i i i i j j k */
  /* n n n o p o p p */
  /* m m m m m n n o */
  /* j j j k l k l l */
  /* e e e e e f f g */
  /* f f f g h g h h */
  y5  = _mm256_permutevar_ps(y2, yi1);
  y6  = _mm256_permutevar_ps(y3, yi2);
  y7  = _mm256_permutevar_ps(y3, yi1);
  y8  = _mm256_permutevar_ps(y2, yi2);
  y2  = _mm256_permutevar_ps(y13, yi1);
  y3  = _mm256_permutevar_ps(y13, yi2);

  yi1 = _mm256_set_epi32(2, 1, 0, 0, 2, 1, 0, 0);
  yi2 = _mm256_set_epi32(2, 1, 1, 0, 2, 1, 1, 0);
  yi3 = _mm256_set_epi32(3, 3, 2, 0, 3, 3, 2, 0);

  /*
   t0[0] = k * p - o * l;    t1[0] = g * p - o * h;    t2[0] = g * l - k * h;
   t0[1] = j * p - n * l;    t1[1] = f * p - n * h;    t2[1] = f * l - j * h;
   t0[2] = j * o - n * k;    t1[2] = f * o - n * g;    t2[2] = f * k - j * g;
   t0[3] = i * p - m * l;    t1[3] = e * p - m * h;    t2[3] = e * l - i * h;
   t0[4] = i * o - m * k;    t1[4] = e * o - m * g;    t2[4] = e * k - i * g;
   t0[5] = i * n - m * j;    t1[5] = e * n - m * f;    t2[5] = e * j - i * f;
   */
  yt0 = _mm256_sub_ps(_mm256_mul_ps(y5, y6), _mm256_mul_ps(y7, y8));
  yt1 = _mm256_sub_ps(_mm256_mul_ps(y2, y6), _mm256_mul_ps(y7, y3));
  yt2 = _mm256_sub_ps(_mm256_mul_ps(y2, y8), _mm256_mul_ps(y5, y3));

  /* t3 t2 t1 t0 t3 t2 t1 t0 */
  /* t5 t5 t5 t4 t5 t5 t5 t4 */
  y9  = _mm256_permute2f128_ps(yt0, yt0, 0x00);
  y10 = _mm256_permute2f128_ps(yt0, yt0, 0x11);

  /* t2 t1 t0 t0 t2 t1 t0 t0 */
  t0  = _mm256_permutevar_ps(y9, yi1);

  /* t4 t3 t3 t1 t4 t3 t3 t1 */
  y11 = _mm256_shuffle_ps(y9, y10, 0x4D);
  y12 = _mm256_permutevar_ps(y11, yi2);
  t1  = _mm256_permute2f128_ps(y12, y9, 0x00);

  /* t5 t5 t4 t2 t5 t5 t4 t2 */
  y11 = _mm256_shuffle_ps(y9, y10, 0x4A);
  y12 = _mm256_permutevar_ps(y11, yi3);
  t2  = _mm256_permute2f128_ps(y12, y12, 0x00);

  /* a a a b e e e f */
  /* b b c c f f g g */
  /* c d d d g h h h */
  y9  = _mm256_permute_ps(y4, 0x01);
  y10 = _mm256_permute_ps(y4, 0x5A);
  y11 = _mm256_permute_ps(y4, 0xBF);

  /*
   dest[0][0] =  f * t[0] - g * t[1] + h * t[2];
   dest[1][0] =-(e * t[0] - g * t[3] + h * t[4]);
   dest[2][0] =  e * t[1] - f * t[3] + h * t[5];
   dest[3][0] =-(e * t[2] - f * t[4] + g * t[5]);

   dest[0][1] =-(b * t[0] - c * t[1] + d * t[2]);
   dest[1][1] =  a * t[0] - c * t[3] + d * t[4];
   dest[2][1] =-(a * t[1] - b * t[3] + d * t[5]);
   dest[3][1] =  a * t[2] - b * t[4] + c * t[5];
   */
  r1 = _mm256_xor_ps(_mm256_add_ps(_mm256_sub_ps(_mm256_mul_ps(y9, t0),
                                                 _mm256_mul_ps(y10, t1)),
                                   _mm256_mul_ps(y11, t2)),
                     flpsign);

  /* d c b a d c b a */
  y2 = _mm256_permute2f128_ps(y0, y0, 0x0);

  /* a a a b a a a b */
  /* b b c c b b c c */
  /* c d d d c d d d */
  y3 = _mm256_permutevar_ps(y2, _mm256_set_epi32(0, 0, 0, 1, 0, 0, 0, 1));
  y4 = _mm256_permutevar_ps(y2, _mm256_set_epi32(1, 1, 2, 2, 1, 1, 2, 2));
  y5 = _mm256_permutevar_ps(y2, _mm256_set_epi32(2, 3, 3, 3, 2, 3, 3, 3));

  /* t2[3] t2[2] t2[1] t2[0] t1[3] t1[2] t1[1] t1[0] */
  /* t2[5] t2[5] t2[5] t2[4] t1[5] t1[5] t1[5] t1[4] */
  y6 = _mm256_permute2f128_ps(yt1, yt2, 0x20);
  y7 = _mm256_permute2f128_ps(yt1, yt2, 0x31);

  /* t2[2] t2[1] t2[0] t2[0] t1[2] t1[1] t1[0] t1[0] */
  t0 = _mm256_permutevar_ps(y6, yi1);

  /* t1[4] t1[3] t1[3] t1[1] t1[4] t1[3] t1[3] t1[1] */

  /* t1[4] t1[3] t1[3] t1[1] t1[4] t1[3] t1[3] t1[1] */
  y11 = _mm256_shuffle_ps(y6, y7, 0x4D);
  t1  = _mm256_permutevar_ps(y11, yi2);


  /* t2[5] t2[5] t2[4] t2[2] t1[5] t1[5] t1[4] t1[2] */
  y11 = _mm256_shuffle_ps(y6, y7, 0x4A);
  t2  = _mm256_permutevar_ps(y11, yi3);

  /*
   dest[0][2] =  b * t1[0] - c * t1[1] + d * t1[2];
   dest[1][2] =-(a * t1[0] - c * t1[3] + d * t1[4]);
   dest[2][2] =  a * t1[1] - b * t1[3] + d * t1[5];
   dest[3][2] =-(a * t1[2] - b * t1[4] + c * t1[5]);

   dest[0][3] =-(b * t2[0] - c * t2[1] + d * t2[2]);
   dest[1][3] =  a * t2[0] - c * t2[3] + d * t2[4];
   dest[2][3] =-(a * t2[1] - b * t2[3] + d * t2[5]);
   dest[3][3] =  a * t2[2] - b * t2[4] + c * t2[5];
   */
  r2 = _mm256_xor_ps(_mm256_add_ps(_mm256_sub_ps(_mm256_mul_ps(y3, t0),
                                                 _mm256_mul_ps(y4, t1)),
                                   _mm256_mul_ps(y5, t2)),
                     flpsign);

  /* determinant */

  y4 = _mm256_mul_ps(y0, r1);
  y4 = _mm256_permute2f128_ps(y4, y4, 0x30);
  y4 = _mm256_dp_ps(y0, r1, 0xff);

  y5 = _mm256_rcp_ps(y4);
  r1 = _mm256_mul_ps(r1, y5);
  r2 = _mm256_mul_ps(r2, y5);

  /* transpose */

  /* d c b a h g f e */
  /* l k j i p o n m */
  y0 = _mm256_permute2f128_ps(r1, r1, 0x03);
  y1 = _mm256_permute2f128_ps(r2, r2, 0x03);

  /* b a f e f e b a */
  /* j i n m n m j i */
  /* i m a e m i e a */
  /* j n b f n j f b */
  /* n j f b m i e a */
  y2 = _mm256_shuffle_ps(r1, y0, 0x44);
  y3 = _mm256_shuffle_ps(r2, y1, 0x44);
  y4 = _mm256_shuffle_ps(y2, y3, 0x88);
  y5 = _mm256_shuffle_ps(y2, y3, 0xDD);
  y6 = _mm256_permute2f128_ps(y4, y5, 0x20);

  /* d c h g h g d c */
  /* l k p o p o l k */
  /* k o c g o k g c */
  /* l p d h p l h d */
  /* p l h d o k g c */
  y2 = _mm256_shuffle_ps(r1, y0, 0xEE);
  y3 = _mm256_shuffle_ps(r2, y1, 0xEE);
  y4 = _mm256_shuffle_ps(y2, y3, 0x88);
  y5 = _mm256_shuffle_ps(y2, y3, 0xDD);
  y7 = _mm256_permute2f128_ps(y4, y5, 0x20);

  glmm_store256(dest[0], y6);
  glmm_store256(dest[2], y7);
}

#endif
#endif /* cglm_mat_simd_avx_h */
