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

#include "../common.h"

CGLM_EXPORT
void
glmc_ivec2(const int * __restrict v, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_copy(const ivec2 a, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_zero(ivec2 v);

CGLM_EXPORT
void
glmc_ivec2_one(ivec2 v);

CGLM_EXPORT
int
glmc_ivec2_dot(const ivec2 a, const ivec2 b);

CGLM_EXPORT
int
glmc_ivec2_cross(const ivec2 a, const ivec2 b);

CGLM_EXPORT
void
glmc_ivec2_add(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_adds(const ivec2 v, int s, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_sub(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_subs(const ivec2 v, int s, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_mul(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_scale(const ivec2 v, int s, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_div(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_divs(const ivec2 v, int s, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_mod(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_addadd(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_addadds(const ivec2 a, int s, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_subadd(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_subadds(const ivec2 a, int s, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_muladd(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_muladds(const ivec2 a, int s, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_maxadd(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_minadd(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_subsub(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_subsubs(const ivec2 a, int s, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_addsub(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_addsubs(const ivec2 a, int s, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_mulsub(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_mulsubs(const ivec2 a, int s, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_maxsub(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT 
void 
glmc_ivec2_minsub(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT
int
glmc_ivec2_distance2(const ivec2 a, const ivec2 b);

CGLM_EXPORT
float
glmc_ivec2_distance(const ivec2 a, const ivec2 b);

CGLM_EXPORT
void
glmc_ivec2_fill(ivec2 v, int val);

CGLM_EXPORT
bool
glmc_ivec2_eq(const ivec2 v, int val);

CGLM_EXPORT
bool
glmc_ivec2_eqv(const ivec2 a, const ivec2 b);

CGLM_EXPORT
void
glmc_ivec2_maxv(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_minv(const ivec2 a, const ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_clamp(ivec2 v, int minVal, int maxVal);

CGLM_EXPORT
void
glmc_ivec2_abs(const ivec2 v, ivec2 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_ivec2_h */
