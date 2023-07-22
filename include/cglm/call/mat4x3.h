/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_mat4x3_h
#define cglmc_mat4x3_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_mat4x3_copy(mat4x3 mat, mat4x3 dest);

CGLM_EXPORT
void
glmc_mat4x3_zero(mat4x3 mat);

CGLM_EXPORT
void
glmc_mat4x3_make(float * __restrict src, mat4x3 dest);

CGLM_EXPORT
void
glmc_mat4x3_mul(mat4x3 m1, mat3x4 m2, mat4 dest);

CGLM_EXPORT
void
glmc_mat4x3_mulv(mat4x3 m, vec3 v, vec4 dest);

CGLM_EXPORT
void
glmc_mat4x3_transpose(mat4x3 m, mat3x4 dest);

CGLM_EXPORT
void
glmc_mat4x3_scale(mat4x3 m, float s);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_mat4x3_h */
