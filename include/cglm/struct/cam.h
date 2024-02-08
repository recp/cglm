/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE mat4s glms_frustum(float left,    float right,
                                  float bottom,  float top,
                                  float nearZ,   float farZ)
   CGLM_INLINE mat4s glms_ortho(float left,    float right,
                                float bottom,  float top,
                                float nearZ,   float farZ)
   CGLM_INLINE mat4s glms_ortho_aabb(vec3s box[2]);
   CGLM_INLINE mat4s glms_ortho_aabb_p(vec3s box[2],  float padding);
   CGLM_INLINE mat4s glms_ortho_aabb_pz(vec3s box[2], float padding);
   CGLM_INLINE mat4s glms_ortho_default(float aspect)
   CGLM_INLINE mat4s glms_ortho_default_s(float aspect, float size)
   CGLM_INLINE mat4s glms_perspective(float fovy,
                                      float aspect,
                                      float nearZ,
                                      float farZ)
   CGLM_INLINE void  glms_persp_move_far(mat4s proj, float deltaFar)
   CGLM_INLINE mat4s glms_perspective_default(float aspect)
   CGLM_INLINE void  glms_perspective_resize(mat4s proj, float aspect)
   CGLM_INLINE mat4s glms_lookat(vec3s eye, vec3s center, vec3s up)
   CGLM_INLINE mat4s glms_look(vec3s eye, vec3s dir, vec3s up)
   CGLM_INLINE mat4s glms_look_anyup(vec3s eye, vec3s dir)
   CGLM_INLINE void  glms_persp_decomp(mat4s  proj,
                                       float *nearv, float *farv,
                                       float *top,   float *bottom,
                                       float *left,  float *right)
   CGLM_INLINE void  glms_persp_decompv(mat4s proj, float dest[6])
   CGLM_INLINE void  glms_persp_decomp_x(mat4s proj, float *left, float *right)
   CGLM_INLINE void  glms_persp_decomp_y(mat4s proj, float *top, float *bottom)
   CGLM_INLINE void  glms_persp_decomp_z(mat4s proj, float *nearv, float *farv)
   CGLM_INLINE void  glms_persp_decomp_far(mat4s proj, float *farZ)
   CGLM_INLINE void  glms_persp_decomp_near(mat4s proj, float *nearZ)
   CGLM_INLINE float glms_persp_fovy(mat4s proj)
   CGLM_INLINE float glms_persp_aspect(mat4s proj)
   CGLM_INLINE vec4s glms_persp_sizes(mat4s proj, float fovy)
 */

#ifndef cglms_cam_h
#define cglms_cam_h

