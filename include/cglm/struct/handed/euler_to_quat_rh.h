/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void glms_euler_xyz_quat_rh(vec3 angles, versor dest);
   CGLM_INLINE void glms_euler_xzy_quat_rh(vec3 angles, versor dest);
   CGLM_INLINE void glms_euler_yxz_quat_rh(vec3 angles, versor dest);
   CGLM_INLINE void glms_euler_yzx_quat_rh(vec3 angles, versor dest);
   CGLM_INLINE void glms_euler_zxy_quat_rh(vec3 angles, versor dest);
   CGLM_INLINE void glms_euler_zyx_quat_rh(vec3 angles, versor dest);
 */

#ifndef cglms_euler_to_quat_rh_h
#define cglms_euler_to_quat_rh_h

#include "../common.h"


/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in x y z order in right hand (roll pitch yaw)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
versors
glms_euler_xyz_quat_rh(vec3s angles) {
  versors dest;
  glm_euler_xyz_quat_rh(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in x z y order in right hand (roll yaw pitch)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
versors
glms_euler_xzy_quat_rh(vec3s angles) {
  versors dest;
  glm_euler_xzy_quat_rh(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in y x z order in right hand (pitch roll yaw)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
versors
glms_euler_yxz_quat_rh(vec3s angles) {
  versors dest;
  glm_euler_yxz_quat_rh(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in y z x order in right hand (pitch yaw roll)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
versors
glms_euler_yzx_quat_rh(vec3s angles) {
  versors dest;
  glm_euler_yzx_quat_rh(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in z x y order in right hand (yaw roll pitch)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
versors
glms_euler_zxy_quat_rh(vec3s angles) {
  versors dest;
  glm_euler_zxy_quat_rh(angles.raw, dest.raw);
  return dest;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in z y x order in right hand (yaw pitch roll)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
versors
glms_euler_zyx_quat_rh(vec3s angles) {
  versors dest;
  glm_euler_zyx_quat_rh(angles.raw, dest.raw);
  return dest;
}


#endif /* cglms_euler_to_quat_rh_h */
