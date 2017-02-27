/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_vcam_h
#define cglm_vcam_h

#include "cglm-common.h"

CGLM_INLINE
void
glm_frustum(float left,
            float right,
            float bottom,
            float top,
            float nearVal,
            float farVal,
            mat4 dest) {
  float rl, tb, fn;

  glm__memzero(float, dest, sizeof(mat4));

  rl = 1.0f / (right - left);
  tb = 1.0f / (top - bottom);
  fn = 1.0f / (farVal - nearVal);

  dest[0][0] = 2.0f * nearVal * rl;
  dest[1][1] = 2.0f * nearVal * tb;
  dest[2][0] = (right + left) * rl;
  dest[2][1] = (top + bottom) * tb;
  dest[2][2] = -(farVal + nearVal) * fn;
  dest[2][3] = -1.0f;
  dest[3][2] = -2.0f * farVal * nearVal * fn;
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
  float rl, tb, fn;

  glm__memzero(float, dest, sizeof(mat4));

  rl = 1.0f / (right - left);
  tb = 1.0f / (top - bottom);
  fn = 1.0f / (farVal - nearVal);

  dest[0][0] = 2.0f * rl;
  dest[1][1] = 2.0f * tb;
  dest[2][2] =-2.0f * fn;
  dest[3][0] =-(right + left) * rl;
  dest[3][1] =-(top + bottom) * tb;
  dest[3][2] =-(farVal + nearVal) * fn;
  dest[3][3] = 1.0f;
}

CGLM_INLINE
void
glm_ortho_default(float aspectRatio,
				  mat4  dest) {
  if (aspectRatio >= 1.0f) {
    glm_ortho(-1.0f * aspectRatio,
               1.0f * aspectRatio,
              -1.0f,
               1.0f,
              -100.0f,
               100.0f,
               dest);
	return;
  }

  glm_ortho(-1.0f,
			 1.0f,
			-1.0f / aspectRatio,
			 1.0f / aspectRatio,
			-100.0f,
			 100.0f,
			 dest);
}

CGLM_INLINE
void
glm_ortho_default_s(float aspectRatio,
					float size,
					mat4  dest) {
  if (aspectRatio >= 1.0f) {
    glm_ortho(-size * aspectRatio,
               size * aspectRatio,
              -size,
               size,
              -size - 100.0f,
               size + 100.0f,
               dest);
	return;
  }

  glm_ortho(-size,
			 size,
			-size / aspectRatio,
			 size / aspectRatio,
			-size - 100.0f,
			 size + 100.0f,
			 dest);
}

CGLM_INLINE
void
glm_perspective(float fovy,
                float aspect,
                float nearVal,
                float farVal,
                mat4 dest) {
  float f, fn;

  glm__memzero(float, dest, sizeof(mat4));

  f  = cosf(fovy * 0.5f) / sinf(fovy * 0.5f);
  fn = 1.0f / (nearVal - farVal);

  dest[0][0] = f / aspect;
  dest[1][1] = f;
  dest[2][2] = (nearVal + farVal) * fn;
  dest[2][3] =-1.0f;
  dest[3][2] = 2 * nearVal * farVal * fn;
}

CGLM_INLINE
void
glm_perspective_default(float aspectRatio, mat4 dest) {
  glm_perspective((float)CGLM_PI_4,
                  aspectRatio,
                  0.01f,
                  100.0f,
                  dest);
}

CGLM_INLINE
void
glm_perspective_resize(float aspectRatio,
					   mat4  proj) {
  if (proj[0][0] == 0)
    return;

  proj[0][0] = proj[1][1] / aspectRatio;
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
  dest[0][1] = u[0];
  dest[0][2] =-f[0];
  dest[1][0] = s[1];
  dest[1][1] = u[1];
  dest[1][2] =-f[1];
  dest[2][0] = s[2];
  dest[2][1] = u[2];
  dest[2][2] =-f[2];
  dest[3][0] =-glm_vec_dot(s, eye);
  dest[3][1] =-glm_vec_dot(u, eye);
  dest[3][2] = glm_vec_dot(f, eye);
  dest[0][3] = dest[1][3] = dest[2][3] = 0.0f;
  dest[3][3] = 1.0f;
}

#endif /* cglm_vcam_h */
