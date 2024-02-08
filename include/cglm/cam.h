/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void  glm_frustum(float left,   float right,
                                 float bottom, float top,
                                 float nearZ,  float farZ,
                                 mat4  dest)
   CGLM_INLINE void  glm_ortho(float left,   float right,
                               float bottom, float top,
                               float nearZ,  float farZ,
                               mat4  dest)
   CGLM_INLINE void  glm_ortho_aabb(vec3 box[2], mat4 dest)
   CGLM_INLINE void  glm_ortho_aabb_p(vec3 box[2],  float padding, mat4 dest)
   CGLM_INLINE void  glm_ortho_aabb_pz(vec3 box[2], float padding, mat4 dest)
   CGLM_INLINE void  glm_ortho_default(float aspect, mat4  dest)
   CGLM_INLINE void  glm_ortho_default_s(float aspect, float size, mat4 dest)
   CGLM_INLINE void  glm_perspective(float fovy,
                                     float aspect,
                                     float nearZ,
                                     float farZ,
                                     mat4  dest)
   CGLM_INLINE void  glm_perspective_default(float aspect, mat4 dest)
   CGLM_INLINE void  glm_perspective_resize(float aspect, mat4 proj)
   CGLM_INLINE void  glm_lookat(vec3 eye, vec3 center, vec3 up, mat4 dest)
   CGLM_INLINE void  glm_look(vec3 eye, vec3 dir, vec3 up, mat4 dest)
   CGLM_INLINE void  glm_look_anyup(vec3 eye, vec3 dir, mat4 dest)
   CGLM_INLINE void  glm_persp_decomp(mat4   proj,
                                      float *nearZ, float *farZ,
                                      float *top,   float *bottom,
                                      float *left,  float *right)
   CGLM_INLINE void  glm_persp_decompv(mat4 proj, float dest[6])
   CGLM_INLINE void  glm_persp_decomp_x(mat4 proj, float *left, float *right)
   CGLM_INLINE void  glm_persp_decomp_y(mat4 proj, float *top,  float *bottom)
   CGLM_INLINE void  glm_persp_decomp_z(mat4 proj, float *nearv, float *farv)
   CGLM_INLINE void  glm_persp_decomp_far(mat4 proj, float *farZ)
   CGLM_INLINE void  glm_persp_decomp_near(mat4 proj, float *nearZ)
   CGLM_INLINE float glm_persp_fovy(mat4 proj)
   CGLM_INLINE float glm_persp_aspect(mat4 proj)
   CGLM_INLINE void  glm_persp_sizes(mat4 proj, float fovy, vec4 dest)
 */

#ifndef cglm_cam_h
#define cglm_cam_h

#include "common.h"
#include "plane.h"

