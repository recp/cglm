/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void glm_frustum_rh_no(float left,    float right,
                                      float bottom,  float top,
                                      float nearZ, float farZ,
                                      mat4  dest)
   CGLM_INLINE void glm_perspective_rh_no(float fovy,
                                          float aspect,
                                          float nearZ,
                                          float farZ,
                                          mat4  dest)
   CGLM_INLINE void glm_perspective_default_rh_no(float aspect, mat4 dest)
   CGLM_INLINE void glm_perspective_resize_rh_no(float aspect, mat4 proj)
   CGLM_INLINE void glm_persp_move_far_rh_no(mat4 proj,
                                             float deltaFar)
   CGLM_INLINE void glm_persp_decomp_rh_no(mat4 proj,
                                           float * __restrict nearZ,
                                           float * __restrict farZ,
                                           float * __restrict top,
                                           float * __restrict bottom,
                                           float * __restrict left,
                                           float * __restrict right)
  CGLM_INLINE void glm_persp_decompv_rh_no(mat4 proj,
                                           float dest[6])
  CGLM_INLINE void glm_persp_decomp_x_rh_no(mat4 proj,
                                            float * __restrict left,
                                            float * __restrict right)
  CGLM_INLINE void glm_persp_decomp_y_rh_no(mat4 proj,
                                            float * __restrict top,
                                            float * __restrict bottom)
  CGLM_INLINE void glm_persp_decomp_z_rh_no(mat4 proj,
                                            float * __restrict nearZ,
                                            float * __restrict farZ)
  CGLM_INLINE void glm_persp_decomp_far_rh_no(mat4 proj, float * __restrict farZ)
  CGLM_INLINE void glm_persp_decomp_near_rh_no(mat4 proj, float * __restrict nearZ)
  CGLM_INLINE void glm_persp_sizes_rh_no(mat4 proj, float fovy, vec4 dest)
 */

#ifndef cglm_persp_rh_no_h
#define cglm_persp_rh_no_h

#include "../common.h"
#include "persp.h"

/*!
 * @brief set up perspective peprojection matrix
 *        with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *
 * @param[in]  left    viewport.left
 * @param[in]  right   viewport.right
 * @param[in]  bottom  viewport.bottom
 * @param[in]  top     viewport.top
 * @param[in]  nearZ   near clipping plane
 * @param[in]  farZ    far clipping plane
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_frustum_rh_no(float left,    float right,
                  float bottom,  float top,
                  float nearZ, float farZ,
                  mat4  dest) {
  float rl, tb, fn, nv;

  glm_mat4_zero(dest);

  rl = 1.0f / (right  - left);
  tb = 1.0f / (top    - bottom);
  fn =-1.0f / (farZ - nearZ);
  nv = 2.0f * nearZ;

  dest[0][0] = nv * rl;
  dest[1][1] = nv * tb;
  dest[2][0] = (right  + left)    * rl;
  dest[2][1] = (top    + bottom)  * tb;
  dest[2][2] = (farZ + nearZ) * fn;
  dest[2][3] =-1.0f;
  dest[3][2] = farZ * nv * fn;
}

/*!
 * @brief set up perspective projection matrix
 *        with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *
 * @param[in]  fovy    field of view angle
 * @param[in]  aspect  aspect ratio ( width / height )
 * @param[in]  nearZ   near clipping plane
 * @param[in]  farZ    far clipping planes
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_perspective_rh_no(float fovy,
                      float aspect,
                      float nearZ,
                      float farZ,
                      mat4  dest) {
  float f, fn;

  glm_mat4_zero(dest);

  f  = 1.0f / tanf(fovy * 0.5f);
  fn = 1.0f / (nearZ - farZ);

  dest[0][0] = f / aspect;
  dest[1][1] = f;
  dest[2][2] = (nearZ + farZ) * fn;
  dest[2][3] =-1.0f;
  dest[3][2] = 2.0f * nearZ * farZ * fn;

}

/*!
 * @brief set up perspective projection matrix with default near/far
 *        and angle values with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *
 * @param[in]  aspect aspect ratio ( width / height )
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_perspective_default_rh_no(float aspect, mat4 dest) {
  glm_perspective_rh_no(GLM_PI_4f, aspect, 0.01f, 100.0f, dest);
}

/*!
 * @brief resize perspective matrix by aspect ratio ( width / height )
 *        this makes very easy to resize proj matrix when window /viewport
 *        resized with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *
 * @param[in]      aspect aspect ratio ( width / height )
 * @param[in, out] proj   perspective projection matrix
 */
