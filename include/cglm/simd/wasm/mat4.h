/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat_wasm_h
#define cglm_mat_wasm_h
#if defined(__wasm__) && defined(__wasm_simd128__)

#include "../../common.h"
#include "../intrin.h"

#define glm_mat4_inv_precise_wasm(mat, dest) glm_mat4_inv_wasm(mat, dest)

CGLM_INLINE
void
glm_mat4_scale_wasm(mat4 m, float s) {
  glmm_128 x0;
  x0 = wasm_f32x4_splat(s);

  glmm_store(m[0], wasm_f32x4_mul(glmm_load(m[0]), x0));
  glmm_store(m[1], wasm_f32x4_mul(glmm_load(m[1]), x0));
  glmm_store(m[2], wasm_f32x4_mul(glmm_load(m[2]), x0));
  glmm_store(m[3], wasm_f32x4_mul(glmm_load(m[3]), x0));
}

CGLM_INLINE
void
glm_mat4_transp_wasm(mat4 m, mat4 dest) {
  glmm_128 r0, r1, r2, r3, tmp0, tmp1, tmp2, tmp3;

  r0 = glmm_load(m[0]);
  r1 = glmm_load(m[1]);
  r2 = glmm_load(m[2]);
  r3 = glmm_load(m[3]);

  /* _MM_TRANSPOSE4_PS(r0, r1, r2, r3); */
  tmp0 = wasm_i32x4_shuffle(r0, r1, 0, 4, 1, 5);
  tmp1 = wasm_i32x4_shuffle(r0, r1, 2, 6, 3, 7);
  tmp2 = wasm_i32x4_shuffle(r2, r3, 0, 4, 1, 5);
  tmp3 = wasm_i32x4_shuffle(r2, r3, 2, 6, 3, 7);
  /* r0 = _mm_movelh_ps(tmp0, tmp2); */
  r0 = wasm_i32x4_shuffle(tmp0, tmp2, 0, 1, 4, 5);
  /* r1 = _mm_movehl_ps(tmp2, tmp0); */
  r1 = wasm_i32x4_shuffle(tmp2, tmp0, 6, 7, 2, 3);
  /* r2 = _mm_movelh_ps(tmp1, tmp3); */
  r2 = wasm_i32x4_shuffle(tmp1, tmp3, 0, 1, 4, 5);
  /* r3 = _mm_movehl_ps(tmp3, tmp1); */
  r3 = wasm_i32x4_shuffle(tmp3, tmp1, 6, 7, 2, 3);

  glmm_store(dest[0], r0);
  glmm_store(dest[1], r1);
  glmm_store(dest[2], r2);
  glmm_store(dest[3], r3);
}

CGLM_INLINE
void
glm_mat4_mul_wasm(mat4 m1, mat4 m2, mat4 dest) {
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
  v0 = glmm_fmadd(glmm_splat_w(r0), l, v0);
  v1 = glmm_fmadd(glmm_splat_w(r1), l, v1);
  v2 = glmm_fmadd(glmm_splat_w(r2), l, v2);
  v3 = glmm_fmadd(glmm_splat_w(r3), l, v3);

  glmm_store(dest[0], v0);
  glmm_store(dest[1], v1);
  glmm_store(dest[2], v2);
  glmm_store(dest[3], v3);
}

CGLM_INLINE
void
glm_mat4_mulv_wasm(mat4 m, vec4 v, vec4 dest) {
  glmm_128 x0, x1, m0, m1, m2, m3, v0, v1, v2, v3;

  m0 = glmm_load(m[0]);
  m1 = glmm_load(m[1]);
  m2 = glmm_load(m[2]);
  m3 = glmm_load(m[3]);

  x0 = glmm_load(v);
  v0 = glmm_splat_x(x0);
  v1 = glmm_splat_y(x0);
  v2 = glmm_splat_z(x0);
  v3 = glmm_splat_w(x0);

  x1 = wasm_f32x4_mul(m3, v3);
  x1 = glmm_fmadd(m2, v2, x1);
  x1 = glmm_fmadd(m1, v1, x1);
  x1 = glmm_fmadd(m0, v0, x1);

  glmm_store(dest, x1);
}

