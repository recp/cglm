/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_vec_h
#define cglm_vec_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

/* DEPRECATED! use _copy, _ucopy versions */
#define glmc_vec_dup(v, dest)   glmc_vec_copy(v, dest)
#define glmc_vec4_dup3(v, dest) glmc_vec4_copy3(v, dest)
#define glmc_vec4_dup(v, dest)  glmc_vec4_copy(v, dest)

CGLM_EXPORT
void
glmc_vec_copy(vec3 a, vec3 dest);

CGLM_EXPORT
void
glmc_vec4_copy3(vec4 a, vec3 dest);

CGLM_EXPORT
void
glmc_vec4_copy(vec4 v, vec4 dest);

CGLM_EXPORT
float
glmc_vec_dot(vec3 a, vec3 b);

CGLM_EXPORT
float
glmc_vec4_dot(vec4 a, vec4 b);

CGLM_EXPORT
void
glmc_vec_cross(vec3 a, vec3 b, vec3 d);

CGLM_EXPORT
float
glmc_vec_norm(vec3 vec);

CGLM_EXPORT
float
glmc_vec4_norm(vec4 vec);

CGLM_EXPORT
float
glmc_vec_norm2(vec3 vec);

CGLM_EXPORT
float
glmc_vec4_norm2(vec4 vec);

CGLM_EXPORT
void
glmc_vec_normalize_to(vec3 vec, vec3 dest);

CGLM_EXPORT
void
glmc_vec4_normalize_to(vec4 vec, vec4 dest);

CGLM_EXPORT
void
glmc_vec_normalize(vec3 v);

CGLM_EXPORT
void
glmc_vec4_normalize(vec4 v);

CGLM_EXPORT
void
glmc_vec_add(vec3 v1, vec3 v2, vec3 dest);

CGLM_EXPORT
void
glmc_vec4_add(vec4 v1, vec4 v2, vec4 dest);

CGLM_EXPORT
void
glmc_vec_sub(vec3 v1, vec3 v2, vec3 dest);

CGLM_EXPORT
void
glmc_vec4_sub(vec4 v1, vec4 v2, vec4 dest);

CGLM_EXPORT
void
glmc_vec_scale(vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec4_scale(vec4 v, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec_scale_as(vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec4_scale_as(vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec_flipsign(vec3 v);

CGLM_EXPORT
void
glmc_vec4_flipsign(vec4 v);

CGLM_EXPORT
float
glmc_vec_angle(vec3 v1, vec3 v2)

CGLM_EXPORT
void
glmc_vec_rotate(vec3 v, float angle, vec3 axis);

CGLM_EXPORT
void
glmc_vec_rotate_m4(mat4 m, vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec_proj(vec3 a, vec3 b, vec3 dest);

CGLM_INLINE
void
glmc_vec_center(vec3 v1, vec3 v2, vec3 dest);

CGLM_EXPORT
float
glmc_vec_distance(vec3 v1, vec3 v2);

CGLM_EXPORT
float
glmc_vec4_distance(vec4 v1, vec4 v2);

#ifdef __cplusplus
}
#endif
#endif /* cglm_vec_h */
