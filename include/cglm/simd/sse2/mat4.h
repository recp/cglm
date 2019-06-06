/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat_sse_h
#define cglm_mat_sse_h
#if defined( __SSE__ ) || defined( __SSE2__ )

#include "../../common.h"
#include "../intrin.h"

#define glm_mat4_inv_precise_sse2(mat, dest) glm_mat4_inv_sse2(mat, dest)

CGLM_INLINE
void
glm_mat4_scale_sse2(mat4 m, float s) {
  __m128 x0;
  x0 = _mm_set1_ps(s);

  glmm_store(m[0], _mm_mul_ps(glmm_load(m[0]), x0));
  glmm_store(m[1], _mm_mul_ps(glmm_load(m[1]), x0));
  glmm_store(m[2], _mm_mul_ps(glmm_load(m[2]), x0));
  glmm_store(m[3], _mm_mul_ps(glmm_load(m[3]), x0));
}

CGLM_INLINE
void
glm_mat4_transp_sse2(mat4 m, mat4 dest) {
  __m128 r0, r1, r2, r3;

  r0 = glmm_load(m[0]);
  r1 = glmm_load(m[1]);
  r2 = glmm_load(m[2]);
  r3 = glmm_load(m[3]);

  _MM_TRANSPOSE4_PS(r0, r1, r2, r3);

  glmm_store(dest[0], r0);
  glmm_store(dest[1], r1);
  glmm_store(dest[2], r2);
  glmm_store(dest[3], r3);
}

CGLM_INLINE
void
glm_mat4_mul_sse2(mat4 m1, mat4 m2, mat4 dest) {
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
                        _mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 2), l2),
                                   _mm_mul_ps(glmm_shuff1x(r, 3), l3))));
  r = glmm_load(m2[1]);
  glmm_store(dest[1],
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 0), l0),
                                   _mm_mul_ps(glmm_shuff1x(r, 1), l1)),
                        _mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 2), l2),
                                   _mm_mul_ps(glmm_shuff1x(r, 3), l3))));
  r = glmm_load(m2[2]);
  glmm_store(dest[2],
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 0), l0),
                                   _mm_mul_ps(glmm_shuff1x(r, 1), l1)),
                        _mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 2), l2),
                                   _mm_mul_ps(glmm_shuff1x(r, 3), l3))));

  r = glmm_load(m2[3]);
  glmm_store(dest[3],
             _mm_add_ps(_mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 0), l0),
                                   _mm_mul_ps(glmm_shuff1x(r, 1), l1)),
                        _mm_add_ps(_mm_mul_ps(glmm_shuff1x(r, 2), l2),
                                   _mm_mul_ps(glmm_shuff1x(r, 3), l3))));
}

CGLM_INLINE
void
glm_mat4_mulv_sse2(mat4 m, vec4 v, vec4 dest) {
  __m128 x0, x1, x2;

  x0 = glmm_load(v);
  x1 = _mm_add_ps(_mm_mul_ps(glmm_load(m[0]), glmm_shuff1x(x0, 0)),
                  _mm_mul_ps(glmm_load(m[1]), glmm_shuff1x(x0, 1)));

  x2 = _mm_add_ps(_mm_mul_ps(glmm_load(m[2]), glmm_shuff1x(x0, 2)),
                  _mm_mul_ps(glmm_load(m[3]), glmm_shuff1x(x0, 3)));

  glmm_store(dest, _mm_add_ps(x1, x2));
}

