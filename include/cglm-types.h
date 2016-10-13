/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_types_h
#define cglm_types_h

#if defined(_WIN32)
#  define CGLM_ALIGN(X) /* __declspec(align(X)) */
#else
#  define CGLM_ALIGN(X) __attribute((aligned(X)))
#endif

typedef float vec3[3];
typedef CGLM_ALIGN(16) float vec4[4];

typedef vec3 mat3[3];
typedef vec4 mat4[4];

typedef vec4 versor;

#endif /* cglm_types_h */
