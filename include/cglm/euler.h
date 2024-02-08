/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 NOTE:
  angles must be passed as [X-Angle, Y-Angle, Z-angle] order
  For instance you don't pass angles as [Z-Angle, X-Angle, Y-angle] to
  glm_euler_zxy function, All RELATED functions accept angles same order
  which is [X, Y, Z].
 */

/*
 Types:
   enum glm_euler_seq

 Functions:
   CGLM_INLINE glm_euler_seq glm_euler_order(int newOrder[3]);
   CGLM_INLINE void glm_euler_angles(mat4 m, vec3 dest);
   CGLM_INLINE void glm_euler(vec3 angles, mat4 dest);
   CGLM_INLINE void glm_euler_xyz(vec3 angles, mat4 dest);
   CGLM_INLINE void glm_euler_zyx(vec3 angles, mat4 dest);
   CGLM_INLINE void glm_euler_zxy(vec3 angles, mat4 dest);
   CGLM_INLINE void glm_euler_xzy(vec3 angles, mat4 dest);
   CGLM_INLINE void glm_euler_yzx(vec3 angles, mat4 dest);
   CGLM_INLINE void glm_euler_yxz(vec3 angles, mat4 dest);
   CGLM_INLINE void glm_euler_by_order(vec3         angles,
                                       glm_euler_seq ord,
                                       mat4         dest);
   CGLM_INLINE void glm_euler_xyz_quat(vec3 angles, versor dest);
   CGLM_INLINE void glm_euler_xzy_quat(vec3 angles, versor dest);
   CGLM_INLINE void glm_euler_yxz_quat(vec3 angles, versor dest);
   CGLM_INLINE void glm_euler_yzx_quat(vec3 angles, versor dest);
   CGLM_INLINE void glm_euler_zxy_quat(vec3 angles, versor dest);
   CGLM_INLINE void glm_euler_zyx_quat(vec3 angles, versor dest);
 */

#ifndef cglm_euler_h
#define cglm_euler_h

#include "common.h"

#ifdef CGLM_FORCE_LEFT_HANDED
#  include "handed/euler_to_quat_lh.h"
#else
#  include "handed/euler_to_quat_rh.h"
#endif


#ifndef CGLM_CLIPSPACE_INCLUDE_ALL
#  if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
#    include "clipspace/ortho_lh_zo.h"
#    include "clipspace/persp_lh_zo.h"
#    include "clipspace/view_lh_zo.h"
#  elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
#    include "clipspace/ortho_lh_no.h"
#    include "clipspace/persp_lh_no.h"
#    include "clipspace/view_lh_no.h"
#  elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
#    include "clipspace/ortho_rh_zo.h"
#    include "clipspace/persp_rh_zo.h"
#    include "clipspace/view_rh_zo.h"
#  elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
#    include "clipspace/ortho_rh_no.h"
#    include "clipspace/persp_rh_no.h"
#    include "clipspace/view_rh_no.h"
#  endif
#else
#  include "clipspace/ortho_lh_zo.h"
#  include "clipspace/persp_lh_zo.h"
#  include "clipspace/ortho_lh_no.h"
#  include "clipspace/persp_lh_no.h"
#  include "clipspace/ortho_rh_zo.h"
#  include "clipspace/persp_rh_zo.h"
#  include "clipspace/ortho_rh_no.h"
#  include "clipspace/persp_rh_no.h"
#  include "clipspace/view_lh_zo.h"
#  include "clipspace/view_lh_no.h"
#  include "clipspace/view_rh_zo.h"
#  include "clipspace/view_rh_no.h"
#endif


/*!
 * if you have axis order like vec3 orderVec = [0, 1, 2] or [0, 2, 1]...
 * vector then you can convert it to this enum by doing this:
 * @code
 * glm_euler_seq order;
 * order = orderVec[0] | orderVec[1] << 2 | orderVec[2] << 4;
 * @endcode
 * you may need to explicit cast if required
 */
typedef enum glm_euler_seq {
  GLM_EULER_XYZ = 0 << 0 | 1 << 2 | 2 << 4,
  GLM_EULER_XZY = 0 << 0 | 2 << 2 | 1 << 4,
  GLM_EULER_YZX = 1 << 0 | 2 << 2 | 0 << 4,
  GLM_EULER_YXZ = 1 << 0 | 0 << 2 | 2 << 4,
  GLM_EULER_ZXY = 2 << 0 | 0 << 2 | 1 << 4,
  GLM_EULER_ZYX = 2 << 0 | 1 << 2 | 0 << 4
} glm_euler_seq;

