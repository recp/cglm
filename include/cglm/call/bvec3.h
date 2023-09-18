/*
 * Copyright (c);, Recep Aslantas.
 *
 * MIT License (MIT);, http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_bvec3_h
#define cglmc_bvec3_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_bvec3(bvec4 v4, bvec3 dest);

CGLM_EXPORT
void
glmc_bvec3_copy(bvec3 a, bvec3 dest);

CGLM_EXPORT
void 
glmc_bvec3_zero(bvec3 v);

CGLM_EXPORT
void
glmc_bvec3_one(bvec3 v);

CGLM_EXPORT
void
glmc_bvec3_add(bvec3 a, bvec3 b, bvec3 dest);

CGLM_EXPORT
void
glmc_bvec3_adds(bvec3 v, int8_t s, bvec3 dest);

CGLM_EXPORT
void
glmc_bvec3_sub(bvec3 a, bvec3 b, bvec3 dest);

CGLM_EXPORT
void
glmc_bvec3_subs(bvec3 v, int8_t s, bvec3 dest);

CGLM_EXPORT
void
glmc_bvec3_mul(bvec3 a, bvec3 b, bvec3 dest);

CGLM_EXPORT
void
glmc_bvec3_scale(bvec3 v, int8_t s, bvec3 dest);

CGLM_EXPORT
int
glmc_bvec3_distance2(bvec3 a, bvec3 b);

CGLM_EXPORT
float
glmc_bvec3_distance(bvec3 a, bvec3 b);

CGLM_EXPORT
void
glmc_bvec3_fill(bvec3 v, int8_t val);

CGLM_EXPORT
bool
glmc_bvec3_eq(bvec3 v, int8_t val);

CGLM_EXPORT
bool
glmc_bvec3_eqv(bvec3 a, bvec3 b);

CGLM_EXPORT
void
glmc_bvec3_maxv(bvec3 a, bvec3 b, bvec3 dest);

CGLM_EXPORT
void
glmc_bvec3_minv(bvec3 a, bvec3 b, bvec3 dest);

CGLM_EXPORT
void
glmc_bvec3_clamp(bvec3 v, int8_t minVal, int8_t maxVal);

CGLM_EXPORT
void
glmc_bvec3_abs(bvec3 v, bvec3 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_bvec3_h */
