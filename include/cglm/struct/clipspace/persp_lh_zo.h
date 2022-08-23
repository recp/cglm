/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE mat4s glms_frustum_lh_zo(float left,    float right,
                                        float bottom,  float top,
                                        float nearZ,   float farZ)
   CGLM_INLINE mat4s glms_perspective_lh_zo(float fovy,
                                            float aspect,
                                            float nearZ,
                                            float farZ)
   CGLM_INLINE void  glms_persp_move_far_lh_zo(mat4s proj, float deltaFar)
   CGLM_INLINE mat4s glms_perspective_default_lh_zo(float aspect)
   CGLM_INLINE void  glms_perspective_resize_lh_zo(mat4s proj, float aspect)
   CGLM_INLINE void  glms_persp_decomp_lh_zo(mat4s  proj,
                                             float *nearv, float *farv,
                                             float *top,   float *bottom,
                                             float *left,  float *right)
   CGLM_INLINE void  glms_persp_decompv_lh_zo(mat4s proj, float dest[6])
   CGLM_INLINE void  glms_persp_decomp_x_lh_zo(mat4s proj, float *left, float *right)
   CGLM_INLINE void  glms_persp_decomp_y_lh_zo(mat4s proj, float *top, float *bottom)
   CGLM_INLINE void  glms_persp_decomp_z_lh_zo(mat4s proj, float *nearv, float *farv)
   CGLM_INLINE void  glms_persp_decomp_far_lh_zo(mat4s proj, float *farZ)
   CGLM_INLINE void  glms_persp_decomp_near_lh_zo(mat4s proj, float *nearZ)
   CGLM_INLINE float glms_persp_fovy_lh_zo(mat4s proj)
   CGLM_INLINE float glms_persp_aspect_lh_zo(mat4s proj)
   CGLM_INLINE vec4s glms_persp_sizes_lh_zo(mat4s proj, float fovy)
 */

#ifndef cglms_persp_lh_zo_h
#define cglms_persp_lh_zo_h

#include "../../common.h"
#include "../../types-struct.h"
#include "../../plane.h"
#include "../../cam.h"

/*!
 * @brief set up perspective peprojection matrix
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *
 * @param[in]  left    viewport.left
 * @param[in]  right   viewport.right
 * @param[in]  bottom  viewport.bottom
 * @param[in]  top     viewport.top
 * @param[in]  nearZ   near clipping plane
 * @param[in]  farZ    far clipping plane
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_frustum_lh_zo(float left,   float right,
                   float bottom, float top,
                   float nearZ,  float farZ) {
  mat4s dest;
  glm_frustum_lh_zo(left, right, bottom, top, nearZ, farZ, dest.raw);
  return dest;
}

/*!
 * @brief set up perspective projection matrix
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *
 * @param[in]  fovy    field of view angle
 * @param[in]  aspect  aspect ratio ( width / height )
 * @param[in]  nearZ   near clipping plane
 * @param[in]  farZ    far clipping planes
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_perspective_lh_zo(float fovy, float aspect, float nearZ, float farZ) {
  mat4s dest;
  glm_perspective_lh_zo(fovy, aspect, nearZ, farZ, dest.raw);
  return dest;
}

/*!
 * @brief extend perspective projection matrix's far distance
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *
 * NOTE: if you dodn't want to create new matrix then use array api on struct.raw
 *       like glms_persp_move_far_lh_zo(prooj.raw, deltaFar) to avoid create new mat4
 *       each time
 *
 * this function does not guarantee far >= near, be aware of that!
 *
 * @param[in, out] proj      projection matrix to extend
 * @param[in]      deltaFar  distance from existing far (negative to shink)
 */
CGLM_INLINE
mat4s
glms_persp_move_far_lh_zo(mat4s proj, float deltaFar) {
  mat4s dest;
  dest = proj;
  glm_persp_move_far_lh_zo(dest.raw, deltaFar);
  return dest;
}

/*!
 * @brief set up perspective projection matrix with default near/far
 *        and angle values with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *
 * @param[in]  aspect aspect ratio ( width / height )
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_perspective_default_lh_zo(float aspect) {
  mat4s dest;
  glm_perspective_default_lh_zo(aspect, dest.raw);
  return dest;
}

/*!
 * @brief resize perspective matrix by aspect ratio ( width / height )
 *        this makes very easy to resize proj matrix when window /viewport
 *        reized with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *
 * NOTE: if you dodn't want to create new matrix then use array api on struct.raw
 *       like glms_perspective_resize_lh_zo(proj.raw, aspect) to avoid create new mat4
 *       each time
 *       
 * @param[in, out] proj   perspective projection matrix
 * @param[in]      aspect aspect ratio ( width / height )
 */
