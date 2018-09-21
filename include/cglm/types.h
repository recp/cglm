/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_types_h
#define cglm_types_h

#if defined(_MSC_VER)
/* do not use alignment for older visual studio versions */
#if _MSC_VER < 1913 /*  Visual Studio 2017 version 15.6  */
#  define CGLM_ALL_UNALIGNED
#  define CGLM_ALIGN(X) /* no alignment */
#else
#  define CGLM_ALIGN(X) __declspec(align(X))
#endif
#else
#  define CGLM_ALIGN(X) __attribute((aligned(X)))
#endif

#ifndef CGLM_ALL_UNALIGNED
#  define CGLM_ALIGN_IF(X) CGLM_ALIGN(X)
#else
#  define CGLM_ALIGN_IF(X) /* no alignment */
#endif

#ifdef __AVX__
#  define CGLM_ALIGN_MAT CGLM_ALIGN(32)
#else
#  define CGLM_ALIGN_MAT CGLM_ALIGN(16)
#endif

typedef float                   vec2[2];
typedef CGLM_ALIGN_IF(8)  float vec3[3];
typedef int                    ivec3[3];
typedef CGLM_ALIGN_IF(16) float vec4[4];

#ifdef __AVX__
typedef CGLM_ALIGN_IF(32) vec3  mat3[3];
typedef CGLM_ALIGN_IF(32) vec4  mat4[4];
#else
typedef                   vec3  mat3[3];
typedef CGLM_ALIGN_IF(16) vec4  mat4[4];
#endif


typedef vec4                    versor;

#define GLM_PI     3.14159265358979323846264338327950288
#define GLM_PI_2   1.57079632679489661923132169163975144
#define GLM_PI_4   0.785398163397448309615660845819875721

#define GLM_PIf    ((float)GLM_PI)
#define GLM_PI_2f  ((float)GLM_PI_2)
#define GLM_PI_4f  ((float)GLM_PI_4)

/* DEPRECATED! use GLM_PI and friends */
#define CGLM_PI    GLM_PIf
#define CGLM_PI_2  GLM_PI_2f
#define CGLM_PI_4  GLM_PI_4f

#endif /* cglm_types_h */
