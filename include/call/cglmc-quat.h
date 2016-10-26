/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglmc_quat_h
#define cglmc_quat_h

#include "../cglm.h"

CGLM_EXPORT
void
glmc_quat_init(versor q,
               float angle,
               float x,
               float y,
               float z);

CGLM_EXPORT
float
glmc_quat_norm(versor q);

CGLM_EXPORT
void
glmc_quat_normalize(versor q);

CGLM_EXPORT
float
glmc_quat_dot(versor q, versor r);

CGLM_EXPORT
void
glmc_quat_mulv(versor q1, versor q2, versor dest);

CGLM_EXPORT
void
glmc_quat_mat4(versor q, mat4 dest);

CGLM_EXPORT
void
glmc_quat_slerp(versor q,
                versor r,
                float  t,
                versor dest);

#endif /* cglmc_quat_h */
