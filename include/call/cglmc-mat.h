/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_mat_h
#define cglmc_mat_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

/* DEPRECATED! use _copy, _ucopy versions */
#define glmc_mat4_udup(mat, dest) glmc_mat4_ucopy(mat, dest)
#define glmc_mat4_dup(mat, dest)  glmc_mat4_copy(mat, dest)

CGLM_EXPORT
void
glmc_mat4_ucopy(mat4 mat, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_copy(mat4 mat, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_pick3(mat4 mat, mat3 dest);

CGLM_EXPORT
void
glmc_mat4_pick3t(mat4 mat, mat3 dest);

CGLM_EXPORT
void
glmc_mat4_ins3(mat3 mat, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_mul(mat4 m1, mat4 m2, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_mulN(mat4 * __restrict matrices[], int len, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_mulv(mat4 m, vec4 v, vec4 dest);

CGLM_EXPORT
void
glmc_mat4_transpose_to(mat4 m, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_transpose(mat4 m);

CGLM_EXPORT
void
glmc_mat4_scale_p(mat4 m, float s);

CGLM_EXPORT
void
glmc_mat4_scale(mat4 m, float s);

CGLM_EXPORT
float
glmc_mat4_det(mat4 mat);

CGLM_EXPORT
void
glmc_mat4_inv(mat4 mat, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_inv_precise(mat4 mat, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_swap_col(mat4 mat, int col1, int col2);

CGLM_EXPORT
void
glmc_mat4_swap_row(mat4 mat, int row1, int row2);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_mat_h */
