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
#  define CGLM_SSE_FP 1
#  ifndef CGLM_SIMD_x86
#    define CGLM_SIMD_x86
#  endif
#endif

#if defined(__SSE3__)
#  include <pmmintrin.h>
#  ifndef CGLM_SIMD_x86
#    define CGLM_SIMD_x86
#  endif
#endif

#if defined(__SSE4_1__)
#  include <smmintrin.h>
#  ifndef CGLM_SIMD_x86
#    define CGLM_SIMD_x86
#  endif
#endif

#if defined(__SSE4_2__)
#  include <nmmintrin.h>
#  ifndef CGLM_SIMD_x86
#    define CGLM_SIMD_x86
#  endif
#endif

#ifdef __AVX__
#  include <immintrin.h>
#  define CGLM_AVX_FP 1
#  ifndef CGLM_SIMD_x86
#    define CGLM_SIMD_x86
#  endif
#endif

/* ARM Neon */
#if defined(__ARM_NEON)
#  include <arm_neon.h>
#  if defined(__ARM_NEON_FP)
#    define CGLM_NEON_FP 1
#    ifndef CGLM_SIMD_ARM
#      define CGLM_SIMD_ARM
#    endif
#  endif
#endif

#if defined(CGLM_SIMD_x86) || defined(CGLM_NEON_FP)
#  ifndef CGLM_SIMD
#    define CGLM_SIMD
#  endif
#endif

#if defined(CGLM_SIMD_x86)
#  include "x86.h"
#endif

#if defined(CGLM_SIMD_ARM)
#  include "arm.h"
#endif

#endif /* cglm_intrin_h */
