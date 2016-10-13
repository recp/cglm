/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat_opengl_h
#define cglm_mat_opengl_h

#include "cglm-common.h"
#include "cglm-platform.h"

CGLM_INLINE
void
glm_uniform(int32_t location, mat4 m) {
  glm_platform_uniform_mat4fv(location, m[0]);
}

#endif /* cglm_mat_opengl_h */
