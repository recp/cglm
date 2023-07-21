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

#include "../cglm.h"

CGLM_EXPORT
void
glmc_mat2x3_copy(mat2x3 mat, mat2x3 dest);

CGLM_EXPORT
void
glmc_mat2x3_zero(mat2x3 mat);

CGLM_EXPORT
void
glmc_mat2x3_make(float * __restrict src, mat2x3 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_mat2x3_h */
