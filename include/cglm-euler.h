/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_euler_h
#define cglm_euler_h

#include "cglm-common.h"

/*!
 * @brief euler angles (in radian) using xyz sequence
 *
 * @param[in]  m     affine transform
 * @param[out] pitch x
 * @param[out] yaw   y
 * @param[out] roll  z
 */
CGLM_INLINE
void
glm_euler_angles(mat4 m,
                 float * __restrict pitch,
                 float * __restrict yaw,
                 float * __restrict roll) {
  if (m[2][0] < 1.0f) {
    if (m[2][0] > -1.0f) {
      float a[2][3];
      int   path;

      a[0][0] = asinf(m[2][0]);
      a[1][0] = M_PI - a[0][0];

      a[0][1] = atan2f(-m[2][1] / cosf(a[0][0]), m[2][2] / cosf(a[0][0]));
      a[1][1] = atan2f(-m[2][1] / cosf(a[1][0]), m[2][2] / cosf(a[1][0]));

      a[0][2] = atan2f(-m[1][0] / cosf(a[0][0]), m[0][0] / cosf(a[0][0]));
      a[1][2] = atan2f(-m[1][0] / cosf(a[1][0]), m[0][0] / cosf(a[1][0]));

      path = (fabsf(a[0][0]) + fabsf(a[0][1]) + fabsf(a[0][2])) >
                (fabsf(a[1][0]) + fabsf(a[1][1]) + fabsf(a[1][2]));

      *yaw   = a[path][0];
      *pitch = a[path][1];
      *roll  = a[path][2];
    } else {
      *yaw   = -M_PI_2;
      *pitch = -atan2(m[0][1], m[2][1]);
      *roll  = 0;
    }
  } else {
    *yaw   = M_PI_2;
    *pitch = atan2f(m[0][1], m[1][1]);
    *roll  = 0;
  }
}

/*!
 * @brief build rotation matrix from euler angles(xyz)
 */
CGLM_INLINE
void
glm_euler(float pitch,
          float yaw,
          float roll,
          mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  sx = sinf(pitch); cx = cosf(pitch);
  sy = sinf(yaw);   cy = cosf(yaw);
  sz = sinf(roll);  cz = cosf(roll);

  dest[0][0] = cy * cz;
  dest[0][1] = cz * sx * sy + cx * sz;
  dest[0][2] =-cx * cz * sy + sx * sz;
  dest[1][0] =-cy * sz;
  dest[1][1] = cx * cz - sx * sy * sz;
  dest[1][2] = cz * sx + cx * sy * sz;
  dest[2][0] = sy;
  dest[2][1] =-cy * sx;
  dest[2][2] = cx * cy;
  dest[0][3] = 0.0f;
  dest[1][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][0] = 0.0f;
  dest[3][1] = 0.0f;
  dest[3][2] = 0.0f;
  dest[3][3] = 1.0f;
}

/*!
 * @brief build rotation matrix from euler angles (zyx)
 */
CGLM_INLINE
void
glm_euler_zyx(float yaw,
              float pitch,
              float roll,
              mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  sx = sinf(pitch); cx = cosf(pitch);
  sy = sinf(yaw);   cy = cosf(yaw);
  sz = sinf(roll);  cz = cosf(roll);

  dest[0][0] = cy * cz;
  dest[0][1] = cy * sz;
  dest[0][2] =-sy;
  dest[1][0] = cz * sx * sy - cx * sz;
  dest[1][1] = cx * cz + sx * sy * sz;
  dest[1][2] = cy * sx;
  dest[2][0] = cx * cz * sy + sx * sz;
  dest[2][1] =-cz * sx + cx * sy * sz;
  dest[2][2] = cx * cy;
  dest[0][3] = 0.0f;
  dest[1][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][0] = 0.0f;
  dest[3][1] = 0.0f;
  dest[3][2] = 0.0f;
  dest[3][3] = 1.0f;
}

/*!
 * @brief build rotation matrix from euler angles (zxy)
 */
CGLM_INLINE
void
glm_euler_zxy(float yaw,
              float pitch,
              float roll,
              mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  sx = sinf(pitch); cx = cosf(pitch);
  sy = sinf(yaw);   cy = cosf(yaw);
  sz = sinf(roll);  cz = cosf(roll);

  dest[0][0] = cy * cz - sx * sy * sz;
  dest[0][1] = cz * sx * sy + cy + sz;
  dest[0][2] =-cx * sy;
  dest[1][0] =-cx * sz;
  dest[1][1] = cx * cz;
  dest[1][2] = sx;
  dest[2][0] = cz * sy + cy * sx * sz;
  dest[2][1] =-cy * cz * sx + sy * sz;
  dest[2][2] = cx * cy;
  dest[0][3] = 0.0f;
  dest[1][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][0] = 0.0f;
  dest[3][1] = 0.0f;
  dest[3][2] = 0.0f;
  dest[3][3] = 1.0f;
}

#endif /* cglm_euler_h */
