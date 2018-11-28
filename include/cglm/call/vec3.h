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

CGLM_EXPORT
void
glmc_vec3(vec4 v4, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_copy(vec3 a, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_zero(vec3 v);

CGLM_EXPORT
void
glmc_vec3_one(vec3 v);

CGLM_EXPORT
float
glmc_vec3_dot(vec3 a, vec3 b);

CGLM_EXPORT
void
glmc_vec3_cross(vec3 a, vec3 b, vec3 d);

CGLM_EXPORT
float
glmc_vec3_norm(vec3 vec);

CGLM_EXPORT
float
glmc_vec3_norm2(vec3 vec);

CGLM_EXPORT
void
glmc_vec3_normalize_to(vec3 vec, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_normalize(vec3 v);

CGLM_EXPORT
void
glmc_vec3_add(vec3 v1, vec3 v2, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_adds(vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_sub(vec3 a, vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_subs(vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_mul(vec3 a, vec3 b, vec3 d);

CGLM_EXPORT
void
glmc_vec3_scale(vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_scale_as(vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_div(vec3 a, vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_divs(vec3 a, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_addadd(vec3 a, vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_subadd(vec3 a, vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_muladd(vec3 a, vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_muladds(vec3 a, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_flipsign(vec3 v);

CGLM_EXPORT
void
glmc_vec3_flipsign_to(vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_negate(vec3 v);

CGLM_EXPORT
void
glmc_vec3_negate_to(vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_inv(vec3 v);

CGLM_EXPORT
void
glmc_vec3_inv_to(vec3 v, vec3 dest);
  
CGLM_EXPORT
float
glmc_vec3_angle(vec3 v1, vec3 v2);

CGLM_EXPORT
void
glmc_vec3_rotate(vec3 v, float angle, vec3 axis);

CGLM_EXPORT
void
glmc_vec3_rotate_m4(mat4 m, vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_rotate_m3(mat3 m, vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_proj(vec3 a, vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_center(vec3 v1, vec3 v2, vec3 dest);

CGLM_EXPORT
float
glmc_vec3_distance2(vec3 v1, vec3 v2);

CGLM_EXPORT
float
glmc_vec3_distance(vec3 v1, vec3 v2);

CGLM_EXPORT
void
glmc_vec3_maxv(vec3 v1, vec3 v2, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_minv(vec3 v1, vec3 v2, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_clamp(vec3 v, float minVal, float maxVal);

CGLM_EXPORT
void
glmc_vec3_ortho(vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_lerp(vec3 from, vec3 to, float t, vec3 dest);

/* ext */

CGLM_EXPORT
void
glmc_vec3_mulv(vec3 a, vec3 b, vec3 d);

CGLM_EXPORT
void
glmc_vec3_broadcast(float val, vec3 d);

CGLM_EXPORT
bool
glmc_vec3_eq(vec3 v, float val);

CGLM_EXPORT
bool
glmc_vec3_eq_eps(vec3 v, float val);

CGLM_EXPORT
bool
glmc_vec3_eq_all(vec3 v);

CGLM_EXPORT
bool
glmc_vec3_eqv(vec3 v1, vec3 v2);

CGLM_EXPORT
bool
glmc_vec3_eqv_eps(vec3 v1, vec3 v2);

CGLM_EXPORT
float
glmc_vec3_max(vec3 v);

CGLM_EXPORT
float
glmc_vec3_min(vec3 v);

CGLM_EXPORT
bool
glmc_vec3_isnan(vec3 v);

CGLM_EXPORT
bool
glmc_vec3_isinf(vec3 v);

CGLM_EXPORT
bool
glmc_vec3_isvalid(vec3 v);

CGLM_EXPORT
void
glmc_vec3_sign(vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_sqrt(vec3 v, vec3 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_vec3_h */
