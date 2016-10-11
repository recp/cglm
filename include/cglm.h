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
typedef CGLM_ALIGN(16) float vec4[4];

typedef vec3 mat3[3];
typedef vec4 mat4[4];

typedef vec4 versor;

#include "cglm-vec.h"
#include "cglm-mat.h"
#include "cglm-mat3.h"
#include "cglm-util.h"
#include "cglm-affine.h"
#include "cglm-cam.h"
#include "cglm-quat.h"

#endif /* glm_h */
