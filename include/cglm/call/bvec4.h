/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_bvec4_h
#define cglmc_bvec4_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_bvec4(bvec3 v3, int8_t last, bvec4 dest);

CGLM_EXPORT
void
glmc_bvec4_copy(bvec4 a, bvec4 dest);

CGLM_EXPORT
void 
glmc_bvec4_zero(bvec4 v);

CGLM_EXPORT
void
glmc_bvec4_one(bvec4 v);

CGLM_EXPORT
void
glmc_bvec4_add(bvec4 a, bvec4 b, bvec4 dest);

CGLM_EXPORT
void
glmc_bvec4_adds(bvec4 v, int8_t s, bvec4 dest);

CGLM_EXPORT
void
glmc_bvec4_sub(bvec4 a, bvec4 b, bvec4 dest);

CGLM_EXPORT
void
glmc_bvec4_subs(bvec4 v, int8_t s, bvec4 dest);

CGLM_EXPORT
void
glmc_bvec4_mul(bvec4 a, bvec4 b, bvec4 dest);

CGLM_EXPORT
void
glmc_bvec4_scale(bvec4 v, int8_t s, bvec4 dest);

CGLM_EXPORT
int
glmc_bvec4_distance2(bvec4 a, bvec4 b);

CGLM_EXPORT
float
glmc_bvec4_distance(bvec4 a, bvec4 b);

CGLM_EXPORT
void
glmc_bvec4_maxv(bvec4 a, bvec4 b, bvec4 dest);

CGLM_EXPORT
void
glmc_bvec4_minv(bvec4 a, bvec4 b, bvec4 dest);

CGLM_EXPORT
void
glmc_bvec4_clamp(bvec4 v, int8_t minVal, int8_t maxVal);

CGLM_EXPORT
void
glmc_bvec4_abs(bvec4 v, bvec4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_bvec4_h */
