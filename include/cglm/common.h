/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_common_h
#define cglm_common_h

#define _USE_MATH_DEFINES /* for windows */

#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

#if defined(_MSC_VER)
#  ifdef CGLM_DLL
#    define CGLM_EXPORT __declspec(dllexport)
#  else
#    define CGLM_EXPORT __declspec(dllimport)
#  endif
#  define CGLM_INLINE __forceinline
#else
#  define CGLM_EXPORT __attribute__((visibility("default")))
#  define CGLM_INLINE static inline __attribute((always_inline))
#endif

#define GLM_SHUFFLE4(z, y, x, w) (((z) << 6) | ((y) << 4) | ((x) << 2) | (w))
#define GLM_SHUFFLE3(z, y, x)    (((z) << 4) | ((y) << 2) | (x))

#include "types.h"
#include "simd/intrin.h"

#endif /* cglm_common_h */
