/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_io_h
#define cglmc_io_h

#include "../cglm.h"

CGLM_EXPORT
void
glmc_mat4_print(mat4   matrix,
                FILE * __restrict ostream);

CGLM_EXPORT
void
glmc_mat3_print(mat3 matrix,
                FILE * __restrict ostream);

CGLM_EXPORT
void
glmc_vec4_print(vec4 vec,
                FILE * __restrict ostream);

CGLM_EXPORT
void
glmc_vec3_print(vec3 vec,
                FILE * __restrict ostream);

CGLM_EXPORT
void
glmc_versor_print(versor vec,
                  FILE * __restrict ostream);

#endif /* cglmc_io_h */
