/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_ubvec2_h
#define cglmc_ubvec2_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_ubvec2(uint8_t * __restrict v, ubvec2 dest);

CGLM_EXPORT
void
glmc_ubvec2_copy(ubvec2 a, ubvec2 dest);

CGLM_EXPORT
void
glmc_ubvec2_zero(ubvec2 v);

CGLM_EXPORT
void
glmc_ubvec2_one(ubvec2 v);

CGLM_EXPORT
void
glmc_ubvec2_add(ubvec2 a, ubvec2 b, ubvec2 dest);

CGLM_EXPORT
void
glmc_ubvec2_adds(ubvec2 v, uint8_t s, ubvec2 dest);

CGLM_EXPORT
void
glmc_ubvec2_sub(ubvec2 a, ubvec2 b, ubvec2 dest);

CGLM_EXPORT
void
glmc_ubvec2_subs(ubvec2 v, uint8_t s, ubvec2 dest);

CGLM_EXPORT
void
glmc_ubvec2_mul(ubvec2 a, ubvec2 b, ubvec2 dest);

CGLM_EXPORT
void
glmc_ubvec2_scale(ubvec2 v, uint8_t s, ubvec2 dest);

CGLM_EXPORT
int
glmc_ubvec2_distance2(ubvec2 a, ubvec2 b);

CGLM_EXPORT
float
glmc_ubvec2_distance(ubvec2 a, ubvec2 b);

CGLM_EXPORT
void
glmc_ubvec2_fill(ubvec2 v, uint8_t val);

CGLM_EXPORT
bool
glmc_ubvec2_eq(ubvec2 v, uint8_t val);

CGLM_EXPORT
bool
glmc_ubvec2_eqv(ubvec2 a, ubvec2 b);

CGLM_EXPORT
void
glmc_ubvec2_maxv(ubvec2 a, ubvec2 b, ubvec2 dest);

CGLM_EXPORT
void
glmc_ubvec2_minv(ubvec2 a, ubvec2 b, ubvec2 dest);

CGLM_EXPORT
void
glmc_ubvec2_clamp(ubvec2 v, uint8_t minVal, uint8_t maxVal);

CGLM_EXPORT
void
glmc_ubvec2_abs(ubvec2 v, ubvec2 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_ubvec2_h */