#include "../common.h"
#include "../types-struct.h"
#include "../plane.h"
#include "../cam.h"

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
 * @brief set up perspective peprojection matrix
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
glms_frustum(float left,   float right,
             float bottom, float top,
             float nearZ,  float farZ) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_frustum_lh_zo(left, right, bottom, top, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_frustum_lh_no(left, right, bottom, top, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_frustum_rh_zo(left, right, bottom, top, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_frustum_rh_no(left, right, bottom, top, nearZ, farZ);
#endif
}

/*!
 * @brief set up orthographic projection matrix
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
glms_ortho(float left,   float right,
           float bottom, float top,
           float nearZ,  float farZ) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_ortho_lh_zo(left, right, bottom, top, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_ortho_lh_no(left, right, bottom, top, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_ortho_rh_zo(left, right, bottom, top, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_ortho_rh_no(left, right, bottom, top, nearZ, farZ);
#endif
}

/*!
 * @brief set up orthographic projection matrix using bounding box
 *
 * bounding box (AABB) must be in view space
 *
 * @param[in]  box   AABB
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_ortho_aabb(vec3s box[2]) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_ortho_aabb_lh_zo(box);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_ortho_aabb_lh_no(box);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_ortho_aabb_rh_zo(box);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_ortho_aabb_rh_no(box);
#endif
}

/*!
 * @brief set up orthographic projection matrix using bounding box
 *
 * bounding box (AABB) must be in view space
 *
 * @param[in]  box     AABB
 * @param[in]  padding padding
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_ortho_aabb_p(vec3s box[2], float padding) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_ortho_aabb_p_lh_zo(box, padding);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_ortho_aabb_p_lh_no(box, padding);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_ortho_aabb_p_rh_zo(box, padding);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_ortho_aabb_p_rh_no(box, padding);
#endif
}

/*!
 * @brief set up orthographic projection matrix using bounding box
 *
 * bounding box (AABB) must be in view space
 *
 * @param[in]  box     AABB
 * @param[in]  padding padding for near and far
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_ortho_aabb_pz(vec3s box[2], float padding) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_ortho_aabb_pz_lh_zo(box, padding);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_ortho_aabb_pz_lh_no(box, padding);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_ortho_aabb_pz_rh_zo(box, padding);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_ortho_aabb_pz_rh_no(box, padding);
#endif
}

/*!
 * @brief set up unit orthographic projection matrix
 *
 * @param[in]  aspect aspect ration ( width / height )
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_ortho_default(float aspect) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_ortho_default_lh_zo(aspect);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_ortho_default_lh_no(aspect);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_ortho_default_rh_zo(aspect);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_ortho_default_rh_no(aspect);
#endif
}

/*!
 * @brief set up orthographic projection matrix with given CUBE size
 *
 * @param[in]  aspect aspect ratio ( width / height )
 * @param[in]  size   cube size
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_ortho_default_s(float aspect, float size) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_ortho_default_s_lh_zo(aspect, size);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_ortho_default_s_lh_no(aspect, size);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_ortho_default_s_rh_zo(aspect, size);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_ortho_default_s_rh_no(aspect, size);
#endif
}

/*!
 * @brief set up perspective projection matrix
 *
 * @param[in]  fovy    field of view angle
 * @param[in]  aspect  aspect ratio ( width / height )
 * @param[in]  nearZ   near clipping plane
 * @param[in]  farZ    far clipping planes
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_perspective(float fovy, float aspect, float nearZ, float farZ) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_perspective_lh_zo(fovy, aspect, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_perspective_lh_no(fovy, aspect, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_perspective_rh_zo(fovy, aspect, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_perspective_rh_no(fovy, aspect, nearZ, farZ);
#endif
}

/*!
 * @brief extend perspective projection matrix's far distance
 *
 * NOTE: if you dodn't want to create new matrix then use array api on struct.raw
 *       like glm_persp_move_far(prooj.raw, deltaFar) to avoid create new mat4
 *       each time
 *
 * this function does not guarantee far >= near, be aware of that!
 *
 * @param[in, out] proj      projection matrix to extend
 * @param[in]      deltaFar  distance from existing far (negative to shink)
 */
CGLM_INLINE
mat4s
glms_persp_move_far(mat4s proj, float deltaFar) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_persp_move_far_lh_zo(proj, deltaFar);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_persp_move_far_lh_no(proj, deltaFar);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_persp_move_far_rh_zo(proj, deltaFar);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_persp_move_far_rh_no(proj, deltaFar);
#endif
}

/*!
 * @brief set up perspective projection matrix with default near/far
 *        and angle values
 *
 * @param[in]  aspect aspect ratio ( width / height )
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_perspective_default(float aspect) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_perspective_default_lh_zo(aspect);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_perspective_default_lh_no(aspect);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_perspective_default_rh_zo(aspect);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_perspective_default_rh_no(aspect);
#endif
}

/*!
 * @brief resize perspective matrix by aspect ratio ( width / height )
 *        this makes very easy to resize proj matrix when window /viewport
 *        reized
 *
 * NOTE: if you dodn't want to create new matrix then use array api on struct.raw
 *       like glms_perspective_resize(proj.raw, aspect) to avoid create new mat4
 *       each time
 *
 * @param[in, out] proj   perspective projection matrix
 * @param[in]      aspect aspect ratio ( width / height )
 */
CGLM_INLINE
mat4s
glms_perspective_resize(mat4s proj, float aspect) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_perspective_resize_lh_zo(proj, aspect);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_perspective_resize_lh_no(proj, aspect);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_perspective_resize_rh_zo(proj, aspect);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_perspective_resize_rh_no(proj, aspect);
#endif
}

