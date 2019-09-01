/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_simd_x86_h
#define cglm_simd_x86_h
#include "intrin.h"
#ifdef CGLM_SIMD_x86

#ifdef CGLM_ALL_UNALIGNED
#  define glmm_load(p)      _mm_loadu_ps(p)
#  define glmm_store(p, a)  _mm_storeu_ps(p, a)
#else
#  define glmm_load(p)      _mm_load_ps(p)
#  define glmm_store(p, a)  _mm_store_ps(p, a)
#endif

#ifdef CGLM_USE_INT_DOMAIN
#  define glmm_shuff1(xmm, z, y, x, w)                                        \
     _mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(xmm),                \
                                        _MM_SHUFFLE(z, y, x, w)))
#else
#  define glmm_shuff1(xmm, z, y, x, w)                                        \
       _mm_shuffle_ps(xmm, xmm, _MM_SHUFFLE(z, y, x, w))
#endif

#define glmm_shuff1x(xmm, x) glmm_shuff1(xmm, x, x, x, x)
#define glmm_shuff2(a, b, z0, y0, x0, w0, z1, y1, x1, w1)                     \
     glmm_shuff1(_mm_shuffle_ps(a, b, _MM_SHUFFLE(z0, y0, x0, w0)),           \
                 z1, y1, x1, w1)

#ifdef __AVX__
#  ifdef CGLM_ALL_UNALIGNED
#    define glmm_load256(p)      _mm256_loadu_ps(p)
#    define glmm_store256(p, a)  _mm256_storeu_ps(p, a)
#  else
#    define glmm_load256(p)      _mm256_load_ps(p)
#    define glmm_store256(p, a)  _mm256_store_ps(p, a)
#  endif
#endif

static inline
__m128
glmm_abs(__m128 x) {
  return _mm_andnot_ps(_mm_set1_ps(-0.0f), x);
}

static inline
__m128
glmm_vhadds(__m128 v) {
#if defined(__SSE3__)
  __m128 shuf, sums;
  shuf = _mm_movehdup_ps(v);
  sums = _mm_add_ps(v, shuf);
  shuf = _mm_movehl_ps(shuf, sums);
  sums = _mm_add_ss(sums, shuf);
  return sums;
#else
  __m128 shuf, sums;
  shuf = glmm_shuff1(v, 2, 3, 0, 1);
  sums = _mm_add_ps(v, shuf);
  shuf = _mm_movehl_ps(shuf, sums);
  sums = _mm_add_ss(sums, shuf);
  return sums;
#endif
}

static inline
float
glmm_hadd(__m128 v) {
  return _mm_cvtss_f32(glmm_vhadds(v));
}

static inline
__m128
glmm_vhmin(__m128 v) {
  __m128 x0, x1, x2;
  x0 = _mm_movehl_ps(v, v);     /* [2, 3, 2, 3] */
  x1 = _mm_min_ps(x0, v);       /* [0|2, 1|3, 2|2, 3|3] */
  x2 = glmm_shuff1x(x1, 1);     /* [1|3, 1|3, 1|3, 1|3] */
  return _mm_min_ss(x1, x2);
}

static inline
float
glmm_hmin(__m128 v) {
  return _mm_cvtss_f32(glmm_vhmin(v));
}

static inline
__m128
glmm_vhmax(__m128 v) {
  __m128 x0, x1, x2;
  x0 = _mm_movehl_ps(v, v);     /* [2, 3, 2, 3] */
  x1 = _mm_max_ps(x0, v);       /* [0|2, 1|3, 2|2, 3|3] */
  x2 = glmm_shuff1x(x1, 1);     /* [1|3, 1|3, 1|3, 1|3] */
  return _mm_max_ss(x1, x2);
}

static inline
float
glmm_hmax(__m128 v) {
  return _mm_cvtss_f32(glmm_vhmax(v));
}

static inline
__m128
glmm_vdots(__m128 a, __m128 b) {
#if (defined(__SSE4_1__) || defined(__SSE4_2__)) && defined(CGLM_SSE4_DOT)
  return _mm_dp_ps(a, b, 0xFF);
#elif defined(__SSE3__) && defined(CGLM_SSE3_DOT)
  __m128 x0, x1;
  x0 = _mm_mul_ps(a, b);
  x1 = _mm_hadd_ps(x0, x0);
  return _mm_hadd_ps(x1, x1);
#else
  return glmm_vhadds(_mm_mul_ps(a, b));
#endif
}

static inline
__m128
glmm_vdot(__m128 a, __m128 b) {
#if (defined(__SSE4_1__) || defined(__SSE4_2__)) && defined(CGLM_SSE4_DOT)
  return _mm_dp_ps(a, b, 0xFF);
#elif defined(__SSE3__) && defined(CGLM_SSE3_DOT)
  __m128 x0, x1;
  x0 = _mm_mul_ps(a, b);
  x1 = _mm_hadd_ps(x0, x0);
  return _mm_hadd_ps(x1, x1);
#else
  __m128 x0;
  x0 = _mm_mul_ps(a, b);
  x0 = _mm_add_ps(x0, glmm_shuff1(x0, 1, 0, 3, 2));
  return _mm_add_ps(x0, glmm_shuff1(x0, 0, 1, 0, 1));
#endif
}

static inline
float
glmm_dot(__m128 a, __m128 b) {
  return _mm_cvtss_f32(glmm_vdots(a, b));
}

static inline
float
glmm_norm(__m128 a) {
  return _mm_cvtss_f32(_mm_sqrt_ss(glmm_vhadds(_mm_mul_ps(a, a))));
}

static inline
float
glmm_norm2(__m128 a) {
  return _mm_cvtss_f32(glmm_vhadds(_mm_mul_ps(a, a)));
}

static inline
float
glmm_norm_one(__m128 a) {
  return _mm_cvtss_f32(glmm_vhadds(glmm_abs(a)));
}

static inline
float
glmm_norm_inf(__m128 a) {
  return _mm_cvtss_f32(glmm_vhmax(glmm_abs(a)));
}

static inline
__m128
glmm_load3(float v[3]) {
  __m128i xy;
  __m128  z;

  xy = _mm_loadl_epi64((const __m128i *)v);
  z  = _mm_load_ss(&v[2]);

  return _mm_movelh_ps(_mm_castsi128_ps(xy), z);
}

static inline
void
glmm_store3(float v[3], __m128 vx) {
  _mm_storel_pi((__m64 *)&v[0], vx);
  _mm_store_ss(&v[2], glmm_shuff1(vx, 2, 2, 2, 2));
}

#endif
#endif /* cglm_simd_x86_h */
