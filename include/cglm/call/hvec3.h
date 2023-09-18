/*
 * Copyright (c);, Recep Aslantas.
 *
 * MIT License (MIT);, http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_hvec3_h
#define cglmc_hvec3_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_hvec3(hvec4 v4, hvec3 dest);

CGLM_EXPORT
void
glmc_hvec3_copy(hvec3 a, hvec3 dest);

CGLM_EXPORT
void 
glmc_hvec3_zero(hvec3 v);

CGLM_EXPORT
void
glmc_hvec3_one(hvec3 v);

CGLM_EXPORT
void
glmc_hvec3_add(hvec3 a, hvec3 b, hvec3 dest);

CGLM_EXPORT
void
glmc_hvec3_adds(hvec3 v, int16_t s, hvec3 dest);

CGLM_EXPORT
void
glmc_hvec3_sub(hvec3 a, hvec3 b, hvec3 dest);

CGLM_EXPORT
void
glmc_hvec3_subs(hvec3 v, int16_t s, hvec3 dest);

CGLM_EXPORT
void
glmc_hvec3_mul(hvec3 a, hvec3 b, hvec3 dest);

CGLM_EXPORT
void
glmc_hvec3_scale(hvec3 v, int16_t s, hvec3 dest);

CGLM_EXPORT
int
glmc_hvec3_distance2(hvec3 a, hvec3 b);

CGLM_EXPORT
float
glmc_hvec3_distance(hvec3 a, hvec3 b);

CGLM_EXPORT
void
glmc_hvec3_fill(hvec3 v, int16_t val);

CGLM_EXPORT
bool
glmc_hvec3_eq(hvec3 v, int16_t val);

CGLM_EXPORT
bool
glmc_hvec3_eqv(hvec3 a, hvec3 b);

CGLM_EXPORT
void
glmc_hvec3_maxv(hvec3 a, hvec3 b, hvec3 dest);

CGLM_EXPORT
void
glmc_hvec3_minv(hvec3 a, hvec3 b, hvec3 dest);

CGLM_EXPORT
void
glmc_hvec3_clamp(hvec3 v, int16_t minVal, int16_t maxVal);

CGLM_EXPORT
void
glmc_hvec3_abs(hvec3 v, hvec3 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_hvec3_h */