/*!
 * @brief set up view matrix
 *
 * NOTE: The UP vector must not be parallel to the line of sight from
 *       the eye point to the reference point
 *
 * @param[in]  eye    eye vector
 * @param[in]  center center vector
 * @param[in]  up     up vector
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_lookat(vec3s eye, vec3s center, vec3s up) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_lookat_lh_zo(eye, center, up);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_lookat_lh_no(eye, center, up);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_lookat_rh_zo(eye, center, up);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_lookat_rh_no(eye, center, up);
#endif
}

/*!
 * @brief set up view matrix
 *
 * convenient wrapper for lookat: if you only have direction not target self
 * then this might be useful. Because you need to get target from direction.
 *
 * NOTE: The UP vector must not be parallel to the line of sight from
 *       the eye point to the reference point
 *
 * @param[in]  eye    eye vector
 * @param[in]  dir    direction vector
 * @param[in]  up     up vector
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_look(vec3s eye, vec3s dir, vec3s up) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_look_lh_zo(eye, dir, up);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_look_lh_no(eye, dir, up);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_look_rh_zo(eye, dir, up);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_look_rh_no(eye, dir, up);
#endif
}

/*!
 * @brief set up view matrix
 *
 * convenient wrapper for look: if you only have direction and if you don't
 * care what UP vector is then this might be useful to create view matrix
 *
 * @param[in]  eye    eye vector
 * @param[in]  dir    direction vector
 * @returns    result matrix
 */
CGLM_INLINE
mat4s
glms_look_anyup(vec3s eye, vec3s dir) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_look_anyup_lh_zo(eye, dir);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_look_anyup_lh_no(eye, dir);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_look_anyup_rh_zo(eye, dir);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_look_anyup_rh_no(eye, dir);
#endif
}

/*!
 * @brief decomposes frustum values of perspective projection.
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
glms_persp_decomp(mat4s proj,
                  float * __restrict nearZ, float * __restrict farZ,
                  float * __restrict top,   float * __restrict bottom,
                  float * __restrict left,  float * __restrict right) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glms_persp_decomp_lh_zo(proj, nearZ, farZ, top, bottom, left, right);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glms_persp_decomp_lh_no(proj, nearZ, farZ, top, bottom, left, right);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glms_persp_decomp_rh_zo(proj, nearZ, farZ, top, bottom, left, right);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glms_persp_decomp_rh_no(proj, nearZ, farZ, top, bottom, left, right);
#endif
}

/*!
 * @brief decomposes frustum values of perspective projection.
 *        this makes easy to get all values at once
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] dest   array
 */
CGLM_INLINE
void
glms_persp_decompv(mat4s proj, float dest[6]) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glms_persp_decompv_lh_zo(proj, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glms_persp_decompv_lh_no(proj, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glms_persp_decompv_rh_zo(proj, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glms_persp_decompv_rh_no(proj, dest);
#endif
}

/*!
 * @brief decomposes left and right values of perspective projection.
 *        x stands for x axis (left / right axis)
 *
 * @param[in]  proj  perspective projection matrix
 * @param[out] left  left
 * @param[out] right right
 */
CGLM_INLINE
void
glms_persp_decomp_x(mat4s proj,
                    float * __restrict left,
                    float * __restrict right) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glms_persp_decomp_x_lh_zo(proj, left, right);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glms_persp_decomp_x_lh_no(proj, left, right);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glms_persp_decomp_x_rh_zo(proj, left, right);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glms_persp_decomp_x_rh_no(proj, left, right);
#endif
}

/*!
 * @brief decomposes top and bottom values of perspective projection.
 *        y stands for y axis (top / bottom axis)
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] top    top
 * @param[out] bottom bottom
 */
CGLM_INLINE
void
glms_persp_decomp_y(mat4s proj,
                    float * __restrict top,
                    float * __restrict bottom) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glms_persp_decomp_y_lh_zo(proj, top, bottom);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glms_persp_decomp_y_lh_no(proj, top, bottom);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glms_persp_decomp_y_rh_zo(proj, top, bottom);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glms_persp_decomp_y_rh_no(proj, top, bottom);
#endif
}

