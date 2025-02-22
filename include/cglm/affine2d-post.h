/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_affine2d_post_h
#define cglm_affine2d_post_h

/*
 Functions:
   CGLM_INLINE void glm_translated2d(mat3 m, vec2 v);
   CGLM_INLINE void glm_translated2d_x(mat3 m, float to);
   CGLM_INLINE void glm_translated2d_y(mat3 m, float to);
   CGLM_INLINE void glm_rotated2d(mat3 m, float angle);
   CGLM_INLINE void glm_scaled2d(mat3 m, vec2 v);
   CGLM_INLINE void glm_scaled2d_uni(mat3 m, float s);
 */

#include "vec2.h"

/*!
 * @brief translate existing transform matrix by v vector
 *        and store result in same matrix
 *
 *  this is POST transform, applies to existing transform as last transform
 *
 * @param[in, out]  m  affine transform
 * @param[in]       v  translate vector [x, y]
 */
CGLM_INLINE
void
glm_translated2d(mat3 m, vec2 v) {
  glm_vec2_add(m[2], v, m[2]);
}

/*!
 * @brief translate existing transform matrix by x factor
 *
 *  this is POST transform, applies to existing transform as last transform
 *
 * @param[in, out]  m  affine transform
 * @param[in]       x  x factor
 */
CGLM_INLINE
void
glm_translated2d_x(mat3 m, float x) {
  m[2][0] += x;
}

/*!
 * @brief translate existing transform matrix by y factor
 *
 *  this is POST transform, applies to existing transform as last transform
 *
 * @param[in, out]  m  affine transform
 * @param[in]       y  y factor
 */
CGLM_INLINE
void
glm_translated2d_y(mat3 m, float y) {
  m[2][1] += y;
}

/*!
 * @brief rotate existing transform matrix by angle
 *
 *  this is POST transform, applies to existing transform as last transform
 *
 * @param[in, out]   m      affine transform
 * @param[in]   angle  angle (radians)
 */
CGLM_INLINE
void
glm_rotated2d(mat3 m, float angle) {
  float c = cosf(angle),
        s = sinf(angle),

        m00 = m[0][0], m10 = m[1][0], m20 = m[2][0],
        m01 = m[0][1], m11 = m[1][1], m21 = m[2][1];

  m[0][0] = c * m00 - s * m01;
  m[1][0] = c * m10 - s * m11;
  m[2][0] = c * m20 - s * m21;

  m[0][1] = s * m00 + c * m01;
  m[1][1] = s * m10 + c * m11;
  m[2][1] = s * m20 + c * m21;
}

/*!
 * @brief scale existing 2d transform matrix by v vector
 *
 *  this is POST transform, applies to existing transform as last transform
 *
 * @param[in, out]   m      affine transform
 * @param[in]   v  scale vector [x, y]
 */
CGLM_INLINE
void
glm_scaled2d(mat3 m, vec2 v) {
  m[0][0] *= v[0];
  m[1][0] *= v[0];
  m[2][0] *= v[0];

  m[0][1] *= v[1];
  m[1][1] *= v[1];
  m[2][1] *= v[1];
}

/*!
 * @brief applies uniform scale to existing 2d transform matrix v = [s, s]
 *
 *  this is POST transform, applies to existing transform as last transform
 *
 * @param[in, out]  m  affine transform
 * @param[in]       s  scale factor
 */
CGLM_INLINE
void
glm_scaled2d_uni(mat3 m, float s) {
  m[0][0] *= s;
  m[1][0] *= s;
  m[2][0] *= s;

  m[0][1] *= s;
  m[1][1] *= s;
  m[2][1] *= s;
}

#endif /* cglm_affine2d_post_h */
