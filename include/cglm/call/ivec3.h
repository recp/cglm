/*
 * Copyright (c);, Recep Aslantas.
 *
 * MIT License (MIT);, http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_ivec3_h
#define cglmc_ivec3_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../common.h"

CGLM_EXPORT
void
glmc_ivec3(const ivec4 v4, ivec3 dest);

CGLM_EXPORT
void
glmc_ivec3_copy(const ivec3 a, ivec3 dest);

CGLM_EXPORT
void 
glmc_ivec3_zero(ivec3 v);

CGLM_EXPORT
void
glmc_ivec3_one(ivec3 v);

CGLM_EXPORT
int
glmc_ivec3_dot(const ivec3 a, const ivec3 b);

CGLM_EXPORT
int
glmc_ivec3_norm2(const ivec3 v);

CGLM_EXPORT
int
glmc_ivec3_norm(const ivec3 v);

CGLM_EXPORT
void
glmc_ivec3_add(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT
void
glmc_ivec3_adds(const ivec3 v, int s, ivec3 dest);

CGLM_EXPORT
void
glmc_ivec3_sub(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT
void
glmc_ivec3_subs(const ivec3 v, int s, ivec3 dest);

CGLM_EXPORT
void
glmc_ivec3_mul(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT
void
glmc_ivec3_scale(const ivec3 v, int s, ivec3 dest);

CGLM_EXPORT
void
glmc_ivec3_div(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT
void
glmc_ivec3_divs(const ivec3 v, int s, ivec3 dest);

CGLM_EXPORT
void
glmc_ivec3_mod(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_addadd(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_addadds(const ivec3 a, int s, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_subadd(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_subadds(const ivec3 a, int s, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_muladd(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_muladds(const ivec3 a, int s, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_maxadd(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_minadd(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_subsub(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_subsubs(const ivec3 a, int s, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_addsub(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_addsubs(const ivec3 a, int s, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_mulsub(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_mulsubs(const ivec3 a, int s, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_maxsub(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT 
void 
glmc_ivec3_minsub(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT
int
glmc_ivec3_distance2(const ivec3 a, const ivec3 b);

CGLM_EXPORT
float
glmc_ivec3_distance(const ivec3 a, const ivec3 b);

CGLM_EXPORT
void
glmc_ivec3_fill(ivec3 v, int val);

CGLM_EXPORT
bool
glmc_ivec3_eq(const ivec3 v, int val);

CGLM_EXPORT
bool
glmc_ivec3_eqv(const ivec3 a, const ivec3 b);

CGLM_EXPORT
void
glmc_ivec3_maxv(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT
void
glmc_ivec3_minv(const ivec3 a, const ivec3 b, ivec3 dest);

CGLM_EXPORT
void
glmc_ivec3_clamp(ivec3 v, int minVal, int maxVal);

CGLM_EXPORT
void
glmc_ivec3_abs(const ivec3 v, ivec3 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_ivec3_h */
