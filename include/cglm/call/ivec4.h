/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_ivec4_h
#define cglmc_ivec4_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_ivec4(ivec3 v3, int last, ivec4 dest);

CGLM_EXPORT
void
glmc_ivec4_copy(ivec4 a, ivec4 dest);

CGLM_EXPORT
void 
glmc_ivec4_zero(ivec4 v);

CGLM_EXPORT
void
glmc_ivec4_one(ivec4 v);

CGLM_EXPORT
void
glmc_ivec4_add(ivec4 a, ivec4 b, ivec4 dest);

CGLM_EXPORT
void
glmc_ivec4_adds(ivec4 v, int s, ivec4 dest);

CGLM_EXPORT
void
glmc_ivec4_sub(ivec4 a, ivec4 b, ivec4 dest);

CGLM_EXPORT
void
glmc_ivec4_subs(ivec4 v, int s, ivec4 dest);

CGLM_EXPORT
void
glmc_ivec4_mul(ivec4 a, ivec4 b, ivec4 dest);

CGLM_EXPORT
void
glmc_ivec4_scale(ivec4 v, int s, ivec4 dest);

CGLM_EXPORT
int
glmc_ivec4_distance2(ivec4 a, ivec4 b);

CGLM_EXPORT
float
glmc_ivec4_distance(ivec4 a, ivec4 b);

CGLM_EXPORT
void
glmc_ivec4_maxv(ivec4 a, ivec4 b, ivec4 dest);

CGLM_EXPORT
void
glmc_ivec4_minv(ivec4 a, ivec4 b, ivec4 dest);

CGLM_EXPORT
void
glmc_ivec4_clamp(ivec4 v, int minVal, int maxVal);

CGLM_EXPORT
void
glmc_ivec4_abs(ivec4 v, ivec4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_ivec4_h */
