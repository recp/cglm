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

#include "../cglm.h"

CGLM_EXPORT
void
glmc_mat4_print(const mat4   matrix,
                FILE * const __restrict ostream);

CGLM_EXPORT
void
glmc_mat3_print(const mat3 matrix,
                FILE * const __restrict ostream);

CGLM_EXPORT
void
glmc_vec4_print(const vec4 vec,
                FILE * const __restrict ostream);

CGLM_EXPORT
void
glmc_vec3_print(const vec3 vec,
                FILE * const __restrict ostream);

CGLM_EXPORT
void
glmc_versor_print(const versor vec,
                  FILE * const __restrict ostream);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_io_h */
