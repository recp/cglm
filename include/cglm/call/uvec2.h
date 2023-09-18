/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_uvec2_h
#define cglmc_uvec2_h
#ifdef __cplusplus
extern "C" {
#endif

#include "../cglm.h"

CGLM_EXPORT
void
glmc_uvec2(uint32_t * __restrict v, uvec2 dest);

CGLM_EXPORT
void
glmc_uvec2_copy(uvec2 a, uvec2 dest);

CGLM_EXPORT
void
glmc_uvec2_zero(uvec2 v);

CGLM_EXPORT
void
glmc_uvec2_one(uvec2 v);

CGLM_EXPORT
void
glmc_uvec2_add(uvec2 a, uvec2 b, uvec2 dest);

CGLM_EXPORT
void
glmc_uvec2_adds(uvec2 v, uint32_t s, uvec2 dest);

CGLM_EXPORT
void
glmc_uvec2_sub(uvec2 a, uvec2 b, uvec2 dest);

CGLM_EXPORT
void
glmc_uvec2_subs(uvec2 v, uint32_t s, uvec2 dest);

CGLM_EXPORT
void
glmc_uvec2_mul(uvec2 a, uvec2 b, uvec2 dest);

CGLM_EXPORT
void
glmc_uvec2_scale(uvec2 v, uint32_t s, uvec2 dest);

CGLM_EXPORT
int
glmc_uvec2_distance2(uvec2 a, uvec2 b);

CGLM_EXPORT
float
glmc_uvec2_distance(uvec2 a, uvec2 b);

CGLM_EXPORT
void
glmc_uvec2_fill(uvec2 v, uint32_t val);

CGLM_EXPORT
bool
glmc_uvec2_eq(uvec2 v, uint32_t val);

CGLM_EXPORT
bool
glmc_uvec2_eqv(uvec2 a, uvec2 b);

CGLM_EXPORT
void
glmc_uvec2_maxv(uvec2 a, uvec2 b, uvec2 dest);

CGLM_EXPORT
void
glmc_uvec2_minv(uvec2 a, uvec2 b, uvec2 dest);

CGLM_EXPORT
void
glmc_uvec2_clamp(uvec2 v, uint32_t minVal, uint32_t maxVal);

CGLM_EXPORT
void
glmc_uvec2_abs(uvec2 v, uvec2 dest);

#ifdef __cplusplus
}
#endif
#endif /* cglmc_uvec2_h */
