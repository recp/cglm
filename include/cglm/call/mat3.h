/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_mat3_h
#define cglmc_mat3_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

/* DEPRECATED! use _copy, _ucopy versions */
#define glmc_mat3_dup(mat, dest)  glmc_mat3_copy(mat, dest)

CGLM_EXPORT
void
glmc_mat3_copy(const mat3 mat, mat3 dest);

CGLM_EXPORT
void
glmc_mat3_identity(mat3 mat);

CGLM_EXPORT
void
glmc_mat3_identity_array(mat3 * const __restrict mat, size_t count);

CGLM_EXPORT
void
glmc_mat3_mul(const mat3 m1, const mat3 m2, mat3 dest);

CGLM_EXPORT
void
glmc_mat3_transpose_to(const mat3 m, mat3 dest);

CGLM_EXPORT
void
glmc_mat3_transpose(mat3 m);

CGLM_EXPORT
void
glmc_mat3_mulv(const mat3 m, const vec3 v, vec3 dest);

CGLM_EXPORT
float
glmc_mat3_trace(const mat3 m);

CGLM_EXPORT
void
glmc_mat3_quat(const mat3 m, versor dest);

CGLM_EXPORT
void
glmc_mat3_scale(mat3 m, float s);

CGLM_EXPORT
float
glmc_mat3_det(const mat3 mat);

CGLM_EXPORT
void
glmc_mat3_inv(const mat3 mat, mat3 dest);

CGLM_EXPORT
void
glmc_mat3_swap_col(mat3 mat, int col1, int col2);

CGLM_EXPORT
void
glmc_mat3_swap_row(mat3 mat, int row1, int row2);

CGLM_EXPORT
float
glmc_mat3_rmc(const vec3 r, const mat3 m, const vec3 c);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_mat3_h */