CGLM_INLINE
float
glm_mat4_det_wasm(mat4 mat) {
  glmm_128 r0, r1, r2, r3, x0, x1, x2;

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
  x0 = glmm_fnmadd(glmm_shuff1(r3, 0, 0, 1, 1), glmm_shuff1(r2, 2, 3, 2, 3),
                   wasm_f32x4_mul(glmm_shuff1(r2, 0, 0, 1, 1),
                              glmm_shuff1(r3, 2, 3, 2, 3)));
  /*
   t[0] = k * p - o * l;
   t[0] = k * p - o * l;
   t[5] = i * n - m * j;
   t[5] = i * n - m * j;
   */
  x1 = glmm_fnmadd(glmm_shuff1(r3, 0, 0, 2, 2), glmm_shuff1(r2, 1, 1, 3, 3),
                   wasm_f32x4_mul(glmm_shuff1(r2, 0, 0, 2, 2),
                              glmm_shuff1(r3, 1, 1, 3, 3)));

  /*
     a * (f * t[0] - g * t[1] + h * t[2])
   - b * (e * t[0] - g * t[3] + h * t[4])
   + c * (e * t[1] - f * t[3] + h * t[5])
   - d * (e * t[2] - f * t[4] + g * t[5])
   */
  x2 = glmm_fnmadd(glmm_shuff1(r1, 1, 1, 2, 2), glmm_shuff1(x0, 3, 2, 2, 0),
                   wasm_f32x4_mul(glmm_shuff1(r1, 0, 0, 0, 1),
                              wasm_i32x4_shuffle(x1, x0, 0, 0, 4, 5)));
  x2 = glmm_fmadd(glmm_shuff1(r1, 2, 3, 3, 3),
                  wasm_i32x4_shuffle(x0, x1, 1, 3, 6, 6),
                  x2);
  /* x2 = wasm_v128_xor(x2, wasm_f32x4_const(0.f, -0.f, 0.f, -0.f)); */
  x2 = wasm_v128_xor(x2, glmm_float32x4_SIGNMASK_PNPN);
  
  return glmm_hadd(wasm_f32x4_mul(x2, r0));
}