CGLM_INLINE
void
glm_perspective_resize_rh_no(float aspect, mat4 proj) {
  if (proj[0][0] == 0.0f)
    return;

  proj[0][0] = proj[1][1] / aspect;
}

/*!
 * @brief extend perspective projection matrix's far distance
 *        with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *
 * this function does not guarantee far >= near, be aware of that!
 *
 * @param[in, out] proj      projection matrix to extend
 * @param[in]      deltaFar  distance from existing far (negative to shink)
 */
CGLM_INLINE
void
glm_persp_move_far_rh_no(mat4 proj, float deltaFar) {
  float fn, farZ, nearZ, p22, p32;

  p22        = proj[2][2];
  p32        = proj[3][2];

  nearZ    = p32 / (p22 - 1.0f);
  farZ     = p32 / (p22 + 1.0f) + deltaFar;
  fn         = 1.0f / (nearZ - farZ);

  proj[2][2] = (farZ + nearZ) * fn;
  proj[3][2] = 2.0f * nearZ * farZ * fn;
}

/*!
 * @brief decomposes frustum values of perspective projection
 *        with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *
 * @param[in]  proj    perspective projection matrix
 * @param[out] nearZ   near
 * @param[out] farZ    far
 * @param[out] top     top
 * @param[out] bottom  bottom
 * @param[out] left    left
 * @param[out] right   right
 */
CGLM_INLINE
void
glm_persp_decomp_rh_no(mat4 proj,
                       float * __restrict nearZ, float * __restrict farZ,
                       float * __restrict top,     float * __restrict bottom,
                       float * __restrict left,    float * __restrict right) {
  float m00, m11, m20, m21, m22, m32, n, f;
  float n_m11, n_m00;

  m00 = proj[0][0];
  m11 = proj[1][1];
  m20 = proj[2][0];
  m21 = proj[2][1];
  m22 = proj[2][2];
  m32 = proj[3][2];

  n = m32 / (m22 - 1.0f);
  f = m32 / (m22 + 1.0f);

  n_m11 = n / m11;
  n_m00 = n / m00;

  *nearZ = n;
  *farZ  = f;
  *bottom  = n_m11 * (m21 - 1.0f);
  *top     = n_m11 * (m21 + 1.0f);
  *left    = n_m00 * (m20 - 1.0f);
  *right   = n_m00 * (m20 + 1.0f);
}

/*!
 * @brief decomposes frustum values of perspective projection
 *        with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *        this makes easy to get all values at once
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] dest   array
 */
CGLM_INLINE
void
glm_persp_decompv_rh_no(mat4 proj, float dest[6]) {
  glm_persp_decomp_rh_no(proj, &dest[0], &dest[1], &dest[2],
                               &dest[3], &dest[4], &dest[5]);
}

/*!
 * @brief decomposes left and right values of perspective projection
 *        with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *        x stands for x axis (left / right axis)
 *
 * @param[in]  proj  perspective projection matrix
 * @param[out] left  left
 * @param[out] right right
 */
CGLM_INLINE
void
glm_persp_decomp_x_rh_no(mat4 proj,
                         float * __restrict left,
                         float * __restrict right) {
  float nearZ, m20, m00, m22;

  m00 = proj[0][0];
  m20 = proj[2][0];
  m22 = proj[2][2];

  nearZ = proj[3][2] / (m22 - 1.0f);
  *left   = nearZ * (m20 - 1.0f) / m00;
  *right  = nearZ * (m20 + 1.0f) / m00;
}

