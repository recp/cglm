/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_mat3x2_h
#define cglmc_mat3x2_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_mat3x2_copy(mat3x2 src, mat3x2 dest);

CGLM_EXPORT
void
glmc_mat3x2_zero(mat3x2 m);

CGLM_EXPORT
void
glmc_mat3x2_make(const float * __restrict src, mat3x2 dest);

CGLM_EXPORT
void
glmc_mat3x2_mul(mat3x2 m1, mat2x3 m2, mat2 dest);

CGLM_EXPORT
void
glmc_mat3x2_mulv(mat3x2 m, vec3 v, vec2 dest);

CGLM_EXPORT
void
glmc_mat3x2_transpose(mat3x2 src, mat2x3 dest);

CGLM_EXPORT
void
glmc_mat3x2_scale(mat3x2 m, float s);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_mat3x2_h */
