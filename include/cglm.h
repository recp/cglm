/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef glm_h
#define glm_h

#include "cglm-common.h"

typedef float vec3[3];
typedef float vec4[4];

typedef vec3 mat3[3];
typedef vec4 mat4[4];

CGLM_INLINE
void
glm_mat_mul4(mat4 m1,
             mat4 m2,
             mat4 dest);

#include "cglm-vec.h"
#include "cglm-mat.h"

#endif /* glm_h */
