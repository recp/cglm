/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void glm_translate2d(mat3 m, vec2 v)
   CGLM_INLINE void glm_translate2d_to(mat3 m, vec2 v, mat3 dest)
   CGLM_INLINE void glm_translate2d_x(mat3 m, float x)
   CGLM_INLINE void glm_translate2d_y(mat3 m, float y)
   CGLM_INLINE void glm_translate2d_make(mat3 m, vec2 v)
   CGLM_INLINE void glm_scale2d_to(mat3 m, vec2 v, mat3 dest)
   CGLM_INLINE void glm_scale2d_make(mat3 m, vec2 v)
   CGLM_INLINE void glm_scale2d(mat3 m, vec2 v)
   CGLM_INLINE void glm_scale2d_uni(mat3 m, float s)
   CGLM_INLINE void glm_rotate2d_make(mat3 m, float angle)
   CGLM_INLINE void glm_rotate2d(mat3 m, float angle)
   CGLM_INLINE void glm_rotate2d_to(mat3 m, float angle, mat3 dest)
 */

#ifndef cglm_affine2d_h
#define cglm_affine2d_h

#include "common.h"
#include "util.h"
#include "vec2.h"
#include "mat3.h"

/*!
 * @brief translate existing 2d transform matrix by v vector
 *        and stores result in same matrix
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       v  translate vector [x, y]
 */
CGLM_INLINE
void
glm_translate2d(mat3 m, vec2 v) {
  m[2][0] = m[0][0] * v[0] + m[1][0] * v[1] + m[2][0];
  m[2][1] = m[0][1] * v[0] + m[1][1] * v[1] + m[2][1];
  m[2][2] = m[0][2] * v[0] + m[1][2] * v[1] + m[2][2];
}

/*!
 * @brief translate existing 2d transform matrix by v vector
 *        and store result in dest
 *
 * source matrix will remain same
 *
 * @param[in]  m    affine transfrom
 * @param[in]  v    translate vector [x, y]
 * @param[out] dest translated matrix
 */
CGLM_INLINE
void
glm_translate2d_to(mat3 m, vec2 v, mat3 dest) {
  glm_mat3_copy(m, dest);
  glm_translate2d(dest, v);
}

/*!
 * @brief translate existing 2d transform matrix by x factor
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       x  x factor
 */
CGLM_INLINE
void
glm_translate2d_x(mat3 m, float x) {
  m[2][0] = m[0][0] * x + m[2][0];
  m[2][1] = m[0][1] * x + m[2][1];
  m[2][2] = m[0][2] * x + m[2][2];
}

/*!
 * @brief translate existing 2d transform matrix by y factor
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       y  y factor
 */
CGLM_INLINE
void
glm_translate2d_y(mat3 m, float y) {
  m[2][0] = m[1][0] * y + m[2][0];
  m[2][1] = m[1][1] * y + m[2][1];
  m[2][2] = m[1][2] * y + m[2][2];
}

/*!
 * @brief creates NEW translate 2d transform matrix by v vector
 *
 * @param[out]  m  affine transfrom
 * @param[in]   v  translate vector [x, y]
 */
CGLM_INLINE
void
glm_translate2d_make(mat3 m, vec2 v) {
  glm_mat3_identity(m);
  m[2][0] = v[0];
  m[2][1] = v[1];
}

/*!
 * @brief scale existing 2d transform matrix by v vector
 *        and store result in dest
 *
 * @param[in]  m    affine transfrom
 * @param[in]  v    scale vector [x, y]
 * @param[out] dest scaled matrix
 */
CGLM_INLINE
void
glm_scale2d_to(mat3 m, vec2 v, mat3 dest) {
  dest[0][0] = m[0][0] * v[0];
  dest[0][1] = m[0][1] * v[0];
  dest[0][2] = m[0][2] * v[0];
  
  dest[1][0] = m[1][0] * v[1];
  dest[1][1] = m[1][1] * v[1];
  dest[1][2] = m[1][2] * v[1];
  
  dest[2][0] = m[2][0];
  dest[2][1] = m[2][1];
  dest[2][2] = m[2][2];
}