CGLM_INLINE
mat4s
glms_perspective_resize_lh_zo(mat4s proj, float aspect) {
  mat4s dest;
  dest = proj;
  glm_perspective_resize_lh_zo(aspect, dest.raw);
  return dest;
}

/*!
 * @brief decomposes frustum values of perspective projection.
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
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
glms_persp_decomp_lh_zo(mat4s proj,
                        float * __restrict nearZ, float * __restrict farZ,
                        float * __restrict top,   float * __restrict bottom,
                        float * __restrict left,  float * __restrict right) {
  glm_persp_decomp_lh_zo(proj.raw, nearZ, farZ, top, bottom, left, right);
}

/*!
 * @brief decomposes frustum values of perspective projection.
 *        this makes easy to get all values at once
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] dest   array
 */
CGLM_INLINE
void
glms_persp_decompv_lh_zo(mat4s proj, float dest[6]) {
  glm_persp_decompv_lh_zo(proj.raw, dest);
}

/*!
 * @brief decomposes left and right values of perspective projection
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *        x stands for x axis (left / right axis)
 *
 * @param[in]  proj  perspective projection matrix
 * @param[out] left  left
 * @param[out] right right
 */
CGLM_INLINE
void
glms_persp_decomp_x_lh_zo(mat4s proj,
                          float * __restrict left,
                          float * __restrict right) {
  glm_persp_decomp_x_lh_zo(proj.raw, left, right);
}

/*!
 * @brief decomposes top and bottom values of perspective projection
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *        y stands for y axis (top / botom axis)
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] top    top
 * @param[out] bottom bottom
 */
CGLM_INLINE
void
glms_persp_decomp_y_lh_zo(mat4s proj,
                          float * __restrict top,
                          float * __restrict bottom) {
  glm_persp_decomp_y_lh_zo(proj.raw, top, bottom);
}

/*!
 * @brief decomposes near and far values of perspective projection
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *        z stands for z axis (near / far axis)
 *
 * @param[in]  proj    perspective projection matrix
 * @param[out] nearZ   near
 * @param[out] farZ    far
 */
CGLM_INLINE
void
glms_persp_decomp_z_lh_zo(mat4s proj,
                          float * __restrict nearZ,
                          float * __restrict farZ) {
  glm_persp_decomp_z_lh_zo(proj.raw, nearZ, farZ);
}

/*!
 * @brief decomposes far value of perspective projection
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] farZ   far
 */
CGLM_INLINE
void
glms_persp_decomp_far_lh_zo(mat4s proj, float * __restrict farZ) {
  glm_persp_decomp_far_lh_zo(proj.raw, farZ);
}

/*!
 * @brief decomposes near value of perspective projection
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *
 * @param[in]  proj  perspective projection matrix
 * @param[out] nearZ near
 */
CGLM_INLINE
void
glms_persp_decomp_near_lh_zo(mat4s proj, float * __restrict nearZ) {
  glm_persp_decomp_near_lh_zo(proj.raw, nearZ);
}

/*!
 * @brief returns field of view angle along the Y-axis (in radians)
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *
 * if you need to degrees, use glm_deg to convert it or use this:
 * fovy_deg = glm_deg(glm_persp_fovy(projMatrix))
 *
 * @param[in] proj perspective projection matrix
 */
CGLM_INLINE
float
glms_persp_fovy_lh_zo(mat4s proj) {
  return glm_persp_fovy_lh_zo(proj.raw);
}

/*!
 * @brief returns aspect ratio of perspective projection
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *
 * @param[in] proj perspective projection matrix
 */
CGLM_INLINE
float
glms_persp_aspect_lh_zo(mat4s proj) {
  return glm_persp_aspect_lh_zo(proj.raw);
}

/*!
 * @brief returns sizes of near and far planes of perspective projection
 *        with a left-hand coordinate system and a
 *        clip-space of [0, 1].
 *
 * @param[in]  proj perspective projection matrix
 * @param[in]  fovy fovy (see brief)
 * @returns    sizes as vector, sizes order: [Wnear, Hnear, Wfar, Hfar]
 */
CGLM_INLINE
vec4s
glms_persp_sizes_lh_zo(mat4s proj, float fovy) {
  vec4s dest;
  glm_persp_sizes_lh_zo(proj.raw, fovy, dest.raw);
  return dest;
}

#endif /* cglms_persp_lh_zo_h */
