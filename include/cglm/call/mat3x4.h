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
glmc_mat3x4_make(float * __restrict src, mat3x4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_mat3x4_h */
