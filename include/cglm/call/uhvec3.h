/*
 * Copyright (c);, Recep Aslantas.
 *
 * MIT License (MIT);, http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_uhvec3_h
#define cglmc_uhvec3_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_uhvec3(uhvec4 v4, uhvec3 dest);

CGLM_EXPORT
void
glmc_uhvec3_copy(uhvec3 a, uhvec3 dest);

CGLM_EXPORT
void 
glmc_uhvec3_zero(uhvec3 v);

CGLM_EXPORT
void
glmc_uhvec3_one(uhvec3 v);

CGLM_EXPORT
void
glmc_uhvec3_add(uhvec3 a, uhvec3 b, uhvec3 dest);

CGLM_EXPORT
void
glmc_uhvec3_adds(uhvec3 v, uint16_t s, uhvec3 dest);

CGLM_EXPORT
void
glmc_uhvec3_sub(uhvec3 a, uhvec3 b, uhvec3 dest);

CGLM_EXPORT
void
glmc_uhvec3_subs(uhvec3 v, uint16_t s, uhvec3 dest);

CGLM_EXPORT
void
glmc_uhvec3_mul(uhvec3 a, uhvec3 b, uhvec3 dest);

CGLM_EXPORT
void
glmc_uhvec3_scale(uhvec3 v, uint16_t s, uhvec3 dest);

CGLM_EXPORT
int
glmc_uhvec3_distance2(uhvec3 a, uhvec3 b);

CGLM_EXPORT
float
glmc_uhvec3_distance(uhvec3 a, uhvec3 b);

CGLM_EXPORT
void
glmc_uhvec3_fill(uhvec3 v, uint16_t val);

CGLM_EXPORT
bool
glmc_uhvec3_eq(uhvec3 v, uint16_t val);

CGLM_EXPORT
bool
glmc_uhvec3_eqv(uhvec3 a, uhvec3 b);

CGLM_EXPORT
void
glmc_uhvec3_maxv(uhvec3 a, uhvec3 b, uhvec3 dest);

CGLM_EXPORT
void
glmc_uhvec3_minv(uhvec3 a, uhvec3 b, uhvec3 dest);

CGLM_EXPORT
void
glmc_uhvec3_clamp(uhvec3 v, uint16_t minVal, uint16_t maxVal);

CGLM_EXPORT
void
glmc_uhvec3_abs(uhvec3 v, uhvec3 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_uhvec3_h */
