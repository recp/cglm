/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_vcam_h
#define cglm_vcam_h

#include "cglm-common.h"
#include "cglm-platform.h"

CGLM_INLINE
void
glm_frustum(float left,
            float right,
            float bottom,
            float top,
            float nearVal,
            float farVal,
            mat4 dest) {
  /* https://www.opengl.org/sdk/docs/man2/xhtml/glFrustum.xml */

  glm__memzero(float, dest, sizeof(mat4));

  dest[0][0] = 2.0f * nearVal / (right - left);
  dest[1][1] = 2.0f * nearVal / (top - bottom);
  dest[2][0] = (right + left) / (right - left);
  dest[2][1] = (top + bottom) / (top - bottom);
  dest[2][2] = -(farVal + nearVal) / (farVal - nearVal);
  dest[2][3] = -1.0f;
  dest[3][2] = -2.0f * farVal * nearVal / (farVal - nearVal);
}

CGLM_INLINE
void
glm_ortho(float left,
          float right,
          float bottom,
          float top,
          float nearVal,
          float farVal,
          mat4 dest) {
  /* https://www.opengl.org/sdk/docs/man2/xhtml/glOrtho.xml */

  glm__memzero(float, dest, sizeof(mat4));

  dest[0][0] = 2.0f / (right - left);
  dest[1][1] = 2.0f / (top - bottom);
  dest[2][2] =-2.0f / (farVal - nearVal);
  dest[3][0] =-(right + left) / (right - left);
  dest[3][1] =-(top + bottom) / (top - bottom);
  dest[3][2] =-(farVal + nearVal) / (farVal - nearVal);
  dest[3][3] = 1.0f;
}

CGLM_INLINE
void
glm_ortho_default(mat4 dest) {
  int32_t rect[4];
  float aspectRatio;

  glm_platfom_get_viewport_rect(rect);
  aspectRatio = (float)rect[2]/rect[3];

  if (rect[2] >= rect[3]) {
    glm_ortho(-1.0f * aspectRatio,
               1.0f * aspectRatio,
              -1.0f,
               1.0f,
               100.0f,
              -100.0f,
               dest);
  } else {
    glm_ortho(-1.0f,
               1.0f,
              -1.0f / aspectRatio,
               1.0f / aspectRatio,
               100.0f,
              -100.0f,
               dest);
  }
}

CGLM_INLINE
void
glm_ortho_default_s(float size, mat4 dest) {
  int32_t rect[4];
  float aspectRatio;

  glm_platfom_get_viewport_rect(rect);
  aspectRatio = (float)rect[2]/rect[3];

  if (rect[2] >= rect[3]) {
    glm_ortho(-size * aspectRatio,
               size * aspectRatio,
              -size,
               size,
               size + 100.0f,
              -size - 100.0f,
               dest);
  } else {
    glm_ortho(-size,
               size,
              -size / aspectRatio,
               size / aspectRatio,
               size + 100.0f,
              -size - 100.0f,
               dest);
  }
}

CGLM_INLINE
void
glm_perspective(float fovy,
                float aspect,
                float nearVal,
                float farVal,
                mat4 dest) {
  /* https://www.opengl.org/sdk/docs/man2/xhtml/gluPerspective.xml */
  float f;

  glm__memzero(float, dest, sizeof(mat4));

  f = cosf(fovy * 0.5f) / sinf(fovy * 0.5f);

  dest[0][0] = f / aspect;
  dest[1][1] = f;
  dest[2][2] = (nearVal + farVal) / (nearVal - farVal);
  dest[2][3] =-1.0f;
  dest[3][2] = 2 * nearVal * farVal / (nearVal - farVal);
}

CGLM_INLINE
void
glm_perspective_default(mat4 dest) {
  int32_t rect[4];
  glm_platfom_get_viewport_rect(rect);
  
  glm_perspective((float)M_PI_4,
                  (float)rect[2]/rect[3],
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

#endif /* cglm_vcam_h */
