/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_intrin_h
#define cglm_intrin_h

#if defined( _WIN32 )
#  if (defined(_M_AMD64) || defined(_M_X64)) || _M_IX86_FP == 2
#    define __SSE2__
#  elif _M_IX86_FP == 1
#    define __SSE__
#  endif
#endif

#if defined( __SSE__ ) || defined( __SSE2__ )
#  include <xmmintrin.h>
#  include <emmintrin.h>

/* OPTIONAL: You may save some instructions but latency (not sure) */
#ifdef CGLM_USE_INT_DOM_FOR_SHUFF
#  define _mm_shuffle1_ps(xmm, z, y, x, w)                                    \
  _mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(xmm),                   \
                   _MM_SHUFFLE(z, y, x, w)))
#else
#  define _mm_shuffle1_ps(xmm, z, y, x, w)                                    \
     _mm_shuffle_ps(xmm, xmm, _MM_SHUFFLE(z, y, x, w))
#endif

#  define _mm_shuffle1_ps1(xmm, x)                                            \
     _mm_shuffle1_ps(xmm, x, x, x, x)

#  define _mm_shuffle2_ps(a, b, z0, y0, x0, w0, z1, y1, x1, w1)               \
     _mm_shuffle1_ps(_mm_shuffle_ps(a, b, _MM_SHUFFLE(z0, y0, x0, w0)),       \
                                    z1, y1, x1, w1)
#endif

/* x86, x64 */
#if defined( __SSE__ ) || defined( __SSE2__ )
#  define CGLM_SSE_FP 1
#endif

#ifdef __AVX__
#  define CGLM_AVX_FP 1
#endif

/* ARM Neon */
#if defined(__ARM_NEON) && defined(__ARM_NEON_FP)
#  include <arm_neon.h>
#  define CGLM_NEON_FP 1
#else
#  undef  CGLM_NEON_FP
#endif

#endif /* cglm_intrin_h */
