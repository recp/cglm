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
#define glmc_vec_dup(v, dest)          glmc_vec3_copy(v, dest)
#define glmc_vec3_flipsign(v)          glmc_vec3_negate(v)
#define glmc_vec3_flipsign_to(v, dest) glmc_vec3_negate_to(v, dest)
#define glmc_vec3_inv(v)               glmc_vec3_negate(v)
#define glmc_vec3_inv_to(v, dest)      glmc_vec3_negate_to(v, dest)

CGLM_EXPORT
void
glmc_vec3(const vec4 v4, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_copy(const vec3 a, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_zero(vec3 v);

CGLM_EXPORT
void
glmc_vec3_one(vec3 v);

CGLM_EXPORT
float
glmc_vec3_dot(const vec3 a, const vec3 b);

CGLM_EXPORT
void
glmc_vec3_cross(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_crossn(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
float
glmc_vec3_norm(const vec3 v);

CGLM_EXPORT
float
glmc_vec3_norm2(const vec3 v);

CGLM_EXPORT
void
glmc_vec3_normalize_to(const vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_normalize(vec3 v);

CGLM_EXPORT
void
glmc_vec3_add(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_adds(const vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_sub(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_subs(const vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_mul(const vec3 a, const vec3 b, vec3 d);

CGLM_EXPORT
void
glmc_vec3_scale(const vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_scale_as(const vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_div(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_divs(const vec3 a, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_addadd(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_subadd(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_muladd(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_muladds(const vec3 a, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_maxadd(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_minadd(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_negate(vec3 v);

CGLM_EXPORT
void
glmc_vec3_negate_to(const vec3 v, vec3 dest);

CGLM_EXPORT
float
glmc_vec3_angle(const vec3 a, const vec3 b);

CGLM_EXPORT
void
glmc_vec3_rotate(vec3 v, float angle, const vec3 axis);

CGLM_EXPORT
void
glmc_vec3_rotate_m4(const mat4 m, const vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_rotate_m3(const mat3 m, const vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_proj(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_center(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
float
glmc_vec3_distance2(const vec3 a, const vec3 b);

CGLM_EXPORT
float
glmc_vec3_distance(const vec3 a, const vec3 b);

CGLM_EXPORT
void
glmc_vec3_maxv(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_minv(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_clamp(vec3 v, float minVal, float maxVal);

CGLM_EXPORT
void
glmc_vec3_ortho(const vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_lerp(const vec3 from, const vec3 to, float t, vec3 dest);

/* ext */

CGLM_EXPORT
void
glmc_vec3_mulv(const vec3 a, const vec3 b, vec3 d);

CGLM_EXPORT
void
glmc_vec3_broadcast(float val, vec3 d);

CGLM_EXPORT
bool
glmc_vec3_eq(const vec3 v, float val);

CGLM_EXPORT
bool
glmc_vec3_eq_eps(const vec3 v, float val);

CGLM_EXPORT
bool
glmc_vec3_eq_all(const vec3 v);

CGLM_EXPORT
bool
glmc_vec3_eqv(const vec3 a, const vec3 b);

CGLM_EXPORT
bool
glmc_vec3_eqv_eps(const vec3 a, const vec3 b);

CGLM_EXPORT
float
glmc_vec3_max(const vec3 v);

CGLM_EXPORT
float
glmc_vec3_min(const vec3 v);

CGLM_EXPORT
bool
glmc_vec3_isnan(const vec3 v);

CGLM_EXPORT
bool
glmc_vec3_isinf(const vec3 v);

CGLM_EXPORT
bool
glmc_vec3_isvalid(const vec3 v);

CGLM_EXPORT
void
glmc_vec3_sign(const vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_sqrt(const vec3 v, vec3 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_vec3_h */