CGLM_INLINE
void
glm_mat4_inv_fast_wasm(mat4 mat, mat4 dest) {
  glmm_128 r0, r1, r2, r3,
         v0, v1, v2, v3,
         t0, t1, t2, t3, t4, t5,
         x0, x1, x2, x3, x4, x5, x6, x7, x8, x9;

  /* x8 = wasm_f32x4_const(0.f, -0.f, 0.f, -0.f); */
  x8 = glmm_float32x4_SIGNMASK_PNPN;
  x9 = glmm_shuff1(x8, 2, 1, 2, 1);

  /* 127 <- 0 */
  r0 = glmm_load(mat[0]); /* d c b a */
  r1 = glmm_load(mat[1]); /* h g f e */
  r2 = glmm_load(mat[2]); /* l k j i */
  r3 = glmm_load(mat[3]); /* p o n m */
  /* x0 = _mm_movehl_ps(r3, r2); */
  x0 = wasm_i32x4_shuffle(r3, r2, 6, 7, 2, 3);           /* p o l k */
  /* x3 = _mm_movelh_ps(r2, r3); */
  x3 = wasm_i32x4_shuffle(r2, r3, 0, 1, 4, 5);           /* n m j i */
  x1 = glmm_shuff1(x0, 1, 3, 3 ,3);                      /* l p p p */
  x2 = glmm_shuff1(x0, 0, 2, 2, 2);                      /* k o o o */
  x4 = glmm_shuff1(x3, 1, 3, 3, 3);                      /* j n n n */
  x7 = glmm_shuff1(x3, 0, 2, 2, 2);                      /* i m m m */

  x6 = wasm_i32x4_shuffle(r2, r1, 0, 0, 4, 4);           /* e e i i */
  x5 = wasm_i32x4_shuffle(r2, r1, 1, 1, 5, 5);           /* f f j j */
  x3 = wasm_i32x4_shuffle(r2, r1, 2, 2, 6, 6);           /* g g k k */
  x0 = wasm_i32x4_shuffle(r2, r1, 3, 3, 7, 7);           /* h h l l */
  
  t0 = wasm_f32x4_mul(x3, x1);
  t1 = wasm_f32x4_mul(x5, x1);
  t2 = wasm_f32x4_mul(x5, x2);
  t3 = wasm_f32x4_mul(x6, x1);
  t4 = wasm_f32x4_mul(x6, x2);
  t5 = wasm_f32x4_mul(x6, x4);
  
  /* t1[0] = k * p - o * l;
     t1[0] = k * p - o * l;
     t2[0] = g * p - o * h;
     t3[0] = g * l - k * h; */
  t0 = glmm_fnmadd(x2, x0, t0);
  
  /* t1[1] = j * p - n * l;
     t1[1] = j * p - n * l;
     t2[1] = f * p - n * h;
     t3[1] = f * l - j * h; */
   t1 = glmm_fnmadd(x4, x0, t1);
  
  /* t1[2] = j * o - n * k
     t1[2] = j * o - n * k;
     t2[2] = f * o - n * g;
     t3[2] = f * k - j * g; */
  t2 = glmm_fnmadd(x4, x3, t2);
  
  /* t1[3] = i * p - m * l;
     t1[3] = i * p - m * l;
     t2[3] = e * p - m * h;
     t3[3] = e * l - i * h; */
  t3 = glmm_fnmadd(x7, x0, t3);
  
  /* t1[4] = i * o - m * k;
     t1[4] = i * o - m * k;
     t2[4] = e * o - m * g;
     t3[4] = e * k - i * g; */
  t4 = glmm_fnmadd(x7, x3, t4);
  
  /* t1[5] = i * n - m * j;
     t1[5] = i * n - m * j;
     t2[5] = e * n - m * f;
     t3[5] = e * j - i * f; */
  t5 = glmm_fnmadd(x7, x5, t5);
  /* x4 = _mm_movelh_ps(r0, r1); */
  x4 = wasm_i32x4_shuffle(r0, r1, 0, 1, 4, 5);           /* f e b a */
  /* x5 = _mm_movehl_ps(r1, r0); */
  x5 = wasm_i32x4_shuffle(r1, r0, 6, 7, 2, 3);           /* h g d c */
  
  x0 = glmm_shuff1(x4, 0, 0, 0, 2);                      /* a a a e */
  x1 = glmm_shuff1(x4, 1, 1, 1, 3);                      /* b b b f */
  x2 = glmm_shuff1(x5, 0, 0, 0, 2);                      /* c c c g */
  x3 = glmm_shuff1(x5, 1, 1, 1, 3);                      /* d d d h */
  
  v2 = wasm_f32x4_mul(x0, t1);
  v1 = wasm_f32x4_mul(x0, t0);
  v3 = wasm_f32x4_mul(x0, t2);
  v0 = wasm_f32x4_mul(x1, t0);
  
  v2 = glmm_fnmadd(x1, t3, v2);
  v3 = glmm_fnmadd(x1, t4, v3);
  v0 = glmm_fnmadd(x2, t1, v0);
  v1 = glmm_fnmadd(x2, t3, v1);
  
  v3 = glmm_fmadd(x2, t5, v3);
  v0 = glmm_fmadd(x3, t2, v0);
  v2 = glmm_fmadd(x3, t5, v2);
  v1 = glmm_fmadd(x3, t4, v1);

  /*
   dest[0][0] =  f * t1[0] - g * t1[1] + h * t1[2];
   dest[0][1] =-(b * t1[0] - c * t1[1] + d * t1[2]);
   dest[0][2] =  b * t2[0] - c * t2[1] + d * t2[2];
   dest[0][3] =-(b * t3[0] - c * t3[1] + d * t3[2]); */
  v0 = wasm_v128_xor(v0, x8);
  
  /*
   dest[2][0] =  e * t1[1] - f * t1[3] + h * t1[5];
   dest[2][1] =-(a * t1[1] - b * t1[3] + d * t1[5]);
   dest[2][2] =  a * t2[1] - b * t2[3] + d * t2[5];
   dest[2][3] =-(a * t3[1] - b * t3[3] + d * t3[5]);*/
  v2 = wasm_v128_xor(v2, x8);

  /*
   dest[1][0] =-(e * t1[0] - g * t1[3] + h * t1[4]);
   dest[1][1] =  a * t1[0] - c * t1[3] + d * t1[4];
   dest[1][2] =-(a * t2[0] - c * t2[3] + d * t2[4]);
   dest[1][3] =  a * t3[0] - c * t3[3] + d * t3[4]; */
  v1 = wasm_v128_xor(v1, x9);

  /*
   dest[3][0] =-(e * t1[2] - f * t1[4] + g * t1[5]);
   dest[3][1] =  a * t1[2] - b * t1[4] + c * t1[5];
   dest[3][2] =-(a * t2[2] - b * t2[4] + c * t2[5]);
   dest[3][3] =  a * t3[2] - b * t3[4] + c * t3[5]; */
  v3 = wasm_v128_xor(v3, x9);

  /* determinant */
  x0 = wasm_i32x4_shuffle(v0, v1, 0, 0, 4, 4);
  x1 = wasm_i32x4_shuffle(v2, v3, 0, 0, 4, 4);
  x0 = wasm_i32x4_shuffle(x0, x1, 0, 2, 4, 6);

  /* x0 = _mm_rcp_ps(glmm_vhadd(wasm_f32x4_mul(x0, r0))); */
  x0 = wasm_f32x4_div(wasm_f32x4_const_splat(1.0f),
                      glmm_vhadd(wasm_f32x4_mul(x0, r0)));

  glmm_store(dest[0], wasm_f32x4_mul(v0, x0));
  glmm_store(dest[1], wasm_f32x4_mul(v1, x0));
  glmm_store(dest[2], wasm_f32x4_mul(v2, x0));
  glmm_store(dest[3], wasm_f32x4_mul(v3, x0));
}