CGLM_INLINE
float
glm_mat4_det_sse2(mat4 mat) {
  __m128 r0, r1, r2, r3, x0, x1, x2;

  /* 127 <- 0, [square] det(A) = det(At) */
  r0 = glmm_load(mat[0]); /* d c b a */
  r1 = glmm_load(mat[1]); /* h g f e */
  r2 = glmm_load(mat[2]); /* l k j i */
  r3 = glmm_load(mat[3]); /* p o n m */

  /*
   t[1] = j * p - n * l;
   t[2] = j * o - n * k;
   t[3] = i * p - m * l;
   t[4] = i * o - m * k;
   */
  x0 = _mm_sub_ps(_mm_mul_ps(glmm_shuff1(r2, 0, 0, 1, 1),
                             glmm_shuff1(r3, 2, 3, 2, 3)),
                  _mm_mul_ps(glmm_shuff1(r3, 0, 0, 1, 1),
                             glmm_shuff1(r2, 2, 3, 2, 3)));
  /*
   t[0] = k * p - o * l;
   t[0] = k * p - o * l;
   t[5] = i * n - m * j;
   t[5] = i * n - m * j;
   */
  x1 = _mm_sub_ps(_mm_mul_ps(glmm_shuff1(r2, 0, 0, 2, 2),
                             glmm_shuff1(r3, 1, 1, 3, 3)),
                  _mm_mul_ps(glmm_shuff1(r3, 0, 0, 2, 2),
                             glmm_shuff1(r2, 1, 1, 3, 3)));

  /*
     a * (f * t[0] - g * t[1] + h * t[2])
   - b * (e * t[0] - g * t[3] + h * t[4])
   + c * (e * t[1] - f * t[3] + h * t[5])
   - d * (e * t[2] - f * t[4] + g * t[5])
   */
  x2 = _mm_sub_ps(_mm_mul_ps(glmm_shuff1(r1, 0, 0, 0, 1),
                             _mm_shuffle_ps(x1, x0, _MM_SHUFFLE(1, 0, 0, 0))),
                  _mm_mul_ps(glmm_shuff1(r1, 1, 1, 2, 2),
                             glmm_shuff1(x0, 3, 2, 2, 0)));

  x2 = _mm_add_ps(x2,
                  _mm_mul_ps(glmm_shuff1(r1, 2, 3, 3, 3),
                             _mm_shuffle_ps(x0, x1, _MM_SHUFFLE(2, 2, 3, 1))));
  x2 = _mm_xor_ps(x2, _mm_set_ps(-0.f, 0.f, -0.f, 0.f));

  x0 = _mm_mul_ps(r0, x2);
  x0 = _mm_add_ps(x0, glmm_shuff1(x0, 0, 1, 2, 3));
  x0 = _mm_add_ps(x0, glmm_shuff1(x0, 1, 3, 3, 1));

  return _mm_cvtss_f32(x0);
}