/*!
 * @brief creates NEW 2d scale matrix by v vector
 *
 * @param[out]  m  affine transfrom
 * @param[in]   v  scale vector [x, y]
 */
CGLM_INLINE
void
glm_scale2d_make(mat3 m, vec2 v) {
  glm_mat3_identity(m);
  m[0][0] = v[0];
  m[1][1] = v[1];
}

/*!
 * @brief scales existing 2d transform matrix by v vector
 *        and stores result in same matrix
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       v  scale vector [x, y]
 */
CGLM_INLINE
void
glm_scale2d(mat3 m, vec2 v) {
  m[0][0] = m[0][0] * v[0];
  m[0][1] = m[0][1] * v[0];
  m[0][2] = m[0][2] * v[0];

  m[1][0] = m[1][0] * v[1];
  m[1][1] = m[1][1] * v[1];
  m[1][2] = m[1][2] * v[1];
}

/*!
 * @brief applies uniform scale to existing 2d transform matrix v = [s, s]
 *        and stores result in same matrix
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       s  scale factor
 */
CGLM_INLINE
void
glm_scale2d_uni(mat3 m, float s) {
  m[0][0] = m[0][0] * s;
  m[0][1] = m[0][1] * s;
  m[0][2] = m[0][2] * s;

  m[1][0] = m[1][0] * s;
  m[1][1] = m[1][1] * s;
  m[1][2] = m[1][2] * s;
}

/*!
 * @brief creates NEW rotation matrix by angle around Z axis
 *
 * @param[out] m     affine transfrom
 * @param[in]  angle angle (radians)
 */
CGLM_INLINE
void
glm_rotate2d_make(mat3 m, float angle) {
  float c, s;

  s = sinf(angle);
  c = cosf(angle);
  
  m[0][0] = c;
  m[0][1] = s;
  m[0][2] = 0;

  m[1][0] = -s;
  m[1][1] = c;
  m[1][2] = 0;
  
  m[2][0] = 0.0f;
  m[2][1] = 0.0f;
  m[2][2] = 1.0f;
}

/*!
 * @brief rotate existing 2d transform matrix around Z axis by angle
 *         and store result in same matrix
 *
 * @param[in, out]  m      affine transfrom
 * @param[in]       angle  angle (radians)
 */
CGLM_INLINE
void
glm_rotate2d(mat3 m, float angle) {
  float m00 = m[0][0],  m10 = m[1][0],
        m01 = m[0][1],  m11 = m[1][1],
        m02 = m[0][2],  m12 = m[1][2];
  float c, s;

  s = sinf(angle);
  c = cosf(angle);
  
  m[0][0] = m00 * c + m10 * s;
  m[0][1] = m01 * c + m11 * s;
  m[0][2] = m02 * c + m12 * s;

  m[1][0] = m00 * -s + m10 * c;
  m[1][1] = m01 * -s + m11 * c;
  m[1][2] = m02 * -s + m12 * c;
}

/*!
 * @brief rotate existing 2d transform matrix around Z axis by angle
 *        and store result in dest
 *
 * @param[in]  m      affine transfrom
 * @param[in]  angle  angle (radians)
 * @param[out] dest   destination
 */
CGLM_INLINE
void
glm_rotate2d_to(mat3 m, float angle, mat3 dest) {
  float m00 = m[0][0],  m10 = m[1][0],
        m01 = m[0][1],  m11 = m[1][1],
        m02 = m[0][2],  m12 = m[1][2];
  float c, s;

  s = sinf(angle);
  c = cosf(angle);
  
  dest[0][0] = m00 * c + m10 * s;
  dest[0][1] = m01 * c + m11 * s;
  dest[0][2] = m02 * c + m12 * s;

  dest[1][0] = m00 * -s + m10 * c;
  dest[1][1] = m01 * -s + m11 * c;
  dest[1][2] = m02 * -s + m12 * c;
  
  dest[2][0] = m[2][0];
  dest[2][1] = m[2][1];
  dest[2][2] = m[2][2];
}

#endif /* cglm_affine2d_h */
