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
#    ifndef __SSE2__
#      define __SSE2__
#    endif
#  elif _M_IX86_FP == 1
#    ifndef __SSE__
#      define __SSE__
#    endif
#  endif
#endif

#if defined( __SSE__ ) || defined( __SSE2__ )
#  include <xmmintrin.h>
#  include <emmintrin.h>

/* float */
#  define _mm_shuffle1_ps(a, z, y, x, w)                                       \
     _mm_shuffle_ps(a, a, _MM_SHUFFLE(z, y, x, w))

#  define _mm_shuffle1_ps1(a, x)                                               \
     _mm_shuffle_ps(a, a, _MM_SHUFFLE(x, x, x, x))

#  define _mm_shuffle2_ps(a, b, z0, y0, x0, w0, z1, y1, x1, w1)                \
     _mm_shuffle1_ps(_mm_shuffle_ps(a, b, _MM_SHUFFLE(z0, y0, x0, w0)),        \
                                    z1, y1, x1, w1)

CGLM_INLINE
__m128
glm_simd_dot(__m128 a, __m128 b) {
  __m128 x0;
  x0 = _mm_mul_ps(a, b);
  x0 = _mm_add_ps(x0, _mm_shuffle1_ps(x0, 1, 0, 3, 2));
  return _mm_add_ps(x0, _mm_shuffle1_ps(x0, 0, 1, 0, 1));
}

CGLM_INLINE
__m128
glm_simd_norm(__m128 a) {
  return _mm_sqrt_ps(glm_simd_dot(a, a));
}

static inline
__m128
glm_simd_load_v3(vec3 v) {
  __m128i xy;
  __m128  z;

  xy = _mm_loadl_epi64((const __m128i *)v);
  z  = _mm_load_ss(&v[2]);

  return _mm_movelh_ps(_mm_castsi128_ps(xy), z);
}

static inline
void
glm_simd_store_v3(__m128 vx, vec3 v) {
  _mm_storel_pi((__m64 *)&v[0], vx);
  _mm_store_ss(&v[2], _mm_shuffle1_ps(vx, 2, 2, 2, 2));
}

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
