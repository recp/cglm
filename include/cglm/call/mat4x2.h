/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_mat4x2_h
#define cglmc_mat4x2_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../common.h"

CGLM_EXPORT
void
glmc_mat4x2_copy(CGLM_CONST mat4x2 src, mat4x2 dest);

CGLM_EXPORT
void
glmc_mat4x2_zero(mat4x2 m);

CGLM_EXPORT
void
glmc_mat4x2_make(const float * __restrict src, mat4x2 dest);

CGLM_EXPORT
void
glmc_mat4x2_mul(CGLM_CONST mat4x2 m1, CGLM_CONST mat2x4 m2, mat2 dest);

CGLM_EXPORT
void
glmc_mat4x2_mulv(CGLM_CONST mat4x2 m, const vec4 v, vec2 dest);

CGLM_EXPORT
void
glmc_mat4x2_transpose(CGLM_CONST mat4x2 src, mat2x4 dest);

CGLM_EXPORT
void
glmc_mat4x2_scale(mat4x2 m, float s);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_mat4x2_h */