/*!
 * @brief decomposes near and far values of perspective projection.
 *        z stands for z axis (near / far axis)
 *
 * @param[in]  proj    perspective projection matrix
 * @param[out] nearZ   near
 * @param[out] farZ    far
 */
CGLM_INLINE
void
glms_persp_decomp_z(mat4s proj,
                    float * __restrict nearZ,
                    float * __restrict farZ) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glms_persp_decomp_z_lh_zo(proj, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glms_persp_decomp_z_lh_no(proj, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glms_persp_decomp_z_rh_zo(proj, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glms_persp_decomp_z_rh_no(proj, nearZ, farZ);
#endif
}

/*!
 * @brief decomposes far value of perspective projection.
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] farZ   far
 */
CGLM_INLINE
void
glms_persp_decomp_far(mat4s proj, float * __restrict farZ) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glms_persp_decomp_far_lh_zo(proj, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glms_persp_decomp_far_lh_no(proj, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glms_persp_decomp_far_rh_zo(proj, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glms_persp_decomp_far_rh_no(proj, farZ);
#endif
}

/*!
 * @brief decomposes near value of perspective projection.
 *
 * @param[in]  proj  perspective projection matrix
 * @param[out] nearZ near
 */
CGLM_INLINE
void
glms_persp_decomp_near(mat4s proj, float * __restrict nearZ) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glms_persp_decomp_near_lh_zo(proj, nearZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glms_persp_decomp_near_lh_no(proj, nearZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glms_persp_decomp_near_rh_zo(proj, nearZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glms_persp_decomp_near_rh_no(proj, nearZ);
#endif
}

/*!
 * @brief returns field of view angle along the Y-axis (in radians)
 *
 * if you need to degrees, use glm_deg to convert it or use this:
 * fovy_deg = glm_deg(glm_persp_fovy(projMatrix))
 *
 * @param[in] proj perspective projection matrix
 */
CGLM_INLINE
float
glms_persp_fovy(mat4s proj) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_persp_fovy_lh_zo(proj);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_persp_fovy_lh_no(proj);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_persp_fovy_rh_zo(proj);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_persp_fovy_rh_no(proj);
#endif
}

/*!
 * @brief returns aspect ratio of perspective projection
 *
 * @param[in] proj perspective projection matrix
 */
CGLM_INLINE
float
glms_persp_aspect(mat4s proj) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_persp_aspect_lh_zo(proj);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_persp_aspect_lh_no(proj);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_persp_aspect_rh_zo(proj);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_persp_aspect_rh_no(proj);
#endif
}

/*!
 * @brief returns sizes of near and far planes of perspective projection
 *
 * @param[in]  proj perspective projection matrix
 * @param[in]  fovy fovy (see brief)
 * @returns    sizes as vector, sizes order: [Wnear, Hnear, Wfar, Hfar]
 */
CGLM_INLINE
vec4s
glms_persp_sizes(mat4s proj, float fovy) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  return glms_persp_sizes_lh_zo(proj, fovy);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  return glms_persp_sizes_lh_no(proj, fovy);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  return glms_persp_sizes_rh_zo(proj, fovy);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  return glms_persp_sizes_rh_no(proj, fovy);
#endif
}

#endif /* cglms_cam_h */
