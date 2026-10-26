/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_io_h
#define cglmc_io_h

#ifdef __cplusplus
extern "C" {
#endif

#include "../common.h"
#include <stdio.h>

CGLM_EXPORT
void
glmc_mat4_print(CGLM_CONST mat4 matrix,
                FILE * __restrict ostream);

CGLM_EXPORT
void
glmc_mat3_print(CGLM_CONST mat3 matrix,
                FILE * __restrict ostream);

CGLM_EXPORT
void
glmc_vec4_print(const vec4 vec,
                FILE * __restrict ostream);

CGLM_EXPORT
void
glmc_vec3_print(const vec3 vec,
                FILE * __restrict ostream);

CGLM_EXPORT
void
glmc_versor_print(const versor vec,
                  FILE * __restrict ostream);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_io_h */