CGLM_INLINE
glm_euler_seq
glm_euler_order(int ord[3]) {
  return (glm_euler_seq)(ord[0] << 0 | ord[1] << 2 | ord[2] << 4);
}

/*!
 * @brief extract euler angles (in radians) using xyz order
 *
 * @param[in]  m    affine transform
 * @param[out] dest angles vector [x, y, z]
 */
CGLM_INLINE
void
glm_euler_angles(mat4 m, vec3 dest) {
  float m00, m01, m10, m11, m20, m21, m22;
  float thetaX, thetaY, thetaZ;

  m00 = m[0][0];  m10 = m[1][0];  m20 = m[2][0];
  m01 = m[0][1];  m11 = m[1][1];  m21 = m[2][1];
                                  m22 = m[2][2];

  if (m20 < 1.0f) {
    if (m20 > -1.0f) {
      thetaY = asinf(m20);
      thetaX = atan2f(-m21, m22);
      thetaZ = atan2f(-m10, m00);
    } else { /* m20 == -1 */
      /* Not a unique solution */
      thetaY = -GLM_PI_2f;
      thetaX = -atan2f(m01, m11);
      thetaZ =  0.0f;
    }
  } else { /* m20 == +1 */
    thetaY = GLM_PI_2f;
    thetaX = atan2f(m01, m11);
    thetaZ = 0.0f;
  }

  dest[0] = thetaX;
  dest[1] = thetaY;
  dest[2] = thetaZ;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_xyz(vec3 angles, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz, czsx, cxcz, sysz;

  sx   = sinf(angles[0]); cx = cosf(angles[0]);
  sy   = sinf(angles[1]); cy = cosf(angles[1]);
  sz   = sinf(angles[2]); cz = cosf(angles[2]);

  czsx = cz * sx;
  cxcz = cx * cz;
  sysz = sy * sz;

  dest[0][0] =  cy * cz;
  dest[0][1] =  czsx * sy + cx * sz;
  dest[0][2] = -cxcz * sy + sx * sz;
  dest[1][0] = -cy * sz;
  dest[1][1] =  cxcz - sx * sysz;
  dest[1][2] =  czsx + cx * sysz;
  dest[2][0] =  sy;
  dest[2][1] = -cy * sx;
  dest[2][2] =  cx * cy;
  dest[0][3] =  0.0f;
  dest[1][3] =  0.0f;
  dest[2][3] =  0.0f;
  dest[3][0] =  0.0f;
  dest[3][1] =  0.0f;
  dest[3][2] =  0.0f;
  dest[3][3] =  1.0f;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler(vec3 angles, mat4 dest) {
  glm_euler_xyz(angles, dest);
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_xzy(vec3 angles, mat4 dest) {
  float cx, cy, cz,
  sx, sy, sz, sxsy, cysx, cxsy, cxcy;

  sx   = sinf(angles[0]); cx = cosf(angles[0]);
  sy   = sinf(angles[1]); cy = cosf(angles[1]);
  sz   = sinf(angles[2]); cz = cosf(angles[2]);

  sxsy = sx * sy;
  cysx = cy * sx;
  cxsy = cx * sy;
  cxcy = cx * cy;

  dest[0][0] =  cy * cz;
  dest[0][1] =  sxsy + cxcy * sz;
  dest[0][2] = -cxsy + cysx * sz;
  dest[1][0] = -sz;
  dest[1][1] =  cx * cz;
  dest[1][2] =  cz * sx;
  dest[2][0] =  cz * sy;
  dest[2][1] = -cysx + cxsy * sz;
  dest[2][2] =  cxcy + sxsy * sz;
  dest[0][3] =  0.0f;
  dest[1][3] =  0.0f;
  dest[2][3] =  0.0f;
  dest[3][0] =  0.0f;
  dest[3][1] =  0.0f;
  dest[3][2] =  0.0f;
  dest[3][3] =  1.0f;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_yxz(vec3 angles, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz, cycz, sysz, czsy, cysz;

  sx   = sinf(angles[0]); cx = cosf(angles[0]);
  sy   = sinf(angles[1]); cy = cosf(angles[1]);
  sz   = sinf(angles[2]); cz = cosf(angles[2]);

  cycz = cy * cz;
  sysz = sy * sz;
  czsy = cz * sy;
  cysz = cy * sz;

  dest[0][0] =  cycz + sx * sysz;
  dest[0][1] =  cx * sz;
  dest[0][2] = -czsy + cysz * sx;
  dest[1][0] = -cysz + czsy * sx;
  dest[1][1] =  cx * cz;
  dest[1][2] =  cycz * sx + sysz;
  dest[2][0] =  cx * sy;
  dest[2][1] = -sx;
  dest[2][2] =  cx * cy;
  dest[0][3] =  0.0f;
  dest[1][3] =  0.0f;
  dest[2][3] =  0.0f;
  dest[3][0] =  0.0f;
  dest[3][1] =  0.0f;
  dest[3][2] =  0.0f;
  dest[3][3] =  1.0f;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_yzx(vec3 angles, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz, sxsy, cxcy, cysx, cxsy;

  sx   = sinf(angles[0]); cx = cosf(angles[0]);
  sy   = sinf(angles[1]); cy = cosf(angles[1]);
  sz   = sinf(angles[2]); cz = cosf(angles[2]);

  sxsy = sx * sy;
  cxcy = cx * cy;
  cysx = cy * sx;
  cxsy = cx * sy;

  dest[0][0] =  cy * cz;
  dest[0][1] =  sz;
  dest[0][2] = -cz * sy;
  dest[1][0] =  sxsy - cxcy * sz;
  dest[1][1] =  cx * cz;
  dest[1][2] =  cysx + cxsy * sz;
  dest[2][0] =  cxsy + cysx * sz;
  dest[2][1] = -cz * sx;
  dest[2][2] =  cxcy - sxsy * sz;
  dest[0][3] =  0.0f;
  dest[1][3] =  0.0f;
  dest[2][3] =  0.0f;
  dest[3][0] =  0.0f;
  dest[3][1] =  0.0f;
  dest[3][2] =  0.0f;
  dest[3][3] =  1.0f;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_zxy(vec3 angles, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz, cycz, sxsy, cysz;

  sx   = sinf(angles[0]); cx = cosf(angles[0]);
  sy   = sinf(angles[1]); cy = cosf(angles[1]);
  sz   = sinf(angles[2]); cz = cosf(angles[2]);

  cycz = cy * cz;
  sxsy = sx * sy;
  cysz = cy * sz;

  dest[0][0] =  cycz - sxsy * sz;
  dest[0][1] =  cz * sxsy + cysz;
  dest[0][2] = -cx * sy;
  dest[1][0] = -cx * sz;
  dest[1][1] =  cx * cz;
  dest[1][2] =  sx;
  dest[2][0] =  cz * sy + cysz * sx;
  dest[2][1] = -cycz * sx + sy * sz;
  dest[2][2] =  cx * cy;
  dest[0][3] =  0.0f;
  dest[1][3] =  0.0f;
  dest[2][3] =  0.0f;
  dest[3][0] =  0.0f;
  dest[3][1] =  0.0f;
  dest[3][2] =  0.0f;
  dest[3][3] =  1.0f;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_zyx(vec3 angles, mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz, czsx, cxcz, sysz;

  sx   = sinf(angles[0]); cx = cosf(angles[0]);
  sy   = sinf(angles[1]); cy = cosf(angles[1]);
  sz   = sinf(angles[2]); cz = cosf(angles[2]);

  czsx = cz * sx;
  cxcz = cx * cz;
  sysz = sy * sz;

  dest[0][0] =  cy * cz;
  dest[0][1] =  cy * sz;
  dest[0][2] = -sy;
  dest[1][0] =  czsx * sy - cx * sz;
  dest[1][1] =  cxcz + sx * sysz;
  dest[1][2] =  cy * sx;
  dest[2][0] =  cxcz * sy + sx * sz;
  dest[2][1] = -czsx + cx * sysz;
  dest[2][2] =  cx * cy;
  dest[0][3] =  0.0f;
  dest[1][3] =  0.0f;
  dest[2][3] =  0.0f;
  dest[3][0] =  0.0f;
  dest[3][1] =  0.0f;
  dest[3][2] =  0.0f;
  dest[3][3] =  1.0f;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[in]  ord    euler order
 * @param[out] dest   rotation matrix
 */
CGLM_INLINE
void
glm_euler_by_order(vec3 angles, glm_euler_seq ord, mat4 dest) {
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

  switch (ord) {
    case GLM_EULER_XZY:
      dest[0][0] =  cycz;
      dest[0][1] =  sx * sy + cx * cysz;
      dest[0][2] = -cx * sy + cysx * sz;
      dest[1][0] = -sz;
      dest[1][1] =  cxcz;
      dest[1][2] =  czsx;
      dest[2][0] =  czsy;
      dest[2][1] = -cysx + cx * sysz;
      dest[2][2] =  cxcy + sx * sysz;
      break;
    case GLM_EULER_XYZ:
      dest[0][0] =  cycz;
      dest[0][1] =  czsx * sy + cxsz;
      dest[0][2] = -cx * czsy + sx * sz;
      dest[1][0] = -cysz;
      dest[1][1] =  cxcz - sx * sysz;
      dest[1][2] =  czsx + cx * sysz;
      dest[2][0] =  sy;
      dest[2][1] = -cysx;
      dest[2][2] =  cxcy;
      break;
    case GLM_EULER_YXZ:
      dest[0][0] =  cycz + sx * sysz;
      dest[0][1] =  cxsz;
      dest[0][2] = -czsy + cysx * sz;
      dest[1][0] =  czsx * sy - cysz;
      dest[1][1] =  cxcz;
      dest[1][2] =  cycz * sx + sysz;
      dest[2][0] =  cx * sy;
      dest[2][1] = -sx;
      dest[2][2] =  cxcy;
      break;
    case GLM_EULER_YZX:
      dest[0][0] =  cycz;
      dest[0][1] =  sz;
      dest[0][2] = -czsy;
      dest[1][0] =  sx * sy - cx * cysz;
      dest[1][1] =  cxcz;
      dest[1][2] =  cysx + cx * sysz;
      dest[2][0] =  cx * sy + cysx * sz;
      dest[2][1] = -czsx;
      dest[2][2] =  cxcy - sx * sysz;
      break;
    case GLM_EULER_ZXY:
      dest[0][0] =  cycz - sx * sysz;
      dest[0][1] =  czsx * sy + cysz;
      dest[0][2] = -cx * sy;
      dest[1][0] = -cxsz;
      dest[1][1] =  cxcz;
      dest[1][2] =  sx;
      dest[2][0] =  czsy + cysx * sz;
      dest[2][1] = -cycz * sx + sysz;
      dest[2][2] =  cxcy;
      break;
    case GLM_EULER_ZYX:
      dest[0][0] =  cycz;
      dest[0][1] =  cysz;
      dest[0][2] = -sy;
      dest[1][0] =  czsx * sy - cxsz;
      dest[1][1] =  cxcz + sx * sysz;
      dest[1][2] =  cysx;
      dest[2][0] =  cx * czsy + sx * sz;
      dest[2][1] = -czsx + cx * sysz;
      dest[2][2] =  cxcy;
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


/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in x y z order (roll pitch yaw)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
void
glm_euler_xyz_quat(vec3 angles, versor dest) {
#ifdef CGLM_FORCE_LEFT_HANDED
  glm_euler_xyz_quat_lh(angles, dest);
#else
  glm_euler_xyz_quat_rh(angles, dest);
#endif
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in x z y order (roll yaw pitch)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
void
glm_euler_xzy_quat(vec3 angles, versor dest) {
#ifdef CGLM_FORCE_LEFT_HANDED
  glm_euler_xzy_quat_lh(angles, dest);
#else
  glm_euler_xzy_quat_rh(angles, dest);
#endif
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in y x z order (pitch roll yaw)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
void
glm_euler_yxz_quat(vec3 angles, versor dest) {
#ifdef CGLM_FORCE_LEFT_HANDED
  glm_euler_yxz_quat_lh(angles, dest);
#else
  glm_euler_yxz_quat_rh(angles, dest);
#endif
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in y z x order (pitch yaw roll)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
void
glm_euler_yzx_quat(vec3 angles, versor dest) {
#ifdef CGLM_FORCE_LEFT_HANDED
  glm_euler_yzx_quat_lh(angles, dest);
#else
  glm_euler_yzx_quat_rh(angles, dest);
#endif
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in z x y order (yaw roll pitch)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
void
glm_euler_zxy_quat(vec3 angles, versor dest) {
#ifdef CGLM_FORCE_LEFT_HANDED
  glm_euler_zxy_quat_lh(angles, dest);
#else
  glm_euler_zxy_quat_rh(angles, dest);
#endif
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in z y x order (yaw pitch roll)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
void
glm_euler_zyx_quat(vec3 angles, versor dest) {
#ifdef CGLM_FORCE_LEFT_HANDED
  glm_euler_zyx_quat_lh(angles, dest);
#else
  glm_euler_zyx_quat_rh(angles, dest);
#endif
}


#endif /* cglm_euler_h */
