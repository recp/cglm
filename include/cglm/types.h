/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_types_h
#define cglm_types_h

#if defined(_MSC_VER)
#  define CGLM_ALIGN(X) /* __declspec(align(X)) */
#else
#  define CGLM_ALIGN(X) __attribute((aligned(X)))
#endif

typedef float vec2[2];
typedef  CGLM_ALIGN(8) float vec3[3];
typedef int  ivec3[3];
typedef CGLM_ALIGN(16) float vec4[4];

typedef vec3 mat3[3];
typedef CGLM_ALIGN(16) vec4 mat4[4];

typedef vec4 versor;

#define CGLM_PI    (float)M_PI
#define CGLM_PI_2  (float)M_PI_2
#define CGLM_PI_4  (float)M_PI_4

#endif /* cglm_types_h */
