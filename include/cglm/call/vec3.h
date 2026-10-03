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

#include "../common.h"

/* DEPRECATED! use _copy, _ucopy versions */
#define glmc_vec_dup(v, dest)          glmc_vec3_copy(v, dest)
#define glmc_vec3_flipsign(v)          glmc_vec3_negate(v)
#define glmc_vec3_flipsign_to(v, dest) glmc_vec3_negate_to(v, dest)
#define glmc_vec3_inv(v)               glmc_vec3_negate(v)
#define glmc_vec3_inv_to(v, dest)      glmc_vec3_negate_to(v, dest)
#define glmc_vec3_step_uni(edge, x, dest) glmc_vec3_steps(edge, x, dest);

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
float
glmc_vec3_norm_one(const vec3 v);

CGLM_EXPORT
float
glmc_vec3_norm_inf(const vec3 v);

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
glmc_vec3_subsub(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_addsub(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_mulsub(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_mulsubs(const vec3 a, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_maxsub(const vec3 a, const vec3 b, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_minsub(const vec3 a, const vec3 b, vec3 dest);

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
glmc_vec3_rotate_m4(CGLM_CONST mat4 m, const vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_rotate_m3(CGLM_CONST mat3 m, const vec3 v, vec3 dest);

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

CGLM_EXPORT
void
glmc_vec3_lerpc(const vec3 from, const vec3 to, float t, vec3 dest);

CGLM_INLINE
void
glmc_vec3_mix(const vec3 from, const vec3 to, float t, vec3 dest) {
  glmc_vec3_lerp(from, to, t, dest);
}

CGLM_INLINE
void
glmc_vec3_mixc(const vec3 from, const vec3 to, float t, vec3 dest) {
  glmc_vec3_lerpc(from, to, t, dest);
}

CGLM_EXPORT
void
glmc_vec3_step(const vec3 edge, const vec3 x, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_smoothstep_uni(float edge0, float edge1, const vec3 x, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_smoothstep(const vec3 edge0, const vec3 edge1, const vec3 x, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_smoothinterp(const vec3 from, const vec3 to, float t, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_smoothinterpc(const vec3 from, const vec3 to, float t, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_swizzle(const vec3 v, int mask, vec3 dest);

/* ext */

CGLM_EXPORT
void
glmc_vec3_mulv(vec3 a, vec3 b, vec3 d);

CGLM_EXPORT
void
glmc_vec3_broadcast(float val, vec3 d);

CGLM_EXPORT
void
glmc_vec3_fill(vec3 v, float val);

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
glmc_vec3_abs(const vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_fract(const vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_floor(const vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_mods(const vec3 v, float s, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_steps(float edge, const vec3 x, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_stepr(const vec3 edge, float x, vec3 dest);

CGLM_EXPORT
float
glmc_vec3_hadd(const vec3 v);

CGLM_EXPORT
void
glmc_vec3_sqrt(const vec3 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_make(const float * __restrict src, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_faceforward(const vec3 n, const vec3 v, const vec3 nref, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_reflect(const vec3 v, const vec3 n, vec3 dest);

CGLM_EXPORT
bool
glmc_vec3_refract(const vec3 v, const vec3 n, float eta, vec3 dest);

CGLM_EXPORT
void
glmc_vec3_swap(vec3 a, vec3 b);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_vec3_h */
