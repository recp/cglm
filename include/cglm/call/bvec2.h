/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_bvec2_h
#define cglmc_bvec2_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_bvec2(int8_t * __restrict v, bvec2 dest);

CGLM_EXPORT
void
glmc_bvec2_copy(bvec2 a, bvec2 dest);

CGLM_EXPORT
void
glmc_bvec2_zero(bvec2 v);

CGLM_EXPORT
void
glmc_bvec2_one(bvec2 v);

CGLM_EXPORT
void
glmc_bvec2_add(bvec2 a, bvec2 b, bvec2 dest);

CGLM_EXPORT
void
glmc_bvec2_adds(bvec2 v, int8_t s, bvec2 dest);

CGLM_EXPORT
void
glmc_bvec2_sub(bvec2 a, bvec2 b, bvec2 dest);

CGLM_EXPORT
void
glmc_bvec2_subs(bvec2 v, int8_t s, bvec2 dest);

CGLM_EXPORT
void
glmc_bvec2_mul(bvec2 a, bvec2 b, bvec2 dest);

CGLM_EXPORT
void
glmc_bvec2_scale(bvec2 v, int8_t s, bvec2 dest);

CGLM_EXPORT
int
glmc_bvec2_distance2(bvec2 a, bvec2 b);

CGLM_EXPORT
float
glmc_bvec2_distance(bvec2 a, bvec2 b);

CGLM_EXPORT
void
glmc_bvec2_fill(bvec2 v, int8_t val);

CGLM_EXPORT
bool
glmc_bvec2_eq(bvec2 v, int8_t val);

CGLM_EXPORT
bool
glmc_bvec2_eqv(bvec2 a, bvec2 b);

CGLM_EXPORT
void
glmc_bvec2_maxv(bvec2 a, bvec2 b, bvec2 dest);

CGLM_EXPORT
void
glmc_bvec2_minv(bvec2 a, bvec2 b, bvec2 dest);

CGLM_EXPORT
void
glmc_bvec2_clamp(bvec2 v, int8_t minVal, int8_t maxVal);

CGLM_EXPORT
void
glmc_bvec2_abs(bvec2 v, bvec2 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_bvec2_h */
