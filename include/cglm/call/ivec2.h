/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_ivec2_h
#define cglmc_ivec2_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_ivec2(int * __restrict v, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_copy(ivec2 a, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_zero(ivec2 v);

CGLM_EXPORT
void
glmc_ivec2_one(ivec2 v);

CGLM_EXPORT
int
glmc_ivec2_dot(ivec2 a, ivec2 b);

CGLM_EXPORT
int
glmc_ivec2_cross(ivec2 a, ivec2 b);

CGLM_EXPORT
void
glmc_ivec2_add(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_adds(ivec2 v, int s, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_sub(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_subs(ivec2 v, int s, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_mul(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_scale(ivec2 v, int s, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_div(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_divs(ivec2 v, int s, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_mod(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_addadd(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_addadds(ivec2 a, int s, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_subadd(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_subadds(ivec2 a, int s, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_muladd(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_muladds(ivec2 a, int s, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_maxadd(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_minadd(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_subsub(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_subsubs(ivec2 a, int s, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_addsub(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_addsubs(ivec2 a, int s, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_mulsub(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_mulsubs(ivec2 a, int s, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_maxsub(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_minsub(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT
int
glmc_ivec2_distance2(ivec2 a, ivec2 b);

CGLM_EXPORT
float
glmc_ivec2_distance(ivec2 a, ivec2 b);

CGLM_EXPORT
void
glmc_ivec2_fill(ivec2 v, int val);

CGLM_EXPORT
bool
glmc_ivec2_eq(ivec2 v, int val);

CGLM_EXPORT
bool
glmc_ivec2_eqv(ivec2 a, ivec2 b);

CGLM_EXPORT
void
glmc_ivec2_maxv(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_minv(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_clamp(ivec2 v, int minVal, int maxVal);

CGLM_EXPORT
void
glmc_ivec2_abs(ivec2 v, ivec2 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_ivec2_h */