CGLM_INLINE
void
glm_mat4_inv_fast_sse2(mat4 mat, mat4 dest) {
  __m128 r0, r1, r2, r3,
         v0, v1, v2, v3,
         t0, t1, t2, t3, t4, t5,
         x0, x1, x2, x3, x4, x5, x6, x7;

  /* 127 <- 0 */
  r0 = glmm_load(mat[0]); /* d c b a */
  r1 = glmm_load(mat[1]); /* h g f e */
  r2 = glmm_load(mat[2]); /* l k j i */
  r3 = glmm_load(mat[3]); /* p o n m */

  x0 = _mm_shuffle_ps(r2, r3, _MM_SHUFFLE(3, 2, 3, 2));  /* p o l k */
  x1 = glmm_shuff1(x0, 1, 3, 3, 3);                      /* l p p p */
  x2 = glmm_shuff1(x0, 0, 2, 2, 2);                      /* k o o o */
  x0 = _mm_shuffle_ps(r2, r1, _MM_SHUFFLE(3, 3, 3, 3));  /* h h l l */
  x3 = _mm_shuffle_ps(r2, r1, _MM_SHUFFLE(2, 2, 2, 2));  /* g g k k */

  /* t1[0] = k * p - o * l;
     t1[0] = k * p - o * l;
     t2[0] = g * p - o * h;
     t3[0] = g * l - k * h; */
  t0 = _mm_sub_ps(_mm_mul_ps(x3, x1), _mm_mul_ps(x2, x0));

  x4 = _mm_shuffle_ps(r2, r3, _MM_SHUFFLE(2, 1, 2, 1)); /* o n k j */
  x4 = glmm_shuff1(x4, 0, 2, 2, 2);                     /* j n n n */
  x5 = _mm_shuffle_ps(r2, r1, _MM_SHUFFLE(1, 1, 1, 1)); /* f f j j */

  /* t1[1] = j * p - n * l;
     t1[1] = j * p - n * l;
     t2[1] = f * p - n * h;
     t3[1] = f * l - j * h; */
  t1 = _mm_sub_ps(_mm_mul_ps(x5, x1), _mm_mul_ps(x4, x0));

  /* t1[2] = j * o - n * k
     t1[2] = j * o - n * k;
     t2[2] = f * o - n * g;
     t3[2] = f * k - j * g; */
  t2 = _mm_sub_ps(_mm_mul_ps(x5, x2), _mm_mul_ps(x4, x3));

  x6 = _mm_shuffle_ps(r2, r1, _MM_SHUFFLE(0, 0, 0, 0)); /* e e i i */
  x7 = glmm_shuff2(r3, r2, 0, 0, 0, 0, 2, 0, 0, 0);     /* i m m m */

  /* t1[3] = i * p - m * l;
     t1[3] = i * p - m * l;
     t2[3] = e * p - m * h;
     t3[3] = e * l - i * h; */
  t3 = _mm_sub_ps(_mm_mul_ps(x6, x1), _mm_mul_ps(x7, x0));

  /* t1[4] = i * o - m * k;
     t1[4] = i * o - m * k;
     t2[4] = e * o - m * g;
     t3[4] = e * k - i * g; */
  t4 = _mm_sub_ps(_mm_mul_ps(x6, x2), _mm_mul_ps(x7, x3));

  /* t1[5] = i * n - m * j;
     t1[5] = i * n - m * j;
     t2[5] = e * n - m * f;
     t3[5] = e * j - i * f; */
  t5 = _mm_sub_ps(_mm_mul_ps(x6, x4), _mm_mul_ps(x7, x5));

  x0 = glmm_shuff2(r1, r0, 0, 0, 0, 0, 2, 2, 2, 0); /* a a a e */
  x1 = glmm_shuff2(r1, r0, 1, 1, 1, 1, 2, 2, 2, 0); /* b b b f */
  x2 = glmm_shuff2(r1, r0, 2, 2, 2, 2, 2, 2, 2, 0); /* c c c g */
  x3 = glmm_shuff2(r1, r0, 3, 3, 3, 3, 2, 2, 2, 0); /* d d d h */

  /*
   dest[0][0] =  f * t1[0] - g * t1[1] + h * t1[2];
   dest[0][1] =-(b * t1[0] - c * t1[1] + d * t1[2]);
   dest[0][2] =  b * t2[0] - c * t2[1] + d * t2[2];
   dest[0][3] =-(b * t3[0] - c * t3[1] + d * t3[2]); */
  v0 = _mm_add_ps(_mm_mul_ps(x3, t2),
                  _mm_sub_ps(_mm_mul_ps(x1, t0),
                             _mm_mul_ps(x2, t1)));
  v0 = _mm_xor_ps(v0, _mm_set_ps(-0.f, 0.f, -0.f, 0.f));

  /*
   dest[1][0] =-(e * t1[0] - g * t1[3] + h * t1[4]);
   dest[1][1] =  a * t1[0] - c * t1[3] + d * t1[4];
   dest[1][2] =-(a * t2[0] - c * t2[3] + d * t2[4]);
   dest[1][3] =  a * t3[0] - c * t3[3] + d * t3[4]; */
  v1 = _mm_add_ps(_mm_mul_ps(x3, t4),
                  _mm_sub_ps(_mm_mul_ps(x0, t0),
                             _mm_mul_ps(x2, t3)));
  v1 = _mm_xor_ps(v1, _mm_set_ps(0.f, -0.f, 0.f, -0.f));

  /*
   dest[2][0] =  e * t1[1] - f * t1[3] + h * t1[5];
   dest[2][1] =-(a * t1[1] - b * t1[3] + d * t1[5]);
   dest[2][2] =  a * t2[1] - b * t2[3] + d * t2[5];
   dest[2][3] =-(a * t3[1] - b * t3[3] + d * t3[5]);*/
  v2 = _mm_add_ps(_mm_mul_ps(x3, t5),
                  _mm_sub_ps(_mm_mul_ps(x0, t1),
                             _mm_mul_ps(x1, t3)));
  v2 = _mm_xor_ps(v2, _mm_set_ps(-0.f, 0.f, -0.f, 0.f));

  /*
   dest[3][0] =-(e * t1[2] - f * t1[4] + g * t1[5]);
   dest[3][1] =  a * t1[2] - b * t1[4] + c * t1[5];
   dest[3][2] =-(a * t2[2] - b * t2[4] + c * t2[5]);
   dest[3][3] =  a * t3[2] - b * t3[4] + c * t3[5]; */
  v3 = _mm_add_ps(_mm_mul_ps(x2, t5),
                  _mm_sub_ps(_mm_mul_ps(x0, t2),
                             _mm_mul_ps(x1, t4)));
  v3 = _mm_xor_ps(v3, _mm_set_ps(0.f, -0.f, 0.f, -0.f));

  /* determinant */
  x0 = _mm_shuffle_ps(v0, v1, _MM_SHUFFLE(0, 0, 0, 0));
  x1 = _mm_shuffle_ps(v2, v3, _MM_SHUFFLE(0, 0, 0, 0));
  x0 = _mm_shuffle_ps(x0, x1, _MM_SHUFFLE(2, 0, 2, 0));

  x0 = _mm_mul_ps(x0, r0);
  x0 = _mm_add_ps(x0, glmm_shuff1(x0, 0, 1, 2, 3));
  x0 = _mm_add_ps(x0, glmm_shuff1(x0, 1, 0, 0, 1));
  x0 = _mm_rcp_ps(x0);

  glmm_store(dest[0], _mm_mul_ps(v0, x0));
  glmm_store(dest[1], _mm_mul_ps(v1, x0));
  glmm_store(dest[2], _mm_mul_ps(v2, x0));
  glmm_store(dest[3], _mm_mul_ps(v3, x0));
}

