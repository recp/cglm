/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 TODO: GLdouble vs float ?
 */

#ifndef glm_vcam_h
#define glm_vcam_h

#include "cglm.h"
#include "cglm-platform.h"
#include <math.h>

CGLM_INLINE
void
glm_frustum(float left,
            float right,
            float bottom,
            float top,
            float near,
            float far,
            mat4 dest) {
  /* https://www.opengl.org/sdk/docs/man2/xhtml/glFrustum.xml */

  glm__memzero(float, dest, sizeof(mat4));

  dest[0][0] = 2.0f * near / (right - left);
  dest[1][1] = 2.0f * near / (top - bottom);
  dest[2][0] = (right + left) / (right - left);
  dest[2][1] = (top + bottom) / (top - bottom);
  dest[2][2] = -(far + near) / (far - near);
  dest[2][3] = -1.0f;
  dest[3][2] = -2.0f * far * near / (far - near);
}

CGLM_INLINE
void
glm_ortho(float left,
          float right,
          float bottom,
          float top,
          float near,
          float far,
          mat4 dest) {
  /* https://www.opengl.org/sdk/docs/man2/xhtml/glOrtho.xml */

  glm__memzero(float, dest, sizeof(mat4));

  dest[0][0] = 2.0f / (right - left);
  dest[1][1] = 2.0f / (top - bottom);
  dest[2][2] =-2.0f / (far - near);
  dest[3][0] =-(right + left) / (right - left);
  dest[3][1] =-(top + bottom) / (top - bottom);
  dest[3][2] =-(far + near) / (far - near);
  dest[3][3] = 1.0f;
}

CGLM_INLINE
void
glm_perspective(float fovy,
                float aspect,
                float near,
                float far,
                mat4 dest) {
  /* https://www.opengl.org/sdk/docs/man2/xhtml/gluPerspective.xml */
  float f;

  glm__memzero(float, dest, sizeof(mat4));

  f = cosf(fovy * 0.5f) / sinf(fovy * 0.5f);

  dest[0][0] = f / aspect;
  dest[1][1] = f;
  dest[2][2] = (near + far) / (near - far);
  dest[2][3] =-1.0f;
  dest[3][2] = 2 * near * far  / (near - far);
}

CGLM_INLINE
void
glm_perspective_default(mat4 dest) {
  GLint viewport[4];
  glGetIntegerv(GL_VIEWPORT, viewport);

  glm_perspective(M_PI_4,
                  (float)viewport[2]/viewport[3],
                  0.01f,
                  100.0f,
                  dest);
}

CGLM_INLINE
void
glm_lookat(vec3 eye,
           vec3 center,
           vec3 up,
           mat4 dest) {
  vec3 f, u, s;

  glm_vec_sub(center, eye, f);
  glm_vec_normalize(f);

  glm_vec_cross(f, up, s);
  glm_vec_normalize(s);

  glm_vec_cross(s, f, u);

  dest[0][0] = s[0];
  dest[1][0] = s[1];
  dest[2][0] = s[2];
  dest[0][1] = u[0];
  dest[1][1] = u[1];
  dest[2][1] = u[2];
  dest[0][2] =-f[0];
  dest[1][2] =-f[1];
  dest[2][2] =-f[2];
  dest[3][0] =-glm_vec_dot(s, eye);
  dest[3][1] =-glm_vec_dot(u, eye);
  dest[3][2] = glm_vec_dot(f, eye);
  dest[0][3] = 0;
  dest[1][3] = 0;
  dest[2][3] = 0;
  dest[3][3] = 1;
}

#endif /* glm_vcam_h */
