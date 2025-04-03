/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_mat3x4_h
#define cglmc_mat3x4_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_mat3x4_copy(mat3x4 src, mat3x4 dest);

CGLM_EXPORT
void
glmc_mat3x4_zero(mat3x4 m);

CGLM_EXPORT
void
glmc_mat3x4_make(const float * __restrict src, mat3x4 dest);

CGLM_EXPORT
void
glmc_mat3x4_mul(mat3x4 m1, mat4x3 m2, mat4 dest);

CGLM_EXPORT
void
glmc_mat3x4_mulv(mat3x4 m, vec3 v, vec4 dest);

CGLM_EXPORT
void
glmc_mat3x4_transpose(mat3x4 src, mat4x3 dest);

CGLM_EXPORT
void
glmc_mat3x4_scale(mat3x4 m, float s);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_mat3x4_h */
