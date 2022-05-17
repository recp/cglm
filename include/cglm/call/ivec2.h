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
int
glmc_ivec2_distance2(ivec2 a, ivec2 b);

CGLM_EXPORT
float
glmc_ivec2_distance(ivec2 a, ivec2 b);

CGLM_EXPORT
void
glmc_ivec2_maxv(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_minv(ivec2 a, ivec2 b, ivec2 dest);

CGLM_EXPORT
void
glmc_ivec2_clamp(ivec2 v, int minVal, int maxVal);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_ivec2_h */
