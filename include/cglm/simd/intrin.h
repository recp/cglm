/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_intrin_h
#define cglm_intrin_h

#if defined( _MSC_VER )
#  if (defined(_M_AMD64) || defined(_M_X64)) || _M_IX86_FP == 2
#    ifndef __SSE2__
#      define __SSE2__
#    endif
#  elif _M_IX86_FP == 1
#    ifndef __SSE__
#      define __SSE__
#    endif
#  endif
/* do not use alignment for older visual studio versions */
#  if _MSC_VER < 1913     /* Visual Studio 2017 version 15.6 */
#    define CGLM_ALL_UNALIGNED
#  endif
#endif

#if defined( __SSE__ ) || defined( __SSE2__ )
#  include <xmmintrin.h>
#  include <emmintrin.h>

/* OPTIONAL: You may save some instructions but latency (not sure) */
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

static inline
__m128
glmm_dot(__m128 a, __m128 b) {
  __m128 x0;
  x0 = _mm_mul_ps(a, b);
  x0 = _mm_add_ps(x0, glmm_shuff1(x0, 1, 0, 3, 2));
  return _mm_add_ps(x0, glmm_shuff1(x0, 0, 1, 0, 1));
}

static inline
__m128
glmm_norm(__m128 a) {
  return _mm_sqrt_ps(glmm_dot(a, a));
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
glmm_store3(__m128 vx, float v[3]) {
  _mm_storel_pi((__m64 *)&v[0], vx);
  _mm_store_ss(&v[2], glmm_shuff1(vx, 2, 2, 2, 2));
}

#ifdef CGLM_ALL_UNALIGNED
#  define glmm_load(p)      _mm_loadu_ps(p)
#  define glmm_store(p, a)  _mm_storeu_ps(p, a)
#else
#  define glmm_load(p)      _mm_load_ps(p)
#  define glmm_store(p, a)  _mm_store_ps(p, a)
#endif

#endif

/* x86, x64 */
#if defined( __SSE__ ) || defined( __SSE2__ )
#  define CGLM_SSE_FP 1
#endif

#ifdef __AVX__
#  define CGLM_AVX_FP 1

#ifdef CGLM_ALL_UNALIGNED
#  define glmm_load256(p)      _mm256_loadu_ps(p)
#  define glmm_store256(p, a)  _mm256_storeu_ps(p, a)
#else
#  define glmm_load256(p)      _mm256_load_ps(p)
#  define glmm_store256(p, a)  _mm256_store_ps(p, a)
#endif

#endif

#if defined(__SSE3__)
#  include <x86intrin.h>
#endif

#if defined(__SSE4_1__)
#  include <smmintrin.h>
#endif

#if defined(__SSE4_2__)
#  include <nmmintrin.h>
#endif

/* ARM Neon */
#if defined(__ARM_NEON)
#  include <arm_neon.h>
#  if defined(__ARM_NEON_FP)
#    define CGLM_NEON_FP 1
#  endif
#else
#  undef  CGLM_NEON_FP
#endif

#endif /* cglm_intrin_h */
