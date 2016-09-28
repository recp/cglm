/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_mat_opengl_h
#define cglm_mat_opengl_h

#ifdef __APPLE__
#  include <OpenGL/gl3.h>
#else
#  ifdef _WIN32
#    include <windows.h>
#  endif
#  include <GL/gl.h>
#endif

#include "cglm.h"

#ifdef _WIN32
extern
void
glUniformMatrix4fv(GLint location,
                   GLsizei count,
                   GLboolean transpose,
                   const GLfloat *value);
#endif

CGLM_INLINE
void
glm_mat4_uniform(mat4 m, GLint location){
  glUniformMatrix4fv(location, 1, GL_FALSE, m[0]);
}

#endif /* cglm_mat_opengl_h */
