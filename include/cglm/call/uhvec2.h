/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_uhvec2_h
#define cglmc_uhvec2_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_uhvec2(uint16_t * __restrict v, uhvec2 dest);

CGLM_EXPORT
void
glmc_uhvec2_copy(uhvec2 a, uhvec2 dest);

CGLM_EXPORT
void
glmc_uhvec2_zero(uhvec2 v);

CGLM_EXPORT
void
glmc_uhvec2_one(uhvec2 v);

CGLM_EXPORT
void
glmc_uhvec2_add(uhvec2 a, uhvec2 b, uhvec2 dest);

CGLM_EXPORT
void
glmc_uhvec2_adds(uhvec2 v, uint16_t s, uhvec2 dest);

CGLM_EXPORT
void
glmc_uhvec2_sub(uhvec2 a, uhvec2 b, uhvec2 dest);

CGLM_EXPORT
void
glmc_uhvec2_subs(uhvec2 v, uint16_t s, uhvec2 dest);

CGLM_EXPORT
void
glmc_uhvec2_mul(uhvec2 a, uhvec2 b, uhvec2 dest);

CGLM_EXPORT
void
glmc_uhvec2_scale(uhvec2 v, uint16_t s, uhvec2 dest);

CGLM_EXPORT
int
glmc_uhvec2_distance2(uhvec2 a, uhvec2 b);

CGLM_EXPORT
float
glmc_uhvec2_distance(uhvec2 a, uhvec2 b);

CGLM_EXPORT
void
glmc_uhvec2_fill(uhvec2 v, uint16_t val);

CGLM_EXPORT
bool
glmc_uhvec2_eq(uhvec2 v, uint16_t val);

CGLM_EXPORT
bool
glmc_uhvec2_eqv(uhvec2 a, uhvec2 b);

CGLM_EXPORT
void
glmc_uhvec2_maxv(uhvec2 a, uhvec2 b, uhvec2 dest);

CGLM_EXPORT
void
glmc_uhvec2_minv(uhvec2 a, uhvec2 b, uhvec2 dest);

CGLM_EXPORT
void
glmc_uhvec2_clamp(uhvec2 v, uint16_t minVal, uint16_t maxVal);

CGLM_EXPORT
void
glmc_uhvec2_abs(uhvec2 v, uhvec2 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_uhvec2_h */
