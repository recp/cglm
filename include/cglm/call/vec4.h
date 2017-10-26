/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_vec4_h
#define cglmc_vec4_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

/* DEPRECATED! use _copy, _ucopy versions */
#define glmc_vec4_dup3(v, dest) glmc_vec4_copy3(v, dest)
#define glmc_vec4_dup(v, dest)  glmc_vec4_copy(v, dest)

CGLM_EXPORT
void
glmc_vec4_copy3(vec4 a, vec3 dest);

CGLM_EXPORT
void
glmc_vec4_copy(vec4 v, vec4 dest);

CGLM_EXPORT
float
glmc_vec4_dot(vec4 a, vec4 b);

CGLM_EXPORT
float
glmc_vec4_norm(vec4 vec);

CGLM_EXPORT
float
glmc_vec4_norm2(vec4 vec);

CGLM_EXPORT
void
glmc_vec4_normalize_to(vec4 vec, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_normalize(vec4 v);

CGLM_EXPORT
void
glmc_vec4_add(vec4 v1, vec4 v2, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_sub(vec4 v1, vec4 v2, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_scale(vec4 v, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_scale_as(vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec4_flipsign(vec4 v);

CGLM_EXPORT
void
glmc_vec4_inv(vec4 v);

CGLM_EXPORT
void
glmc_vec4_inv_to(vec4 v, vec4 dest);

CGLM_EXPORT
float
glmc_vec4_distance(vec4 v1, vec4 v2);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_vec4_h */