CGLM_INLINE
void
glm_mat4_inv_sse2(mat4 mat, mat4 dest) {
  __m128 r0, r1, r2, r3,
         v0, v1, v2, v3,
         t0, t1, t2, t3, t4, t5,
         x0, x1, x2, x3, x4, x5, x6, x7;

  /* 127 <- 0 */
  r0 = glmm_load(mat[0]); /* d c b a */
  r1 = glmm_load(mat[1]); /* h g f e */
  r2 = glmm_load(mat[2]); /* l k j i */
  r3 = glmm_load(mat[3]); /* p o n m */

  x0 = _mm_shuffle_ps(r2, r3, _MM_SHUFFLE(3, 2, 3, 2));  /* p o l k */
  x1 = glmm_shuff1(x0, 1, 3, 3, 3);                      /* l p p p */
  x2 = glmm_shuff1(x0, 0, 2, 2, 2);                      /* k o o o */
  x0 = _mm_shuffle_ps(r2, r1, _MM_SHUFFLE(3, 3, 3, 3));  /* h h l l */
  x3 = _mm_shuffle_ps(r2, r1, _MM_SHUFFLE(2, 2, 2, 2));  /* g g k k */

  /* t1[0] = k * p - o * l;
     t1[0] = k * p - o * l;
     t2[0] = g * p - o * h;
     t3[0] = g * l - k * h; */
  t0 = _mm_sub_ps(_mm_mul_ps(x3, x1), _mm_mul_ps(x2, x0));

  x4 = _mm_shuffle_ps(r2, r3, _MM_SHUFFLE(2, 1, 2, 1)); /* o n k j */
  x4 = glmm_shuff1(x4, 0, 2, 2, 2);                     /* j n n n */
  x5 = _mm_shuffle_ps(r2, r1, _MM_SHUFFLE(1, 1, 1, 1)); /* f f j j */

  /* t1[1] = j * p - n * l;
     t1[1] = j * p - n * l;
     t2[1] = f * p - n * h;
     t3[1] = f * l - j * h; */
  t1 = _mm_sub_ps(_mm_mul_ps(x5, x1), _mm_mul_ps(x4, x0));

  /* t1[2] = j * o - n * k
     t1[2] = j * o - n * k;
     t2[2] = f * o - n * g;
     t3[2] = f * k - j * g; */
  t2 = _mm_sub_ps(_mm_mul_ps(x5, x2), _mm_mul_ps(x4, x3));

  x6 = _mm_shuffle_ps(r2, r1, _MM_SHUFFLE(0, 0, 0, 0)); /* e e i i */
  x7 = glmm_shuff2(r3, r2, 0, 0, 0, 0, 2, 0, 0, 0);     /* i m m m */

  /* t1[3] = i * p - m * l;
     t1[3] = i * p - m * l;
     t2[3] = e * p - m * h;
     t3[3] = e * l - i * h; */
  t3 = _mm_sub_ps(_mm_mul_ps(x6, x1), _mm_mul_ps(x7, x0));

  /* t1[4] = i * o - m * k;
     t1[4] = i * o - m * k;
     t2[4] = e * o - m * g;
     t3[4] = e * k - i * g; */
  t4 = _mm_sub_ps(_mm_mul_ps(x6, x2), _mm_mul_ps(x7, x3));

  /* t1[5] = i * n - m * j;
     t1[5] = i * n - m * j;
     t2[5] = e * n - m * f;
     t3[5] = e * j - i * f; */
  t5 = _mm_sub_ps(_mm_mul_ps(x6, x4), _mm_mul_ps(x7, x5));

  x0 = glmm_shuff2(r1, r0, 0, 0, 0, 0, 2, 2, 2, 0); /* a a a e */
  x1 = glmm_shuff2(r1, r0, 1, 1, 1, 1, 2, 2, 2, 0); /* b b b f */
  x2 = glmm_shuff2(r1, r0, 2, 2, 2, 2, 2, 2, 2, 0); /* c c c g */
  x3 = glmm_shuff2(r1, r0, 3, 3, 3, 3, 2, 2, 2, 0); /* d d d h */

  /*
   dest[0][0] =  f * t1[0] - g * t1[1] + h * t1[2];
   dest[0][1] =-(b * t1[0] - c * t1[1] + d * t1[2]);
   dest[0][2] =  b * t2[0] - c * t2[1] + d * t2[2];
   dest[0][3] =-(b * t3[0] - c * t3[1] + d * t3[2]); */
  v0 = _mm_add_ps(_mm_mul_ps(x3, t2),
                  _mm_sub_ps(_mm_mul_ps(x1, t0),
                             _mm_mul_ps(x2, t1)));
  v0 = _mm_xor_ps(v0, _mm_set_ps(-0.f, 0.f, -0.f, 0.f));

  /*
   dest[1][0] =-(e * t1[0] - g * t1[3] + h * t1[4]);
   dest[1][1] =  a * t1[0] - c * t1[3] + d * t1[4];
   dest[1][2] =-(a * t2[0] - c * t2[3] + d * t2[4]);
   dest[1][3] =  a * t3[0] - c * t3[3] + d * t3[4]; */
  v1 = _mm_add_ps(_mm_mul_ps(x3, t4),
                  _mm_sub_ps(_mm_mul_ps(x0, t0),
                             _mm_mul_ps(x2, t3)));
  v1 = _mm_xor_ps(v1, _mm_set_ps(0.f, -0.f, 0.f, -0.f));

  /*
   dest[2][0] =  e * t1[1] - f * t1[3] + h * t1[5];
   dest[2][1] =-(a * t1[1] - b * t1[3] + d * t1[5]);
   dest[2][2] =  a * t2[1] - b * t2[3] + d * t2[5];
   dest[2][3] =-(a * t3[1] - b * t3[3] + d * t3[5]);*/
  v2 = _mm_add_ps(_mm_mul_ps(x3, t5),
                  _mm_sub_ps(_mm_mul_ps(x0, t1),
                             _mm_mul_ps(x1, t3)));
  v2 = _mm_xor_ps(v2, _mm_set_ps(-0.f, 0.f, -0.f, 0.f));

  /*
   dest[3][0] =-(e * t1[2] - f * t1[4] + g * t1[5]);
   dest[3][1] =  a * t1[2] - b * t1[4] + c * t1[5];
   dest[3][2] =-(a * t2[2] - b * t2[4] + c * t2[5]);
   dest[3][3] =  a * t3[2] - b * t3[4] + c * t3[5]; */
  v3 = _mm_add_ps(_mm_mul_ps(x2, t5),
                  _mm_sub_ps(_mm_mul_ps(x0, t2),
                             _mm_mul_ps(x1, t4)));
  v3 = _mm_xor_ps(v3, _mm_set_ps(0.f, -0.f, 0.f, -0.f));

  /* determinant */
  x0 = _mm_shuffle_ps(v0, v1, _MM_SHUFFLE(0, 0, 0, 0));
  x1 = _mm_shuffle_ps(v2, v3, _MM_SHUFFLE(0, 0, 0, 0));
  x0 = _mm_shuffle_ps(x0, x1, _MM_SHUFFLE(2, 0, 2, 0));

  x0 = _mm_mul_ps(x0, r0);
  x0 = _mm_add_ps(x0, glmm_shuff1(x0, 0, 1, 2, 3));
  x0 = _mm_add_ps(x0, glmm_shuff1(x0, 1, 0, 0, 1));
  x0 = _mm_div_ps(_mm_set1_ps(1.0f), x0);

  glmm_store(dest[0], _mm_mul_ps(v0, x0));
  glmm_store(dest[1], _mm_mul_ps(v1, x0));
  glmm_store(dest[2], _mm_mul_ps(v2, x0));
  glmm_store(dest[3], _mm_mul_ps(v3, x0));
}

#endif
#endif /* cglm_mat_sse_h */