CGLM_INLINE
void
glm_mat4_inv_wasm(mat4 mat, mat4 dest) {
  glmm_128 r0, r1, r2, r3,
         v0, v1, v2, v3,
         t0, t1, t2, t3, t4, t5,
         x0, x1, x2, x3, x4, x5, x6, x7, x8, x9;

  /* x8 = wasm_f32x4_const(0.f, -0.f, 0.f, -0.f); */
  x8 = glmm_float32x4_SIGNMASK_PNPN;
  x9 = glmm_shuff1(x8, 2, 1, 2, 1);

  /* 127 <- 0 */
  r0 = glmm_load(mat[0]); /* d c b a */
  r1 = glmm_load(mat[1]); /* h g f e */
  r2 = glmm_load(mat[2]); /* l k j i */
  r3 = glmm_load(mat[3]); /* p o n m */
  /* x0 = _mm_movehl_ps(r3, r2); */
  x0 = wasm_i32x4_shuffle(r3, r2, 6, 7, 2, 3);           /* p o l k */
  /* x3 = _mm_movelh_ps(r2, r3); */
  x3 = wasm_i32x4_shuffle(r2, r3, 0, 1, 4, 5);           /* n m j i */
  x1 = glmm_shuff1(x0, 1, 3, 3 ,3);                      /* l p p p */
  x2 = glmm_shuff1(x0, 0, 2, 2, 2);                      /* k o o o */
  x4 = glmm_shuff1(x3, 1, 3, 3, 3);                      /* j n n n */
  x7 = glmm_shuff1(x3, 0, 2, 2, 2);                      /* i m m m */

  x6 = wasm_i32x4_shuffle(r2, r1, 0, 0, 4, 4);           /* e e i i */
  x5 = wasm_i32x4_shuffle(r2, r1, 1, 1, 5, 5);           /* f f j j */
  x3 = wasm_i32x4_shuffle(r2, r1, 2, 2, 6, 6);           /* g g k k */
  x0 = wasm_i32x4_shuffle(r2, r1, 3, 3, 7, 7);           /* h h l l */
  
  t0 = wasm_f32x4_mul(x3, x1);
  t1 = wasm_f32x4_mul(x5, x1);
  t2 = wasm_f32x4_mul(x5, x2);
  t3 = wasm_f32x4_mul(x6, x1);
  t4 = wasm_f32x4_mul(x6, x2);
  t5 = wasm_f32x4_mul(x6, x4);
  
  /* t1[0] = k * p - o * l;
     t1[0] = k * p - o * l;
     t2[0] = g * p - o * h;
     t3[0] = g * l - k * h; */
  t0 = glmm_fnmadd(x2, x0, t0);
  
  /* t1[1] = j * p - n * l;
     t1[1] = j * p - n * l;
     t2[1] = f * p - n * h;
     t3[1] = f * l - j * h; */
   t1 = glmm_fnmadd(x4, x0, t1);
  
  /* t1[2] = j * o - n * k
     t1[2] = j * o - n * k;
     t2[2] = f * o - n * g;
     t3[2] = f * k - j * g; */
  t2 = glmm_fnmadd(x4, x3, t2);
  
  /* t1[3] = i * p - m * l;
     t1[3] = i * p - m * l;
     t2[3] = e * p - m * h;
     t3[3] = e * l - i * h; */
  t3 = glmm_fnmadd(x7, x0, t3);
  
  /* t1[4] = i * o - m * k;
     t1[4] = i * o - m * k;
     t2[4] = e * o - m * g;
     t3[4] = e * k - i * g; */
  t4 = glmm_fnmadd(x7, x3, t4);
  
  /* t1[5] = i * n - m * j;
     t1[5] = i * n - m * j;
     t2[5] = e * n - m * f;
     t3[5] = e * j - i * f; */
  t5 = glmm_fnmadd(x7, x5, t5);
  /* x4 = _mm_movelh_ps(r0, r1); */
  x4 = wasm_i32x4_shuffle(r0, r1, 0, 1, 4, 5);           /* f e b a */
  /* x5 = _mm_movehl_ps(r1, r0); */
  x5 = wasm_i32x4_shuffle(r1, r0, 6, 7, 2, 3);           /* h g d c */
  
  x0 = glmm_shuff1(x4, 0, 0, 0, 2);                      /* a a a e */
  x1 = glmm_shuff1(x4, 1, 1, 1, 3);                      /* b b b f */
  x2 = glmm_shuff1(x5, 0, 0, 0, 2);                      /* c c c g */
  x3 = glmm_shuff1(x5, 1, 1, 1, 3);                      /* d d d h */
  
  v2 = wasm_f32x4_mul(x0, t1);
  v1 = wasm_f32x4_mul(x0, t0);
  v3 = wasm_f32x4_mul(x0, t2);
  v0 = wasm_f32x4_mul(x1, t0);
  
  v2 = glmm_fnmadd(x1, t3, v2);
  v3 = glmm_fnmadd(x1, t4, v3);
  v0 = glmm_fnmadd(x2, t1, v0);
  v1 = glmm_fnmadd(x2, t3, v1);
  
  v3 = glmm_fmadd(x2, t5, v3);
  v0 = glmm_fmadd(x3, t2, v0);
  v2 = glmm_fmadd(x3, t5, v2);
  v1 = glmm_fmadd(x3, t4, v1);

  /*
   dest[0][0] =  f * t1[0] - g * t1[1] + h * t1[2];
   dest[0][1] =-(b * t1[0] - c * t1[1] + d * t1[2]);
   dest[0][2] =  b * t2[0] - c * t2[1] + d * t2[2];
   dest[0][3] =-(b * t3[0] - c * t3[1] + d * t3[2]); */
  v0 = wasm_v128_xor(v0, x8);
  
  /*
   dest[2][0] =  e * t1[1] - f * t1[3] + h * t1[5];
   dest[2][1] =-(a * t1[1] - b * t1[3] + d * t1[5]);
   dest[2][2] =  a * t2[1] - b * t2[3] + d * t2[5];
   dest[2][3] =-(a * t3[1] - b * t3[3] + d * t3[5]);*/
  v2 = wasm_v128_xor(v2, x8);

  /*
   dest[1][0] =-(e * t1[0] - g * t1[3] + h * t1[4]);
   dest[1][1] =  a * t1[0] - c * t1[3] + d * t1[4];
   dest[1][2] =-(a * t2[0] - c * t2[3] + d * t2[4]);
   dest[1][3] =  a * t3[0] - c * t3[3] + d * t3[4]; */
  v1 = wasm_v128_xor(v1, x9);

  /*
   dest[3][0] =-(e * t1[2] - f * t1[4] + g * t1[5]);
   dest[3][1] =  a * t1[2] - b * t1[4] + c * t1[5];
   dest[3][2] =-(a * t2[2] - b * t2[4] + c * t2[5]);
   dest[3][3] =  a * t3[2] - b * t3[4] + c * t3[5]; */
  v3 = wasm_v128_xor(v3, x9);

  /* determinant */
  x0 = wasm_i32x4_shuffle(v0, v1, 0, 0, 4, 4);
  x1 = wasm_i32x4_shuffle(v2, v3, 0, 0, 4, 4);
  x0 = wasm_i32x4_shuffle(x0, x1, 0, 2, 4, 6);

  x0 = wasm_f32x4_div(wasm_f32x4_splat(1.0f), glmm_vhadd(wasm_f32x4_mul(x0, r0)));

  glmm_store(dest[0], wasm_f32x4_mul(v0, x0));
  glmm_store(dest[1], wasm_f32x4_mul(v1, x0));
  glmm_store(dest[2], wasm_f32x4_mul(v2, x0));
  glmm_store(dest[3], wasm_f32x4_mul(v3, x0));
}

#endif
#endif /* cglm_mat_wasm_h */
