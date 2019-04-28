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
glmc_mat4_ucopy(const mat4 mat, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_copy(const mat4 mat, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_identity(mat4 mat);

CGLM_EXPORT
void
glmc_mat4_identity_array(mat4 * const __restrict mat, size_t count);

CGLM_EXPORT
void
glmc_mat4_pick3(const mat4 mat, mat3 dest);

CGLM_EXPORT
void
glmc_mat4_pick3t(const mat4 mat, mat3 dest);

CGLM_EXPORT
void
glmc_mat4_ins3(const mat3 mat, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_mul(const mat4 m1, const mat4 m2, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_mulN(mat4 * const __restrict matrices[], uint32_t len, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_mulv(const mat4 m, const vec4 v, vec4 dest);

CGLM_EXPORT
void
glmc_mat4_mulv3(const mat4 m, const vec3 v, float last, vec3 dest);

CGLM_EXPORT
float
glmc_mat4_trace(const mat4 m);

CGLM_EXPORT
float
glmc_mat4_trace3(const mat4 m);

CGLM_EXPORT
void
glmc_mat4_quat(const mat4 m, versor dest);

CGLM_EXPORT
void
glmc_mat4_transpose_to(const mat4 m, mat4 dest);

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
glmc_mat4_det(const mat4 mat);

CGLM_EXPORT
void
glmc_mat4_inv(const mat4 mat, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_inv_precise(const mat4 mat, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_inv_fast(const mat4 mat, mat4 dest);

CGLM_EXPORT
void
glmc_mat4_swap_col(mat4 mat, int col1, int col2);

CGLM_EXPORT
void
glmc_mat4_swap_row(mat4 mat, int row1, int row2);

CGLM_EXPORT
float
glmc_mat4_rmc(const vec4 r, const mat4 m, const vec4 c);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_mat_h */
