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
  glm_euler_zxy funciton, All RELATED functions accept angles same order
  which is [X, Y, Z].
 */

/*
 Types:
   enum glm_euler_seq

 Functions:
   CGLM_INLINE vec3s glms_euler_angles(mat4s m)
   CGLM_INLINE mat4s glms_euler_xyz(vec3s angles)
   CGLM_INLINE mat4s glms_euler_xzy(vec3s angles)
   CGLM_INLINE mat4s glms_euler_yxz(vec3s angles)
   CGLM_INLINE mat4s glms_euler_yzx(vec3s angles)
   CGLM_INLINE mat4s glms_euler_zxy(vec3s angles)
   CGLM_INLINE mat4s glms_euler_zyx(vec3s angles)
   CGLM_INLINE mat4s glms_euler_by_order(vec3s angles, glm_euler_seq ord)
   CGLM_INLINE versors glms_euler_xyz_quat(vec3s angles)
   CGLM_INLINE versors glms_euler_xzy_quat(vec3s angles)
   CGLM_INLINE versors glms_euler_yxz_quat(vec3s angles)
   CGLM_INLINE versors glms_euler_yzx_quat(vec3s angles)
   CGLM_INLINE versors glms_euler_zxy_quat(vec3s angles)
   CGLM_INLINE versors glms_euler_zyx_quat(vec3s angles)
 */

#ifndef cglms_euler_h
#define cglms_euler_h

#include "../common.h"
#include "../types-struct.h"
#include "../euler.h"

/*!
 * @brief extract euler angles (in radians) using xyz order
 *
 * @param[in]  m    affine transform
 * @returns angles vector [x, y, z]
 */
CGLM_INLINE
vec3s
glms_euler_angles(mat4s m) {
  vec3s dest;
  glm_euler_angles(m.raw, dest.raw);
  return dest;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @returns rotation matrix
 */
CGLM_INLINE
mat4s
glms_euler_xyz(vec3s angles) {
  mat4s dest;
  glm_euler_xyz(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @returns rotation matrix
 */
CGLM_INLINE
mat4s
glms_euler_xzy(vec3s angles) {
  mat4s dest;
  glm_euler_xzy(angles.raw, dest.raw);
  return dest;
}


/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @returns rotation matrix
 */
CGLM_INLINE
mat4s
glms_euler_yxz(vec3s angles) {
  mat4s dest;
  glm_euler_yxz(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @returns rotation matrix
 */
CGLM_INLINE
mat4s
glms_euler_yzx(vec3s angles) {
  mat4s dest;
  glm_euler_yzx(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @returns rotation matrix
 */
CGLM_INLINE
mat4s
glms_euler_zxy(vec3s angles) {
  mat4s dest;
  glm_euler_zxy(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @returns rotation matrix
 */
CGLM_INLINE
mat4s
glms_euler_zyx(vec3s angles) {
  mat4s dest;
  glm_euler_zyx(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief build rotation matrix from euler angles
 *
 * @param[in]  angles angles as vector [Xangle, Yangle, Zangle]
 * @param[in]  ord    euler order
 * @returns rotation matrix
 */
CGLM_INLINE
mat4s
glms_euler_by_order(vec3s angles, glm_euler_seq ord) {
  mat4s dest;
  glm_euler_by_order(angles.raw, ord, dest.raw);
  return dest;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in x y z order (roll pitch yaw)
 * 
 * @param[in]   angles angles x y z (radians)
 * @returns quaternion
 */
CGLM_INLINE
versors
glms_euler_xyz_quat(vec3s angles) {
  versors dest;
  glm_euler_xyz_quat(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in x z y order (roll yaw pitch)
 * 
 * @param[in]   angles angles x y z (radians)
 * @returns quaternion
 */
CGLM_INLINE
versors
glms_euler_xzy_quat(vec3s angles) {
  versors dest;
  glm_euler_xzy_quat(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in y x z order (pitch roll yaw)
 * 
 * @param[in]   angles angles x y z (radians)
 * @returns quaternion
 */
CGLM_INLINE
versors
glms_euler_yxz_quat(vec3s angles) {
  versors dest;
  glm_euler_yxz_quat(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in y z x order (pitch yaw roll)
 * 
 * @param[in]   angles angles x y z (radians)
 * @returns quaternion
 */
CGLM_INLINE
versors
glms_euler_yzx_quat(vec3s angles) {
  versors dest;
  glm_euler_yzx_quat(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in z x y order (yaw roll pitch)
 * 
 * @param[in]   angles angles x y z (radians)
 * @returns quaternion
 */
CGLM_INLINE
versors
glms_euler_zxy_quat(vec3s angles) {
  versors dest;
  glm_euler_zxy_quat(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in z y x order (yaw pitch roll)
 * 
 * @param[in]   angles angles x y z (radians)
 * @returns quaternion
 */
CGLM_INLINE
versors
glms_euler_zyx_quat(vec3s angles) {
  versors dest;
  glm_euler_zyx_quat(angles.raw, dest.raw);
  return dest;
}


#endif /* cglms_euler_h */
