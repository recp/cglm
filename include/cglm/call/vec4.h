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
glmc_vec4(vec3 v3, float last, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_zero(vec4 v);

CGLM_EXPORT
void
glmc_vec4_one(vec4 v);

CGLM_EXPORT
void
glmc_vec4_copy3(vec4 v, vec3 dest);

CGLM_EXPORT
void
glmc_vec4_copy(vec4 v, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_ucopy(vec4 v, vec4 dest);

CGLM_EXPORT
float
glmc_vec4_dot(vec4 a, vec4 b);

CGLM_EXPORT
float
glmc_vec4_norm(vec4 v);

CGLM_EXPORT
float
glmc_vec4_norm2(vec4 v);
    
CGLM_EXPORT
float
glmc_vec4_norm_one(vec4 v);

CGLM_EXPORT
float
glmc_vec4_norm_inf(vec4 v);

CGLM_EXPORT
void
glmc_vec4_normalize_to(vec4 v, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_normalize(vec4 v);

CGLM_EXPORT
void
glmc_vec4_add(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_adds(vec4 v, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_sub(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_subs(vec4 v, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_mul(vec4 a, vec4 b, vec4 d);

CGLM_EXPORT
void
glmc_vec4_scale(vec4 v, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_scale_as(vec4 v, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_div(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_divs(vec4 v, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_addadd(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_subadd(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_muladd(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_muladds(vec4 a, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_maxadd(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_minadd(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_subsub(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_addsub(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_mulsub(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_mulsubs(vec4 a, float s, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_maxsub(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_minsub(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_negate(vec4 v);

CGLM_EXPORT
void
glmc_vec4_negate_to(vec4 v, vec4 dest);
    
CGLM_EXPORT
float
glmc_vec4_distance(vec4 a, vec4 b);
    
CGLM_EXPORT
float
glmc_vec4_distance2(vec4 a, vec4 b);

CGLM_EXPORT
void
glmc_vec4_maxv(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_minv(vec4 a, vec4 b, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_clamp(vec4 v, float minVal, float maxVal);
    
CGLM_EXPORT
void
glmc_vec4_lerp(vec4 from, vec4 to, float t, vec4 dest);
    
CGLM_EXPORT
void
glmc_vec4_lerpc(vec4 from, vec4 to, float t, vec4 dest);
    
CGLM_INLINE
void
glmc_vec4_mix(vec4 from, vec4 to, float t, vec4 dest) {
  glmc_vec4_lerp(from, to, t, dest);
}

CGLM_INLINE
void
glmc_vec4_mixc(vec4 from, vec4 to, float t, vec4 dest) {
  glmc_vec4_lerpc(from, to, t, dest);
}
    
CGLM_EXPORT
void
glmc_vec4_step_uni(float edge, vec4 x, vec4 dest);
    
CGLM_EXPORT
void
glmc_vec4_step(vec4 edge, vec4 x, vec4 dest);
    
CGLM_EXPORT
void
glmc_vec4_smoothstep_uni(float edge0, float edge1, vec4 x, vec4 dest);
    
CGLM_EXPORT
void
glmc_vec4_smoothstep(vec4 edge0, vec4 edge1, vec4 x, vec4 dest);
    
CGLM_EXPORT
void
glmc_vec4_smoothinterp(vec4 from, vec4 to, float t, vec4 dest);
    
CGLM_EXPORT
void
glmc_vec4_smoothinterpc(vec4 from, vec4 to, float t, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_cubic(float s, vec4 dest);

/* ext */

CGLM_EXPORT
void
glmc_vec4_mulv(vec4 a, vec4 b, vec4 d);

CGLM_EXPORT
void
glmc_vec4_broadcast(float val, vec4 d);
    
CGLM_EXPORT
void
glmc_vec4_fill(vec4 v, float val);

CGLM_EXPORT
bool
glmc_vec4_eq(vec4 v, float val);

CGLM_EXPORT
bool
glmc_vec4_eq_eps(vec4 v, float val);

CGLM_EXPORT
bool
glmc_vec4_eq_all(vec4 v);

CGLM_EXPORT
bool
glmc_vec4_eqv(vec4 a, vec4 b);

CGLM_EXPORT
bool
glmc_vec4_eqv_eps(vec4 a, vec4 b);

CGLM_EXPORT
float
glmc_vec4_max(vec4 v);

CGLM_EXPORT
float
glmc_vec4_min(vec4 v);

CGLM_EXPORT
bool
glmc_vec4_isnan(vec4 v);

CGLM_EXPORT
bool
glmc_vec4_isinf(vec4 v);

CGLM_EXPORT
bool
glmc_vec4_isvalid(vec4 v);

CGLM_EXPORT
void
glmc_vec4_sign(vec4 v, vec4 dest);
    
CGLM_EXPORT
void
glmc_vec4_abs(vec4 v, vec4 dest);
    
CGLM_EXPORT
void
glmc_vec4_fract(vec4 v, vec4 dest);
    
CGLM_EXPORT
float
glmc_vec4_hadd(vec4 v);

CGLM_EXPORT
void
glmc_vec4_sqrt(vec4 v, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_make(const float * __restrict src, vec4 dest);

CGLM_EXPORT
void
glmc_vec4_reflect(vec4 v, vec4 n, vec4 dest);

CGLM_EXPORT
bool
glmc_vec4_refract(vec4 v, vec4 n, float eta, vec4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_vec4_h */

