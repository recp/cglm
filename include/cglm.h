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

typedef float mat3[3];
typedef float mat4[16];

CGLM_INLINE
void
glm_mat_mul4(float * __restrict m1,
             float * __restrict m2,
             float * __restrict dest);

#include "cglm-vec.h"
#include "cglm-mat.h"

#endif /* glm_h */
