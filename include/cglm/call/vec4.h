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
#define glmc_vec4_dup3(v, dest)         glmc_vec4_copy3(v, dest)
#define glmc_vec4_dup(v, dest)          glmc_vec4_copy(v, dest)
#define glmc_vec4_flipsign(v)           glmc_vec4_negate(v)
#define glmc_vec4_flipsign_to(v, dest)  glmc_vec4_negate_to(v, dest)
#define glmc_vec4_inv(v)                glmc_vec4_negate(v)
#define glmc_vec4_inv_to(v, dest)       glmc_vec4_negate_to(v, dest)

CGLM_EXPORT
void
glmc_vec4(const vec3 v3, float last, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_zero(vec4 v);

CGLM_EXPORT
void
glmc_vec4_one(vec4 v);

CGLM_EXPORT
void
glmc_vec4_copy3(const vec4 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec4_copy(const vec4 v, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_ucopy(const vec4 v, vec4 dest);

CGLM_EXPORT
float
glmc_vec4_dot(const vec4 a, const vec4 b);

CGLM_EXPORT
float
glmc_vec4_norm(const vec4 v);

CGLM_EXPORT
float
glmc_vec4_norm2(const vec4 v);

CGLM_EXPORT
void
glmc_vec4_normalize_to(const vec4 v, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_normalize(vec4 v);

CGLM_EXPORT
void
glmc_vec4_add(const vec4 a, const vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_adds(const vec4 v, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_sub(const vec4 a, const vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_subs(const vec4 v, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_mul(const vec4 a, const vec4 b, vec4 d);

CGLM_EXPORT
void
glmc_vec4_scale(const vec4 v, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_scale_as(const vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec4_div(const vec4 a, const vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_divs(const vec4 v, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_addadd(const vec4 a, const vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_subadd(const vec4 a, const vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_muladd(const vec4 a, const vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_muladds(const vec4 a, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_maxadd(const vec4 a, const vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_minadd(const vec4 a, const vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_negate(vec4 v);

CGLM_EXPORT
void
glmc_vec4_negate_to(const vec4 v, vec4 dest);

CGLM_EXPORT
float
glmc_vec4_distance(const vec4 a, const vec4 b);

CGLM_EXPORT
void
glmc_vec4_maxv(const vec4 a, const vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_minv(const vec4 a, const vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_clamp(vec4 v, float minVal, float maxVal);

CGLM_EXPORT
void
glmc_vec4_lerp(const vec4 from, const vec4 to, float t, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_cubic(float s, vec4 dest);

/* ext */

CGLM_EXPORT
void
glmc_vec4_mulv(const vec4 a, const vec4 b, vec4 d);

CGLM_EXPORT
void
glmc_vec4_broadcast(float val, vec4 d);

CGLM_EXPORT
bool
glmc_vec4_eq(const vec4 v, float val);

CGLM_EXPORT
bool
glmc_vec4_eq_eps(const vec4 v, float val);

CGLM_EXPORT
bool
glmc_vec4_eq_all(const vec4 v);

CGLM_EXPORT
bool
glmc_vec4_eqv(const vec4 a, const vec4 b);

CGLM_EXPORT
bool
glmc_vec4_eqv_eps(const vec4 a, const vec4 b);

CGLM_EXPORT
float
glmc_vec4_max(const vec4 v);

CGLM_EXPORT
float
glmc_vec4_min(const vec4 v);

CGLM_EXPORT
bool
glmc_vec4_isnan(const vec4 v);

CGLM_EXPORT
bool
glmc_vec4_isinf(const vec4 v);

CGLM_EXPORT
bool
glmc_vec4_isvalid(const vec4 v);

CGLM_EXPORT
void
glmc_vec4_sign(const vec4 v, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_sqrt(const vec4 v, vec4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_vec4_h */

