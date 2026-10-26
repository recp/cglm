/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_mat2x3_h
#define cglmc_mat2x3_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../common.h"

CGLM_EXPORT
void
glmc_mat2x3_copy(CGLM_CONST mat2x3 src, mat2x3 dest);

CGLM_EXPORT
void
glmc_mat2x3_zero(mat2x3 m);

CGLM_EXPORT
void
glmc_mat2x3_make(const float * __restrict src, mat2x3 dest);

CGLM_EXPORT
void
glmc_mat2x3_mul(CGLM_CONST mat2x3 m1, CGLM_CONST mat3x2 m2, mat3 dest);

CGLM_EXPORT
void
glmc_mat2x3_mulv(CGLM_CONST mat2x3 m, const vec2 v, vec3 dest);

CGLM_EXPORT
void
glmc_mat2x3_transpose(CGLM_CONST mat2x3 src, mat3x2 dest);

CGLM_EXPORT
void
glmc_mat2x3_scale(mat2x3 m, float s);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_mat2x3_h */
