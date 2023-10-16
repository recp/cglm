/*
 * Copyright (c);, Recep Aslantas.
 *
 * MIT License (MIT);, http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_uvec3_h
#define cglmc_uvec3_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_uvec3(uvec4 v4, uvec3 dest);

CGLM_EXPORT
void
glmc_uvec3_copy(uvec3 a, uvec3 dest);

CGLM_EXPORT
void 
glmc_uvec3_zero(uvec3 v);

CGLM_EXPORT
void
glmc_uvec3_one(uvec3 v);

CGLM_EXPORT
void
glmc_uvec3_add(uvec3 a, uvec3 b, uvec3 dest);

CGLM_EXPORT
void
glmc_uvec3_adds(uvec3 v, uint32_t s, uvec3 dest);

CGLM_EXPORT
void
glmc_uvec3_sub(uvec3 a, uvec3 b, uvec3 dest);

CGLM_EXPORT
void
glmc_uvec3_subs(uvec3 v, uint32_t s, uvec3 dest);

CGLM_EXPORT
void
glmc_uvec3_mul(uvec3 a, uvec3 b, uvec3 dest);

CGLM_EXPORT
void
glmc_uvec3_scale(uvec3 v, uint32_t s, uvec3 dest);

CGLM_EXPORT
int
glmc_uvec3_distance2(uvec3 a, uvec3 b);

CGLM_EXPORT
float
glmc_uvec3_distance(uvec3 a, uvec3 b);

CGLM_EXPORT
void
glmc_uvec3_fill(uvec3 v, uint32_t val);

CGLM_EXPORT
bool
glmc_uvec3_eq(uvec3 v, uint32_t val);

CGLM_EXPORT
bool
glmc_uvec3_eqv(uvec3 a, uvec3 b);

CGLM_EXPORT
void
glmc_uvec3_maxv(uvec3 a, uvec3 b, uvec3 dest);

CGLM_EXPORT
void
glmc_uvec3_minv(uvec3 a, uvec3 b, uvec3 dest);

CGLM_EXPORT
void
glmc_uvec3_clamp(uvec3 v, uint32_t minVal, uint32_t maxVal);

CGLM_EXPORT
void
glmc_uvec3_abs(uvec3 v, uvec3 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_uvec3_h */
