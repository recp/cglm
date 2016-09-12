/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef glm_vcam_h
#define glm_vcam_h

#include "cglm.h"

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
