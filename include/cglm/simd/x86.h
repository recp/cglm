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

#define glmm_set1(x) _mm_set1_ps(x)
#define glmm_128     __m128

#ifdef CGLM_USE_INT_DOMAIN
#  define glmm_shuff1(xmm, z, y, x, w)                                        \
     _mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(xmm),                \
                                        _MM_SHUFFLE(z, y, x, w)))
#else
#  define glmm_shuff1(xmm, z, y, x, w)                                        \
       _mm_shuffle_ps(xmm, xmm, _MM_SHUFFLE(z, y, x, w))
#endif

#define glmm_splat(x, lane) glmm_shuff1(x, lane, lane, lane, lane)

#define glmm_splat_x(x) glmm_splat(x, 0)
#define glmm_splat_y(x) glmm_splat(x, 1)
#define glmm_splat_z(x) glmm_splat(x, 2)
#define glmm_splat_w(x) glmm_splat(x, 3)

/* glmm_shuff1x() is DEPRECATED!, use glmm_splat() */
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

#define GLMM_NEGZEROf 0x80000000 /*  0x80000000 ---> -0.0f  */

#define GLMM__SIGNMASKf(X, Y, Z, W)                                           \
   _mm_castsi128_ps(_mm_set_epi32(X, Y, Z, W))
  /* _mm_set_ps(X, Y, Z, W); */

#define glmm_float32x4_SIGNMASK_PNPN GLMM__SIGNMASKf(0, GLMM_NEGZEROf, 0, GLMM_NEGZEROf)
#define glmm_float32x4_SIGNMASK_NPNP GLMM__SIGNMASKf(GLMM_NEGZEROf, 0, GLMM_NEGZEROf, 0)
#define glmm_float32x4_SIGNMASK_NPPN GLMM__SIGNMASKf(GLMM_NEGZEROf, 0, 0, GLMM_NEGZEROf)

#define glmm_float32x4_SIGNMASK_NEG _mm_castsi128_ps(_mm_set1_epi32(0x80000000)) /* _mm_set1_ps(-0.0f) */
#define glmm_float32x8_SIGNMASK_NEG _mm256_castsi256_ps(_mm256_set1_epi32(GLMM_NEGZEROf))

static inline
__m128
glmm_abs(__m128 x) {
  return _mm_andnot_ps(glmm_float32x4_SIGNMASK_NEG, x);
}

static inline
__m128
glmm_vhadd(__m128 v) {
  __m128 x0;
  x0 = _mm_add_ps(v,  glmm_shuff1(v, 0, 1, 2, 3));
  x0 = _mm_add_ps(x0, glmm_shuff1(x0, 1, 0, 0, 1));
  return x0;
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
  x2 = glmm_splat(x1, 1);       /* [1|3, 1|3, 1|3, 1|3] */
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
  x2 = glmm_splat(x1, 1);       /* [1|3, 1|3, 1|3, 1|3] */
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

  xy = _mm_loadl_epi64(CGLM_CASTPTR_ASSUME_ALIGNED(v, const __m128i));
  z  = _mm_load_ss(&v[2]);

  return _mm_movelh_ps(_mm_castsi128_ps(xy), z);
}

static inline
void
glmm_store3(float v[3], __m128 vx) {
  _mm_storel_pi(CGLM_CASTPTR_ASSUME_ALIGNED(v, __m64), vx);
  _mm_store_ss(&v[2], glmm_shuff1(vx, 2, 2, 2, 2));
}

static inline
__m128
glmm_div(__m128 a, __m128 b) {
  return _mm_div_ps(a, b);
}

/* enable FMA macro for MSVC? */
#if defined(_MSC_VER) && !defined(__FMA__) && defined(__AVX2__)
#  define __FMA__ 1
#endif

static inline
__m128
glmm_fmadd(__m128 a, __m128 b, __m128 c) {
#ifdef __FMA__
  return _mm_fmadd_ps(a, b, c);
#else
  return _mm_add_ps(c, _mm_mul_ps(a, b));
#endif
}

static inline
__m128
glmm_fnmadd(__m128 a, __m128 b, __m128 c) {
#ifdef __FMA__
  return _mm_fnmadd_ps(a, b, c);
#else
  return _mm_sub_ps(c, _mm_mul_ps(a, b));
#endif
}

static inline
__m128
glmm_fmsub(__m128 a, __m128 b, __m128 c) {
#ifdef __FMA__
  return _mm_fmsub_ps(a, b, c);
#else
  return _mm_sub_ps(_mm_mul_ps(a, b), c);
#endif
}

static inline
__m128
glmm_fnmsub(__m128 a, __m128 b, __m128 c) {
#ifdef __FMA__
  return _mm_fnmsub_ps(a, b, c);
#else
  return _mm_xor_ps(_mm_add_ps(_mm_mul_ps(a, b), c),
                    glmm_float32x4_SIGNMASK_NEG);
#endif
}

#if defined(__AVX__)
static inline
__m256
glmm256_fmadd(__m256 a, __m256 b, __m256 c) {
#ifdef __FMA__
  return _mm256_fmadd_ps(a, b, c);
#else
  return _mm256_add_ps(c, _mm256_mul_ps(a, b));
#endif
}

static inline
__m256
glmm256_fnmadd(__m256 a, __m256 b, __m256 c) {
#ifdef __FMA__
  return _mm256_fnmadd_ps(a, b, c);
#else
  return _mm256_sub_ps(c, _mm256_mul_ps(a, b));
#endif
}

static inline
__m256
glmm256_fmsub(__m256 a, __m256 b, __m256 c) {
#ifdef __FMA__
  return _mm256_fmsub_ps(a, b, c);
#else
  return _mm256_sub_ps(_mm256_mul_ps(a, b), c);
#endif
}

static inline
__m256
glmm256_fnmsub(__m256 a, __m256 b, __m256 c) {
#ifdef __FMA__
  return _mm256_fmsub_ps(a, b, c);
#else
  return _mm256_xor_ps(_mm256_sub_ps(_mm256_mul_ps(a, b), c),
                       glmm_float32x8_SIGNMASK_NEG);
#endif
}
#endif

#endif
#endif /* cglm_simd_x86_h */
