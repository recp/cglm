/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_common_h
#define cglm_common_h

#ifndef _USE_MATH_DEFINES
#  define _USE_MATH_DEFINES       /* for windows */
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#  define _CRT_SECURE_NO_WARNINGS /* for windows */
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

#if defined(_MSC_VER)
#  ifdef CGLM_STATIC
#    define CGLM_EXPORT
#  elif defined(CGLM_EXPORTS)
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

#ifndef CGLM_USE_DEFAULT_EPSILON
#  ifndef GLM_FLT_EPSILON
#    define GLM_FLT_EPSILON 1e-5f
#  endif
#else
#  define GLM_FLT_EPSILON FLT_EPSILON
#endif

/*
 * Clip control: define CGLM_FORCE_DEPTH_ZERO_TO_ONE before including
 * CGLM to use a clip space between 0 to 1.
 * Coordinate system: define CGLM_FORCE_LEFT_HANDED before including
 * CGLM to use the left handed coordinate system by default.
 */

#define CGLM_CLIP_CONTROL_ZO_BIT (1 << 0) /* ZERO_TO_ONE */
#define CGLM_CLIP_CONTROL_NO_BIT (1 << 1) /* NEGATIVE_ONE_TO_ONE */
#define CGLM_CLIP_CONTROL_LH_BIT (1 << 2) /* LEFT_HANDED, For DirectX, Metal, Vulkan */
#define CGLM_CLIP_CONTROL_RH_BIT (1 << 3) /* RIGHT_HANDED, For OpenGL, default in GLM */

#define CGLM_CLIP_CONTROL_LH_ZO (CGLM_CLIP_CONTROL_LH_BIT | CGLM_CLIP_CONTROL_ZO_BIT)
#define CGLM_CLIP_CONTROL_LH_NO (CGLM_CLIP_CONTROL_LH_BIT | CGLM_CLIP_CONTROL_NO_BIT)
#define CGLM_CLIP_CONTROL_RH_ZO (CGLM_CLIP_CONTROL_RH_BIT | CGLM_CLIP_CONTROL_ZO_BIT)
#define CGLM_CLIP_CONTROL_RH_NO (CGLM_CLIP_CONTROL_RH_BIT | CGLM_CLIP_CONTROL_NO_BIT)

#ifdef CGLM_FORCE_DEPTH_ZERO_TO_ONE
#  ifdef CGLM_FORCE_LEFT_HANDED
#    define CGLM_CONFIG_CLIP_CONTROL CGLM_CLIP_CONTROL_LH_ZO
#  else
#    define CGLM_CONFIG_CLIP_CONTROL CGLM_CLIP_CONTROL_RH_ZO
#  endif
#else
#  ifdef CGLM_FORCE_LEFT_HANDED
#    define CGLM_CONFIG_CLIP_CONTROL CGLM_CLIP_CONTROL_LH_NO
#  else
#    define CGLM_CONFIG_CLIP_CONTROL CGLM_CLIP_CONTROL_RH_NO
#  endif
#endif

/* struct API configurator */
/* TODO: move struct/common.h? */
/* WARN: dont use concant helpers outside cglm headers, because they may be changed */

#define CGLM_MACRO_CONCAT_HELPER(A, B, C, D, E, ...) A ## B ## C ## D ## E ## __VA_ARGS__
#define CGLM_MACRO_CONCAT(A, B, C, D, E, ...) CGLM_MACRO_CONCAT_HELPER(A, B, C, D, E,__VA_ARGS__)

#ifndef CGLM_OMIT_NS_FROM_STRUCT_API
#  ifndef CGLM_STRUCT_API_NS
#    define CGLM_STRUCT_API_NS glms
#  endif
#  ifndef CGLM_STRUCT_API_NS_SEPERATOR
#    define CGLM_STRUCT_API_NS_SEPERATOR _
#  endif
#else
#  define CGLM_STRUCT_API_NS
#  define CGLM_STRUCT_API_NS_SEPERATOR
#endif

#ifndef CGLM_STRUCT_API_NAME_SUFFIX
#  define CGLM_STRUCT_API_NAME_SUFFIX
#endif

#define CGLM_STRUCTAPI(A, ...) CGLM_MACRO_CONCAT(CGLM_STRUCT_API_NS,             \
                                                 CGLM_STRUCT_API_NS_SEPERATOR,   \
                                                 A,                              \
                                                 CGLM_STRUCT_API_NAME_SUFFIX,    \
                                                 _,                              \
                                                 __VA_ARGS__)

#endif /* cglm_common_h */
