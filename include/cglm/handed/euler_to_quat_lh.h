/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void glm_euler_xyz_quat_lh(vec3 angles, versor dest);
   CGLM_INLINE void glm_euler_xzy_quat_lh(vec3 angles, versor dest);
   CGLM_INLINE void glm_euler_yxz_quat_lh(vec3 angles, versor dest);
   CGLM_INLINE void glm_euler_yzx_quat_lh(vec3 angles, versor dest);
   CGLM_INLINE void glm_euler_zxy_quat_lh(vec3 angles, versor dest);
   CGLM_INLINE void glm_euler_zyx_quat_lh(vec3 angles, versor dest);
 */

/*
 Things to note:
 The only difference between euler to quat rh vs lh is that the zsin part is negative
 */

#ifndef cglm_euler_to_quat_lh_h
#define cglm_euler_to_quat_lh_h

#include "../common.h"


/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in x y z order in left hand (roll pitch yaw)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
void
glm_euler_xyz_quat_lh(vec3 angles, versor dest) {
  float xc, yc, zc,
        xs, ys, zs;

  xs =  sinf(angles[0] * 0.5f); xc = cosf(angles[0] * 0.5f);
  ys =  sinf(angles[1] * 0.5f); yc = cosf(angles[1] * 0.5f);
  zs = -sinf(angles[2] * 0.5f); zc = cosf(angles[2] * 0.5f);

  dest[0] = xc * ys * zs + xs * yc * zc;
  dest[1] = xc * ys * zc - xs * yc * zs;
  dest[2] = xc * yc * zs + xs * ys * zc;
  dest[3] = xc * yc * zc - xs * ys * zs;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in x z y order in left hand (roll yaw pitch)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
void
glm_euler_xzy_quat_lh(vec3 angles, versor dest) {
  float xc, yc, zc,
        xs, ys, zs;

  xs =  sinf(angles[0] * 0.5f); xc = cosf(angles[0] * 0.5f);
  ys =  sinf(angles[1] * 0.5f); yc = cosf(angles[1] * 0.5f);
  zs = -sinf(angles[2] * 0.5f); zc = cosf(angles[2] * 0.5f);

  dest[0] = -xc * zs * ys + xs * zc * yc;
  dest[1] =  xc * zc * ys - xs * zs * yc;
  dest[2] =  xc * zs * yc + xs * zc * ys;
  dest[3] =  xc * zc * yc + xs * zs * ys;  
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in y x z order in left hand (pitch roll yaw)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
void
glm_euler_yxz_quat_lh(vec3 angles, versor dest) {
  float xc, yc, zc,
        xs, ys, zs;

  xs =  sinf(angles[0] * 0.5f); xc = cosf(angles[0] * 0.5f);
  ys =  sinf(angles[1] * 0.5f); yc = cosf(angles[1] * 0.5f);
  zs = -sinf(angles[2] * 0.5f); zc = cosf(angles[2] * 0.5f);

  dest[0] =  yc * xs * zc + ys * xc * zs;
  dest[1] = -yc * xs * zs + ys * xc * zc;
  dest[2] =  yc * xc * zs - ys * xs * zc;
  dest[3] =  yc * xc * zc + ys * xs * zs;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in y z x order in left hand (pitch yaw roll)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
void
glm_euler_yzx_quat_lh(vec3 angles, versor dest) {
  float xc, yc, zc,
        xs, ys, zs;

  xs =  sinf(angles[0] * 0.5f); xc = cosf(angles[0] * 0.5f);
  ys =  sinf(angles[1] * 0.5f); yc = cosf(angles[1] * 0.5f);
  zs = -sinf(angles[2] * 0.5f); zc = cosf(angles[2] * 0.5f);

  dest[0] = yc * zc * xs + ys * zs * xc;
  dest[1] = yc * zs * xs + ys * zc * xc;
  dest[2] = yc * zs * xc - ys * zc * xs;
  dest[3] = yc * zc * xc - ys * zs * xs;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in z x y order in left hand (yaw roll pitch)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
void
glm_euler_zxy_quat_lh(vec3 angles, versor dest) {
  float xc, yc, zc,
        xs, ys, zs;

  xs =  sinf(angles[0] * 0.5f); xc = cosf(angles[0] * 0.5f);
  ys =  sinf(angles[1] * 0.5f); yc = cosf(angles[1] * 0.5f);
  zs = -sinf(angles[2] * 0.5f); zc = cosf(angles[2] * 0.5f);

  dest[0] = zc * xs * yc - zs * xc * ys;
  dest[1] = zc * xc * ys + zs * xs * yc;
  dest[2] = zc * xs * ys + zs * xc * yc;
  dest[3] = zc * xc * yc - zs * xs * ys;
}

/*!
 * @brief creates NEW quaternion using rotation angles and does
 *        rotations in z y x order in left hand (yaw pitch roll)
 * 
 * @param[in]   angles angles x y z (radians)
 * @param[out]  dest   quaternion
 */
CGLM_INLINE
void
glm_euler_zyx_quat_lh(vec3 angles, versor dest) {
  float xc, yc, zc,
        xs, ys, zs;

  xs =  sinf(angles[0] * 0.5f); xc = cosf(angles[0] * 0.5f);
  ys =  sinf(angles[1] * 0.5f); yc = cosf(angles[1] * 0.5f);
  zs = -sinf(angles[2] * 0.5f); zc = cosf(angles[2] * 0.5f);

  dest[0] =  zc * yc * xs - zs * ys * xc;
  dest[1] =  zc * ys * xc + zs * yc * xs;
  dest[2] = -zc * ys * xs + zs * yc * xc;
  dest[3] =  zc * yc * xc + zs * ys * xs;
}

#endif /*cglm_euler_to_quat_lh_h*/