#include "clipspace/persp.h"

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
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_frustum(float left,    float right,
            float bottom,  float top,
            float nearZ,   float farZ,
            mat4  dest) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_frustum_lh_zo(left, right, bottom, top, nearZ, farZ, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_frustum_lh_no(left, right, bottom, top, nearZ, farZ, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_frustum_rh_zo(left, right, bottom, top, nearZ, farZ, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_frustum_rh_no(left, right, bottom, top, nearZ, farZ, dest);
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
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_ortho(float left,    float right,
          float bottom,  float top,
          float nearZ,   float farZ,
          mat4  dest) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_ortho_lh_zo(left, right, bottom, top, nearZ, farZ, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_ortho_lh_no(left, right, bottom, top, nearZ, farZ, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_ortho_rh_zo(left, right, bottom, top, nearZ, farZ, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_ortho_rh_no(left, right, bottom, top, nearZ, farZ, dest);
#endif
}

/*!
 * @brief set up orthographic projection matrix using bounding box
 *
 * bounding box (AABB) must be in view space
 *
 * @param[in]  box   AABB
 * @param[out] dest  result matrix
 */
CGLM_INLINE
void
glm_ortho_aabb(vec3 box[2], mat4 dest) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_ortho_aabb_lh_zo(box, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_ortho_aabb_lh_no(box, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_ortho_aabb_rh_zo(box, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_ortho_aabb_rh_no(box, dest);
#endif
}

/*!
 * @brief set up orthographic projection matrix using bounding box
 *
 * bounding box (AABB) must be in view space
 *
 * @param[in]  box     AABB
 * @param[in]  padding padding
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_ortho_aabb_p(vec3 box[2], float padding, mat4 dest) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_ortho_aabb_p_lh_zo(box, padding, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_ortho_aabb_p_lh_no(box, padding, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_ortho_aabb_p_rh_zo(box, padding, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_ortho_aabb_p_rh_no(box, padding, dest);
#endif
}

/*!
 * @brief set up orthographic projection matrix using bounding box
 *
 * bounding box (AABB) must be in view space
 *
 * @param[in]  box     AABB
 * @param[in]  padding padding for near and far
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_ortho_aabb_pz(vec3 box[2], float padding, mat4 dest) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_ortho_aabb_pz_lh_zo(box, padding, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_ortho_aabb_pz_lh_no(box, padding, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_ortho_aabb_pz_rh_zo(box, padding, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_ortho_aabb_pz_rh_no(box, padding, dest);
#endif
}

/*!
 * @brief set up unit orthographic projection matrix
 *
 * @param[in]  aspect aspect ration ( width / height )
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_ortho_default(float aspect, mat4 dest) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_ortho_default_lh_zo(aspect, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_ortho_default_lh_no(aspect, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_ortho_default_rh_zo(aspect, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_ortho_default_rh_no(aspect, dest);
#endif
}

/*!
 * @brief set up orthographic projection matrix with given CUBE size
 *
 * @param[in]  aspect aspect ratio ( width / height )
 * @param[in]  size   cube size
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_ortho_default_s(float aspect, float size, mat4 dest) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_ortho_default_s_lh_zo(aspect, size, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_ortho_default_s_lh_no(aspect, size, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_ortho_default_s_rh_zo(aspect, size, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_ortho_default_s_rh_no(aspect, size, dest);
#endif
}

/*!
 * @brief set up perspective projection matrix
 *
 * @param[in]  fovy    field of view angle
 * @param[in]  aspect  aspect ratio ( width / height )
 * @param[in]  nearZ   near clipping plane
 * @param[in]  farZ    far clipping planes
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_perspective(float fovy, float aspect, float nearZ, float farZ, mat4 dest) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_perspective_lh_zo(fovy, aspect, nearZ, farZ, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_perspective_lh_no(fovy, aspect, nearZ, farZ, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_perspective_rh_zo(fovy, aspect, nearZ, farZ, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_perspective_rh_no(fovy, aspect, nearZ, farZ, dest);
#endif
}

/*!
 * @brief extend perspective projection matrix's far distance
 *
 * this function does not guarantee far >= near, be aware of that!
 *
 * @param[in, out] proj      projection matrix to extend
 * @param[in]      deltaFar  distance from existing far (negative to shink)
 */
CGLM_INLINE
void
glm_persp_move_far(mat4 proj, float deltaFar) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_persp_move_far_lh_zo(proj, deltaFar);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_persp_move_far_lh_no(proj, deltaFar);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_persp_move_far_rh_zo(proj, deltaFar);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_persp_move_far_rh_no(proj, deltaFar);
#endif
}

/*!
 * @brief set up perspective projection matrix with default near/far
 *        and angle values
 *
 * @param[in]  aspect aspect ratio ( width / height )
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_perspective_default(float aspect, mat4 dest) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_perspective_default_lh_zo(aspect, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_perspective_default_lh_no(aspect, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_perspective_default_rh_zo(aspect, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_perspective_default_rh_no(aspect, dest);
#endif
}

/*!
 * @brief resize perspective matrix by aspect ratio ( width / height )
 *        this makes very easy to resize proj matrix when window /viewport
 *        reized
 *
 * @param[in]      aspect aspect ratio ( width / height )
 * @param[in, out] proj   perspective projection matrix
 */
CGLM_INLINE
void
glm_perspective_resize(float aspect, mat4 proj) {
  if (proj[0][0] == 0.0f)
    return;

  proj[0][0] = proj[1][1] / aspect;
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
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_lookat(vec3 eye, vec3 center, vec3 up, mat4 dest) {
#if CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_LH_BIT
  glm_lookat_lh(eye, center, up, dest);
#elif CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_RH_BIT
  glm_lookat_rh(eye, center, up, dest);
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
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_look(vec3 eye, vec3 dir, vec3 up, mat4 dest) {
#if CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_LH_BIT
  glm_look_lh(eye, dir, up, dest);
#elif CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_RH_BIT
  glm_look_rh(eye, dir, up, dest);
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
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_look_anyup(vec3 eye, vec3 dir, mat4 dest) {
#if CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_LH_BIT
  glm_look_anyup_lh(eye, dir, dest);
#elif CGLM_CONFIG_CLIP_CONTROL & CGLM_CLIP_CONTROL_RH_BIT
  glm_look_anyup_rh(eye, dir, dest);
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
glm_persp_decomp(mat4 proj,
                 float * __restrict nearZ, float * __restrict farZ,
                 float * __restrict top,   float * __restrict bottom,
                 float * __restrict left,  float * __restrict right) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_persp_decomp_lh_zo(proj, nearZ, farZ, top, bottom, left, right);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_persp_decomp_lh_no(proj, nearZ, farZ, top, bottom, left, right);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_persp_decomp_rh_zo(proj, nearZ, farZ, top, bottom, left, right);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_persp_decomp_rh_no(proj, nearZ, farZ, top, bottom, left, right);
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
glm_persp_decompv(mat4 proj, float dest[6]) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_persp_decompv_lh_zo(proj, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_persp_decompv_lh_no(proj, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_persp_decompv_rh_zo(proj, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_persp_decompv_rh_no(proj, dest);
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
glm_persp_decomp_x(mat4 proj,
                   float * __restrict left,
                   float * __restrict right) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_persp_decomp_x_lh_zo(proj, left, right);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_persp_decomp_x_lh_no(proj, left, right);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_persp_decomp_x_rh_zo(proj, left, right);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_persp_decomp_x_rh_no(proj, left, right);
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
glm_persp_decomp_y(mat4 proj,
                   float * __restrict top,
                   float * __restrict bottom) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_persp_decomp_y_lh_zo(proj, top, bottom);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_persp_decomp_y_lh_no(proj, top, bottom);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_persp_decomp_y_rh_zo(proj, top, bottom);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_persp_decomp_y_rh_no(proj, top, bottom);
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
glm_persp_decomp_z(mat4 proj, float * __restrict nearZ, float * __restrict farZ) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_persp_decomp_z_lh_zo(proj, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_persp_decomp_z_lh_no(proj, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_persp_decomp_z_rh_zo(proj, nearZ, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_persp_decomp_z_rh_no(proj, nearZ, farZ);
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
glm_persp_decomp_far(mat4 proj, float * __restrict farZ) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_persp_decomp_far_lh_zo(proj, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_persp_decomp_far_lh_no(proj, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_persp_decomp_far_rh_zo(proj, farZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_persp_decomp_far_rh_no(proj, farZ);
#endif
}

/*!
 * @brief decomposes near value of perspective projection.
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] nearZ  near
 */
CGLM_INLINE
void
glm_persp_decomp_near(mat4 proj, float * __restrict nearZ) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_persp_decomp_near_lh_zo(proj, nearZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_persp_decomp_near_lh_no(proj, nearZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_persp_decomp_near_rh_zo(proj, nearZ);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_persp_decomp_near_rh_no(proj, nearZ);
#endif
}

/*!
 * @brief returns sizes of near and far planes of perspective projection
 *
 * @param[in]  proj perspective projection matrix
 * @param[in]  fovy fovy (see brief)
 * @param[out] dest sizes order: [Wnear, Hnear, Wfar, Hfar]
 */
CGLM_INLINE
void
glm_persp_sizes(mat4 proj, float fovy, vec4 dest) {
#if CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_ZO
  glm_persp_sizes_lh_zo(proj, fovy, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_LH_NO
  glm_persp_sizes_lh_no(proj, fovy, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_ZO
  glm_persp_sizes_rh_zo(proj, fovy, dest);
#elif CGLM_CONFIG_CLIP_CONTROL == CGLM_CLIP_CONTROL_RH_NO
  glm_persp_sizes_rh_no(proj, fovy, dest);
#endif
}

#endif /* cglm_cam_h */
