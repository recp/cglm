/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_hvec4_h
#define cglmc_hvec4_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_hvec4(hvec3 v3, int16_t last, hvec4 dest);

CGLM_EXPORT
void
glmc_hvec4_copy(hvec4 a, hvec4 dest);

CGLM_EXPORT
void 
glmc_hvec4_zero(hvec4 v);

CGLM_EXPORT
void
glmc_hvec4_one(hvec4 v);

CGLM_EXPORT
void
glmc_hvec4_add(hvec4 a, hvec4 b, hvec4 dest);

CGLM_EXPORT
void
glmc_hvec4_adds(hvec4 v, int16_t s, hvec4 dest);

CGLM_EXPORT
void
glmc_hvec4_sub(hvec4 a, hvec4 b, hvec4 dest);

CGLM_EXPORT
void
glmc_hvec4_subs(hvec4 v, int16_t s, hvec4 dest);

CGLM_EXPORT
void
glmc_hvec4_mul(hvec4 a, hvec4 b, hvec4 dest);

CGLM_EXPORT
void
glmc_hvec4_scale(hvec4 v, int16_t s, hvec4 dest);

CGLM_EXPORT
int
glmc_hvec4_distance2(hvec4 a, hvec4 b);

CGLM_EXPORT
float
glmc_hvec4_distance(hvec4 a, hvec4 b);

CGLM_EXPORT
void
glmc_hvec4_maxv(hvec4 a, hvec4 b, hvec4 dest);

CGLM_EXPORT
void
glmc_hvec4_minv(hvec4 a, hvec4 b, hvec4 dest);

CGLM_EXPORT
void
glmc_hvec4_clamp(hvec4 v, int16_t minVal, int16_t maxVal);

CGLM_EXPORT
void
glmc_hvec4_abs(hvec4 v, hvec4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_hvec4_h */
