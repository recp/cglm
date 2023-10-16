/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_ubvec4_h
#define cglmc_ubvec4_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_ubvec4(ubvec3 v3, uint8_t last, ubvec4 dest);

CGLM_EXPORT
void
glmc_ubvec4_copy(ubvec4 a, ubvec4 dest);

CGLM_EXPORT
void 
glmc_ubvec4_zero(ubvec4 v);

CGLM_EXPORT
void
glmc_ubvec4_one(ubvec4 v);

CGLM_EXPORT
void
glmc_ubvec4_add(ubvec4 a, ubvec4 b, ubvec4 dest);

CGLM_EXPORT
void
glmc_ubvec4_adds(ubvec4 v, uint8_t s, ubvec4 dest);

CGLM_EXPORT
void
glmc_ubvec4_sub(ubvec4 a, ubvec4 b, ubvec4 dest);

CGLM_EXPORT
void
glmc_ubvec4_subs(ubvec4 v, uint8_t s, ubvec4 dest);

CGLM_EXPORT
void
glmc_ubvec4_mul(ubvec4 a, ubvec4 b, ubvec4 dest);

CGLM_EXPORT
void
glmc_ubvec4_scale(ubvec4 v, uint8_t s, ubvec4 dest);

CGLM_EXPORT
int
glmc_ubvec4_distance2(ubvec4 a, ubvec4 b);

CGLM_EXPORT
float
glmc_ubvec4_distance(ubvec4 a, ubvec4 b);

CGLM_EXPORT
void
glmc_ubvec4_maxv(ubvec4 a, ubvec4 b, ubvec4 dest);

CGLM_EXPORT
void
glmc_ubvec4_minv(ubvec4 a, ubvec4 b, ubvec4 dest);

CGLM_EXPORT
void
glmc_ubvec4_clamp(ubvec4 v, uint8_t minVal, uint8_t maxVal);

CGLM_EXPORT
void
glmc_ubvec4_abs(ubvec4 v, ubvec4 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_ubvec4_h */
