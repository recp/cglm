/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat_opengl_h
#define cglm_mat_opengl_h

#include "cglm-platform.h"
#include "cglm.h"

CGLM_INLINE
void
glm_mat4_uniform(mat4 m, GLint location){
  glUniformMatrix4fv(location, 1, GL_FALSE, m[0]);
}

#endif /* cglm_mat_opengl_h */