/*!
 * @brief decomposes top and bottom values of perspective projection
 *        with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *        y stands for y axis (top / botom axis)
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] top    top
 * @param[out] bottom bottom
 */
CGLM_INLINE
void
glm_persp_decomp_y_rh_no(mat4 proj,
                         float * __restrict top,
                         float * __restrict bottom) {
  float nearZ, m21, m11, m22;

  m21 = proj[2][1];
  m11 = proj[1][1];
  m22 = proj[2][2];

  nearZ = proj[3][2] / (m22 - 1.0f);
  *bottom = nearZ * (m21 - 1.0f) / m11;
  *top    = nearZ * (m21 + 1.0f) / m11;
}

/*!
 * @brief decomposes near and far values of perspective projection
 *        with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *        z stands for z axis (near / far axis)
 *
 * @param[in]  proj    perspective projection matrix
 * @param[out] nearZ   near
 * @param[out] farZ    far
 */
CGLM_INLINE
void
glm_persp_decomp_z_rh_no(mat4 proj,
                      float * __restrict nearZ,
                      float * __restrict farZ) {
  float m32, m22;

  m32 = proj[3][2];
  m22 = proj[2][2];

  *nearZ = m32 / (m22 - 1.0f);
  *farZ  = m32 / (m22 + 1.0f);
}

/*!
 * @brief decomposes far value of perspective projection
 *        with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] farZ   far
 */
CGLM_INLINE
void
glm_persp_decomp_far_rh_no(mat4 proj, float * __restrict farZ) {
  *farZ = proj[3][2] / (proj[2][2] + 1.0f);
}

/*!
 * @brief decomposes near value of perspective projection
 *        with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *
 * @param[in]  proj    perspective projection matrix
 * @param[out] nearZ near
 */
CGLM_INLINE
void
glm_persp_decomp_near_rh_no(mat4 proj, float * __restrict nearZ) {
  *nearZ = proj[3][2] / (proj[2][2] - 1.0f);
}

/*!
 * @brief returns sizes of near and far planes of perspective projection
 *        with a right-hand coordinate system and a
 *        clip-space of [-1, 1].
 *
 * @param[in]  proj perspective projection matrix
 * @param[in]  fovy fovy (see brief)
 * @param[out] dest sizes order: [Wnear, Hnear, Wfar, Hfar]
 */
CGLM_INLINE
void
glm_persp_sizes_rh_no(mat4 proj, float fovy, vec4 dest) {
  float t, a, nearZ, farZ;

  t = 2.0f * tanf(fovy * 0.5f);
  a = glm_persp_aspect(proj);

  glm_persp_decomp_z_rh_no(proj, &nearZ, &farZ);

  dest[1]  = t * nearZ;
  dest[3]  = t * farZ;
  dest[0]  = a * dest[1];
  dest[2]  = a * dest[3];
}

/*!
 * @brief returns field of view angle along the Y-axis (in radians)
 *        with a right-hand coordinate system and a clip-space of [-1, 1].
 *
 * if you need to degrees, use glm_deg to convert it or use this:
 * fovy_deg = glm_deg(glm_persp_fovy(projMatrix))
 *
 * @param[in] proj perspective projection matrix
 */
CGLM_INLINE
float
glm_persp_fovy_rh_no(mat4 proj) {
  return glm_persp_fovy(proj);
}

/*!
 * @brief returns aspect ratio of perspective projection
 *        with a right-hand coordinate system and a clip-space of [-1, 1].
 *
 * @param[in] proj perspective projection matrix
 */
CGLM_INLINE
float
glm_persp_aspect_rh_no(mat4 proj) {
  return glm_persp_aspect(proj);
}

#endif /*cglm_cam_rh_no_h*/
