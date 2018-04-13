/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_vec3_h
#define cglmc_vec3_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

/* DEPRECATED! use _copy, _ucopy versions */
#define glmc_vec_dup(v, dest) glmc_vec_copy(v, dest)

CGLM_EXPORT
void
glmc_vec3(vec4 v4, vec3 dest);

CGLM_EXPORT
void
glmc_vec_copy(vec3 a, vec3 dest);

CGLM_EXPORT
void
glmc_vec_zero(vec3 v);

CGLM_EXPORT
void
glmc_vec_one(vec3 v);

CGLM_EXPORT
float
glmc_vec_dot(vec3 a, vec3 b);

CGLM_EXPORT
void
glmc_vec_cross(vec3 a, vec3 b, vec3 d);

CGLM_EXPORT
float
glmc_vec_norm(vec3 vec);

CGLM_EXPORT
float
glmc_vec_norm2(vec3 vec);

CGLM_EXPORT
void
glmc_vec_normalize_to(vec3 vec, vec3 dest);

CGLM_EXPORT
void
glmc_vec_normalize(vec3 v);

CGLM_EXPORT
void
glmc_vec_add(vec3 v1, vec3 v2, vec3 dest);

CGLM_EXPORT
void
glmc_vec_sub(vec3 v1, vec3 v2, vec3 dest);

CGLM_EXPORT
void
glmc_vec_scale(vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec_scale_as(vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec_flipsign(vec3 v);

CGLM_EXPORT
void
glmc_vec_flipsign_to(vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec_inv(vec3 v);

CGLM_EXPORT
void
glmc_vec_inv_to(vec3 v, vec3 dest);
  
CGLM_EXPORT
float
glmc_vec_angle(vec3 v1, vec3 v2);

CGLM_EXPORT
void
glmc_vec_rotate(vec3 v, float angle, vec3 axis);

CGLM_EXPORT
void
glmc_vec_rotate_m4(mat4 m, vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec_proj(vec3 a, vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec_center(vec3 v1, vec3 v2, vec3 dest);

CGLM_EXPORT
float
glmc_vec_distance(vec3 v1, vec3 v2);

CGLM_EXPORT
void
glmc_vec_maxv(vec3 v1, vec3 v2, vec3 dest);

CGLM_EXPORT
void
glmc_vec_minv(vec3 v1, vec3 v2, vec3 dest);

CGLM_EXPORT
void
glmc_vec_clamp(vec3 v, float minVal, float maxVal);

CGLM_EXPORT
void
glmc_vec_ortho(vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec_lerp(vec3 from, vec3 to, float t, vec3 dest);

/* ext */

CGLM_EXPORT
void
glmc_vec_mulv(vec3 a, vec3 b, vec3 d);

CGLM_EXPORT
void
glmc_vec_broadcast(float val, vec3 d);

CGLM_EXPORT
bool
glmc_vec_eq(vec3 v, float val);

CGLM_EXPORT
bool
glmc_vec_eq_eps(vec3 v, float val);

CGLM_EXPORT
bool
glmc_vec_eq_all(vec3 v);

CGLM_EXPORT
bool
glmc_vec_eqv(vec3 v1, vec3 v2);

CGLM_EXPORT
bool
glmc_vec_eqv_eps(vec3 v1, vec3 v2);

CGLM_EXPORT
float
glmc_vec_max(vec3 v);

CGLM_EXPORT
float
glmc_vec_min(vec3 v);

CGLM_EXPORT
bool
glmc_vec_isnan(vec3 v);

CGLM_EXPORT
bool
glmc_vec_isinf(vec3 v);

CGLM_EXPORT
bool
glmc_vec_isvalid(vec3 v);

CGLM_EXPORT
void
glmc_vec_sign(vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec_sqrt(vec3 v, vec3 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_vec3_h */
