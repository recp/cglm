/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:

 */

#ifndef cglm_affine2d_h
#define cglm_affine2d_h

#include "common.h"
#include "util.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#include "mat3.h"
#include "affine-mat.h"

/*!
 * @brief translate existing 2d transform matrix by v vector
 *        and stores result in same matrix
 *
 * @param[in, out]  m  affine transfrom
 * @param[in]       v  translate vector [x, y, z]
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
 * @param[in]  v    translate vector [x, y, z]
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
 * @param[in]   v  translate vector [x, y, z]
 */
CGLM_INLINE
void
glm_translate2d_make(mat3 m, vec2 v) {
  glm_mat3_identity(m);
  m[2][0] = v[0];
  m[2][1] = v[1];
}


#endif /* cglm_affine2d_h */
