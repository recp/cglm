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
 * if you have axis order like vec3 orderVec = [0, 1, 2] or [0, 2, 1]...
 * vector then you can convert it to this enum by doing this:
 * @code
 * glm_euler_sq order;
 * order = orderVec[0] | orderVec[1] << 2 | orderVec[2] << 4;
 * @endcode
 * you may need to explicit cast if required
 */
typedef enum glm_euler_sq {
  GLM_EULER_XYZ = 0 << 0 | 1 << 2 | 2 << 4,
  GLM_EULER_XZY = 0 << 0 | 2 << 2 | 1 << 4,
  GLM_EULER_YZX = 1 << 0 | 2 << 2 | 0 << 4,
  GLM_EULER_YXZ = 1 << 0 | 0 << 2 | 2 << 4,
  GLM_EULER_ZXY = 2 << 0 | 0 << 2 | 1 << 4,
  GLM_EULER_ZYX = 2 << 0 | 1 << 2 | 0 << 4
} glm_euler_sq;

CGLM_INLINE
glm_euler_sq
glm_euler_order(int newOrder[3]) {
  return (glm_euler_sq)(newOrder[0] | newOrder[1] << 2 | newOrder[2] << 4);
}

/*!
 * @brief euler angles (in radian) using xyz sequence
 *
 * @param[in]  m affine transform
 * @param[out] v angles vector [x, y, z]
 */
CGLM_INLINE
void
glm_euler_angles(mat4 m, vec3 dest) {
  if (m[0][2] < 1.0f) {
    if (m[0][2] > -1.0f) {
      vec3  a[2];
      float cy1, cy2;
      int   path;
      
      a[0][1] = asinf(-m[0][2]);
      a[1][1] = CGLM_PI - a[0][1];

      cy1 = cosf(a[0][1]);
      cy2 = cosf(a[1][1]);

      a[0][0] = atan2f(m[1][2] / cy1, m[2][2] / cy1);
      a[1][0] = atan2f(m[1][2] / cy2, m[2][2] / cy2);

      a[0][2] = atan2f(m[0][1] / cy1, m[0][0] / cy1);
      a[1][2] = atan2f(m[0][1] / cy2, m[0][0] / cy2);

      path = (fabsf(a[0][0]) + fabsf(a[0][1]) + fabsf(a[0][2])) >=
               (fabsf(a[1][0]) + fabsf(a[1][1]) + fabsf(a[1][2]));

      glm_vec_copy(a[path], dest);
    } else {
      dest[0] = atan2f(m[1][0], m[2][0]);
      dest[1] = CGLM_PI_2;
      dest[2] = 0.0f;
    }
  } else {
    dest[0] = atan2f(-m[1][0], -m[2][0]);
    dest[1] =-CGLM_PI_2;
    dest[2] = 0.0f;
  }
}

/*!
 * @brief build rotation matrix from euler angles(ExEyEz/RzRyRx)
 *
 * @param[in]  angles angles as vector [Ex, Ey, Ez]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler(vec3 angles, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  sx = sinf(angles[0]); cx = cosf(angles[0]);
  sy = sinf(angles[1]); cy = cosf(angles[1]);
  sz = sinf(angles[2]); cz = cosf(angles[2]);

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
 * @brief build rotation matrix from euler angles (EzEyEx/RxRyRz)
 */
