/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_vec2_h
#define cglmc_vec2_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../common.h"

CGLM_EXPORT
void
glmc_vec2(const float * __restrict v, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_fill(vec2 v, float val);

CGLM_EXPORT
bool
glmc_vec2_eq(const vec2 v, float val);

CGLM_EXPORT
bool
glmc_vec2_eqv(const vec2 a, const vec2 b);

CGLM_EXPORT
void
glmc_vec2_copy(const vec2 a, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_zero(vec2 v);

CGLM_EXPORT
void
glmc_vec2_one(vec2 v);

CGLM_EXPORT
float
glmc_vec2_dot(const vec2 a, const vec2 b);

CGLM_EXPORT
float
glmc_vec2_cross(const vec2 a, const vec2 b);

CGLM_EXPORT
float
glmc_vec2_norm2(const vec2 v);

CGLM_EXPORT
float
glmc_vec2_norm(const vec2 v);

CGLM_EXPORT
void
glmc_vec2_add(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_adds(const vec2 v, float s, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_sub(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_subs(const vec2 v, float s, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_mul(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_scale(const vec2 v, float s, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_scale_as(const vec2 v, float s, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_div(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_divs(const vec2 v, float s, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_addadd(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_subadd(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_muladd(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_muladds(const vec2 a, float s, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_maxadd(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_minadd(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_subsub(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_addsub(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_mulsub(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_mulsubs(const vec2 a, float s, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_maxsub(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_minsub(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_negate_to(const vec2 v, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_negate(vec2 v);

CGLM_EXPORT
void
glmc_vec2_normalize(vec2 v);

CGLM_EXPORT
void
glmc_vec2_normalize_to(const vec2 v, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_rotate(const vec2 v, float angle, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_center(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
float
glmc_vec2_distance2(const vec2 a, const vec2 b);

CGLM_EXPORT
float
glmc_vec2_distance(const vec2 a, const vec2 b);

CGLM_EXPORT
void
glmc_vec2_maxv(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_minv(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_clamp(vec2 v, float minval, float maxval);

CGLM_EXPORT
void
glmc_vec2_abs(const vec2 v, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_fract(const vec2 v, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_floor(const vec2 v, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_mods(const vec2 v, float s, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_swizzle(const vec2 v, int mask, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_lerp(const vec2 from, const vec2 to, float t, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_step(const vec2 edge, const vec2 x, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_steps(float edge, const vec2 x, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_stepr(const vec2 edge, float x, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_complex_mul(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_complex_div(const vec2 a, const vec2 b, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_complex_conjugate(const vec2 a, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_make(const float * __restrict src, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_reflect(const vec2 v, const vec2 n, vec2 dest);

CGLM_EXPORT
bool
glmc_vec2_refract(const vec2 v, const vec2 n, float eta, vec2 dest);

CGLM_EXPORT
void
glmc_vec2_swap(vec2 a, vec2 b);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_vec2_h */