CGLM_INLINE
void
glm_euler_zyx(vec3 angles,
              mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  sx = sinf(angles[0]); cx = cosf(angles[0]);
  sy = sinf(angles[1]); cy = cosf(angles[1]);
  sz = sinf(angles[2]); cz = cosf(angles[2]);

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

CGLM_INLINE
void
glm_euler_zxy(vec3 angles,
              mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  sx = sinf(angles[0]); cx = cosf(angles[0]);
  sy = sinf(angles[1]); cy = cosf(angles[1]);
  sz = sinf(angles[2]); cz = cosf(angles[2]);

  dest[0][0] = cy * cz + sx * sy * sz;
  dest[0][1] = cx * sz;
  dest[0][2] =-cz * sy + cy * sx * sz;
  dest[1][0] = cz * sx * sy - cy * sz;
  dest[1][1] = cx * cz;
  dest[1][2] = cy * cz * sx + sy * sz;
  dest[2][0] = cx * sy;
  dest[2][1] =-sx;
  dest[2][2] = cx * cy;
  dest[0][3] = 0.0f;
  dest[1][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][0] = 0.0f;
  dest[3][1] = 0.0f;
  dest[3][2] = 0.0f;
  dest[3][3] = 1.0f;
}

CGLM_INLINE
void
glm_euler_xzy(vec3 angles,
              mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  sx = sinf(angles[0]); cx = cosf(angles[0]);
  sy = sinf(angles[1]); cy = cosf(angles[1]);
  sz = sinf(angles[2]); cz = cosf(angles[2]);

  dest[0][0] = cy * cz;
  dest[0][1] = sz;
  dest[0][2] =-cz * sy;
  dest[1][0] = sx * sy - cx * cy * sz;
  dest[1][1] = cx * cz;
  dest[1][2] = cy * sx + cx * sy * sz;
  dest[2][0] = cx * sy + cy * sx * sz;
  dest[2][1] =-cz * sx;
  dest[2][2] = cx * cy - sx * sy * sz;
  dest[0][3] = 0.0f;
  dest[1][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][0] = 0.0f;
  dest[3][1] = 0.0f;
  dest[3][2] = 0.0f;
  dest[3][3] = 1.0f;
}

CGLM_INLINE
void
glm_euler_yzx(vec3 angles,
              mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  sx = sinf(angles[0]); cx = cosf(angles[0]);
  sy = sinf(angles[1]); cy = cosf(angles[1]);
  sz = sinf(angles[2]); cz = cosf(angles[2]);

  dest[0][0] = cy * cz;
  dest[0][1] = sx * sy + cx * cy * sz;
  dest[0][2] =-cx * sy + cy * sx * sz;
  dest[1][0] =-sz;
  dest[1][1] = cx * cz;
  dest[1][2] = cz * sx;
  dest[2][0] = cz * sy;
  dest[2][1] =-cy * sx + cx * sy * sz;
  dest[2][2] = cx * cy + sx * sy * sz;
  dest[0][3] = 0.0f;
  dest[1][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][0] = 0.0f;
  dest[3][1] = 0.0f;
  dest[3][2] = 0.0f;
  dest[3][3] = 1.0f;
}

CGLM_INLINE
void
glm_euler_yxz(vec3 angles,
              mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  sx = sinf(angles[0]); cx = cosf(angles[0]);
  sy = sinf(angles[1]); cy = cosf(angles[1]);
  sz = sinf(angles[2]); cz = cosf(angles[2]);

  dest[0][0] = cy * cz - sx * sy * sz;
  dest[0][1] = cz * sx * sy + cy * sz;
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

CGLM_INLINE
void
glm_euler_by_order(vec3 angles, glm_euler_sq axis, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  float cycz, cysz, cysx, cxcy,
        czsy, cxcz, czsx, cxsz,
        sysz;

  sx = sinf(angles[0]); cx = cosf(angles[0]);
  sy = sinf(angles[1]); cy = cosf(angles[1]);
  sz = sinf(angles[2]); cz = cosf(angles[2]);

  cycz = cy * cz; cysz = cy * sz;
  cysx = cy * sx; cxcy = cx * cy;
  czsy = cz * sy; cxcz = cx * cz;
  czsx = cz * sx; cxsz = cx * sz;
  sysz = sy * sz;

  switch (axis) {
    case GLM_EULER_XYZ:
      dest[0][0] = cycz;
      dest[0][1] = cysz;
      dest[0][2] =-sy;
      dest[1][0] = czsx * sy - cxsz;
      dest[1][1] = cxcz + sx * sysz;
      dest[1][2] = cysx;
      dest[2][0] = cx * czsy + sx * sz;
      dest[2][1] =-czsx + cx * sysz;
      dest[2][2] = cxcy;
      break;
    case GLM_EULER_XZY:
      dest[0][0] = cycz;
      dest[0][1] = sz;
      dest[0][2] =-czsy;
      dest[1][0] = sx * sy - cx * cysz;
      dest[1][1] = cxcz;
      dest[1][2] = cysx + cx * sysz;
      dest[2][0] = cx * sy + cysx * sz;
      dest[2][1] =-czsx;
      dest[2][2] = cxcy - sx * sysz;
      break;
    case GLM_EULER_ZXY:
      dest[0][0] = cycz + sx * sysz;
      dest[0][1] = cxsz;
      dest[0][2] =-czsy + cysx * sz;
      dest[1][0] = czsx * sy - cysz;
      dest[1][1] = cxcz;
      dest[1][2] = cycz * sx + sysz;
      dest[2][0] = cx * sy;
      dest[2][1] =-sx;
      dest[2][2] = cxcy;
      break;
    case GLM_EULER_ZYX:
      dest[0][0] = cycz;
      dest[0][1] = czsx * sy + cxsz;
      dest[0][2] =-cx * czsy + sx * sz;
      dest[1][0] =-cysz;
      dest[1][1] = cxcz - sx * sysz;
      dest[1][2] = czsx + cx * sysz;
      dest[2][0] = sy;
      dest[2][1] =-cysx;
      dest[2][2] = cxcy;
      break;
    case GLM_EULER_YXZ:
      dest[0][0] = cycz - sx * sysz;
      dest[0][1] = czsx * sy + cysz;
      dest[0][2] =-cx * sy;
      dest[1][0] =-cxsz;
      dest[1][1] = cxcz;
      dest[1][2] = sx;
      dest[2][0] = czsy + cysx * sz;
      dest[2][1] =-cycz * sx + sysz;
      dest[2][2] = cxcy;
      break;
    case GLM_EULER_YZX:
      dest[0][0] = cycz;
      dest[0][1] = sx * sy + cx * cysz;
      dest[0][2] =-cx * sy + cysx * sz;
      dest[1][0] =-sz;
      dest[1][1] = cxcz;
      dest[1][2] = czsx;
      dest[2][0] = czsy;
      dest[2][1] =-cysx + cx * sysz;
      dest[2][2] = cxcy + sx * sysz;
      break;
  }

  dest[0][3] = 0.0f;
  dest[1][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][0] = 0.0f;
  dest[3][1] = 0.0f;
  dest[3][2] = 0.0f;
  dest[3][3] = 1.0f;
}

#endif /* cglm_euler_h */
