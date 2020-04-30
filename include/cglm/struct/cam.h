/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_DECL mat4s glms_frustum(float left,    float right,
                                  float bottom,  float top,
                                  float nearVal, float farVal)
   CGLM_DECL mat4s glms_ortho(float left,    float right,
                                float bottom,  float top,
                                float nearVal, float farVal)
   CGLM_DECL mat4s glms_ortho_aabb(vec3s box[2]);
   CGLM_DECL mat4s glms_ortho_aabb_p(vec3s box[2],  float padding);
   CGLM_DECL mat4s glms_ortho_aabb_pz(vec3s box[2], float padding);
   CGLM_DECL mat4s glms_ortho_default(float aspect)
   CGLM_DECL mat4s glms_ortho_default_s(float aspect, float size)
   CGLM_DECL mat4s glms_perspective(float fovy,
                                      float aspect,
                                      float nearVal,
                                      float farVal)
   CGLM_DECL void  glms_persp_move_far(mat4s proj, float deltaFar)
   CGLM_DECL mat4s glms_perspective_default(float aspect)
   CGLM_DECL void  glms_perspective_resize(mat4s proj, float aspect)
   CGLM_DECL mat4s glms_lookat(vec3s eye, vec3s center, vec3s up)
   CGLM_DECL mat4s glms_look(vec3s eye, vec3s dir, vec3s up)
   CGLM_DECL mat4s glms_look_anyup(vec3s eye, vec3s dir)
   CGLM_DECL void  glms_persp_decomp(mat4s  proj,
                                       float *nearv, float *farv,
                                       float *top,   float *bottom,
                                       float *left,  float *right)
   CGLM_DECL void  glms_persp_decompv(mat4s proj, float dest[6])
   CGLM_DECL void  glms_persp_decomp_x(mat4s proj, float *left, float *right)
   CGLM_DECL void  glms_persp_decomp_y(mat4s proj, float *top, float *bottom)
   CGLM_DECL void  glms_persp_decomp_z(mat4s proj, float *nearv, float *farv)
   CGLM_DECL void  glms_persp_decomp_far(mat4s proj, float *farVal)
   CGLM_DECL void  glms_persp_decomp_near(mat4s proj, float *nearVal)
   CGLM_DECL float glms_persp_fovy(mat4s proj)
   CGLM_DECL float glms_persp_aspect(mat4s proj)
   CGLM_DECL vec4s glms_persp_sizes(mat4s proj, float fovy)
 */

#ifndef cglms_cam_h
#define cglms_cam_h

#include "../common.h"
#include "../types-struct.h"
#include "../plane.h"
#include "../cam.h"

/*!
 * @brief set up perspective peprojection matrix
 *
 * @param[in]  left    viewport.left
 * @param[in]  right   viewport.right
 * @param[in]  bottom  viewport.bottom
 * @param[in]  top     viewport.top
 * @param[in]  nearVal near clipping plane
 * @param[in]  farVal  far clipping plane
 * @returns    result matrix
 */
CGLM_DECL
mat4s
glms_frustum(float left,    float right,
             float bottom,  float top,
             float nearVal, float farVal) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_frustum(left, right, bottom, top, nearVal, farVal, dest.raw);
  return dest;
}
#endif

/*!
 * @brief set up orthographic projection matrix
 *
 * @param[in]  left    viewport.left
 * @param[in]  right   viewport.right
 * @param[in]  bottom  viewport.bottom
 * @param[in]  top     viewport.top
 * @param[in]  nearVal near clipping plane
 * @param[in]  farVal  far clipping plane
 * @returns    result matrix
 */
CGLM_DECL
mat4s
glms_ortho(float left,    float right,
           float bottom,  float top,
           float nearVal, float farVal) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_ortho(left, right, bottom, top, nearVal, farVal, dest.raw);
  return dest;
}
#endif

/*!
 * @brief set up orthographic projection matrix using bounding box
 *
 * bounding box (AABB) must be in view space
 *
 * @param[in]  box   AABB
 * @returns    result matrix
 */
CGLM_DECL
mat4s
glms_ortho_aabb(vec3s box[2]) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  vec3  rawBox[2];

  glms_vec3_unpack(rawBox, box, 2);
  glm_ortho_aabb(rawBox, dest.raw);

  return dest;
}
#endif

/*!
 * @brief set up orthographic projection matrix using bounding box
 *
 * bounding box (AABB) must be in view space
 *
 * @param[in]  box     AABB
 * @param[in]  padding padding
 * @returns    result matrix
 */
CGLM_DECL
mat4s
glms_ortho_aabb_p(vec3s box[2], float padding) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  vec3  rawBox[2];

  glms_vec3_unpack(rawBox, box, 2);
  glm_ortho_aabb_p(rawBox, padding, dest.raw);

  return dest;
}
#endif

/*!
 * @brief set up orthographic projection matrix using bounding box
 *
 * bounding box (AABB) must be in view space
 *
 * @param[in]  box     AABB
 * @param[in]  padding padding for near and far
 * @returns    result matrix
 */
CGLM_DECL
mat4s
glms_ortho_aabb_pz(vec3s box[2], float padding) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  vec3  rawBox[2];

  glms_vec3_unpack(rawBox, box, 2);
  glm_ortho_aabb_pz(rawBox, padding, dest.raw);

  return dest;
}
#endif

/*!
 * @brief set up unit orthographic projection matrix
 *
 * @param[in]  aspect aspect ration ( width / height )
 * @returns    result matrix
 */
CGLM_DECL
mat4s
glms_ortho_default(float aspect) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_ortho_default(aspect, dest.raw);
  return dest;
}
#endif

/*!
 * @brief set up orthographic projection matrix with given CUBE size
 *
 * @param[in]  aspect aspect ratio ( width / height )
 * @param[in]  size   cube size
 * @returns    result matrix
 */
CGLM_DECL
mat4s
glms_ortho_default_s(float aspect, float size) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_ortho_default_s(aspect, size, dest.raw);
  return dest;
}
#endif

/*!
 * @brief set up perspective projection matrix
 *
 * @param[in]  fovy    field of view angle
 * @param[in]  aspect  aspect ratio ( width / height )
 * @param[in]  nearVal near clipping plane
 * @param[in]  farVal  far clipping planes
 * @returns    result matrix
 */
CGLM_DECL
mat4s
glms_perspective(float fovy, float aspect, float nearVal, float farVal) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_perspective(fovy, aspect, nearVal, farVal, dest.raw);
  return dest;
}
#endif

/*!
 * @brief extend perspective projection matrix's far distance
 *
 * this function does not guarantee far >= near, be aware of that!
 *
 * @param[in, out] proj      projection matrix to extend
 * @param[in]      deltaFar  distance from existing far (negative to shink)
 */
CGLM_DECL
void
glms_persp_move_far(mat4s proj, float deltaFar) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_persp_move_far(proj.raw, deltaFar);
}
#endif

/*!
 * @brief set up perspective projection matrix with default near/far
 *        and angle values
 *
 * @param[in]  aspect aspect ratio ( width / height )
 * @returns    result matrix
 */
CGLM_DECL
mat4s
glms_perspective_default(float aspect) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_perspective_default(aspect, dest.raw);
  return dest;
}
#endif

/*!
 * @brief resize perspective matrix by aspect ratio ( width / height )
 *        this makes very easy to resize proj matrix when window /viewport
 *        reized
 *
 * @param[in, out] proj   perspective projection matrix
 * @param[in]      aspect aspect ratio ( width / height )
 */
CGLM_DECL
void
glms_perspective_resize(mat4s proj, float aspect) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_perspective_resize(aspect, proj.raw);
}
#endif

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
CGLM_DECL
mat4s
glms_lookat(vec3s eye, vec3s center, vec3s up) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_lookat(eye.raw, center.raw, up.raw, dest.raw);
  return dest;
}
#endif

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
CGLM_DECL
mat4s
glms_look(vec3s eye, vec3s dir, vec3s up) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_look(eye.raw, dir.raw, up.raw, dest.raw);
  return dest;
}
#endif

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
CGLM_DECL
mat4s
glms_look_anyup(vec3s eye, vec3s dir) CGLM_ENDD
#ifndef CGLM_LIB
{
  mat4s dest;
  glm_look_anyup(eye.raw, dir.raw, dest.raw);
  return dest;
}
#endif

/*!
 * @brief decomposes frustum values of perspective projection.
 *
 * @param[in]  proj    perspective projection matrix
 * @param[out] nearVal near
 * @param[out] farVal  far
 * @param[out] top     top
 * @param[out] bottom  bottom
 * @param[out] left    left
 * @param[out] right   right
 */
CGLM_DECL
void
glms_persp_decomp(mat4s proj,
                  float * __restrict nearVal, float * __restrict farVal,
                  float * __restrict top,     float * __restrict bottom,
                  float * __restrict left,    float * __restrict right) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_persp_decomp(proj.raw, nearVal, farVal, top, bottom, left, right);
}
#endif

/*!
 * @brief decomposes frustum values of perspective projection.
 *        this makes easy to get all values at once
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] dest   array
 */
CGLM_DECL
void
glms_persp_decompv(mat4s proj, float dest[6]) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_persp_decompv(proj.raw, dest);
}
#endif

/*!
 * @brief decomposes left and right values of perspective projection.
 *        x stands for x axis (left / right axis)
 *
 * @param[in]  proj  perspective projection matrix
 * @param[out] left  left
 * @param[out] right right
 */
CGLM_DECL
void
glms_persp_decomp_x(mat4s proj,
                    float * __restrict left,
                    float * __restrict right) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_persp_decomp_x(proj.raw, left, right);
}
#endif

/*!
 * @brief decomposes top and bottom values of perspective projection.
 *        y stands for y axis (top / botom axis)
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] top    top
 * @param[out] bottom bottom
 */
CGLM_DECL
void
glms_persp_decomp_y(mat4s proj,
                    float * __restrict top,
                    float * __restrict bottom) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_persp_decomp_y(proj.raw, top, bottom);
}
#endif

/*!
 * @brief decomposes near and far values of perspective projection.
 *        z stands for z axis (near / far axis)
 *
 * @param[in]  proj    perspective projection matrix
 * @param[out] nearVal near
 * @param[out] farVal  far
 */
CGLM_DECL
void
glms_persp_decomp_z(mat4s proj,
                    float * __restrict nearVal,
                    float * __restrict farVal) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_persp_decomp_z(proj.raw, nearVal, farVal);
}
#endif

/*!
 * @brief decomposes far value of perspective projection.
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] farVal far
 */
CGLM_DECL
void
glms_persp_decomp_far(mat4s proj, float * __restrict farVal) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_persp_decomp_far(proj.raw, farVal);
}
#endif

/*!
 * @brief decomposes near value of perspective projection.
 *
 * @param[in]  proj    perspective projection matrix
 * @param[out] nearVal near
 */
CGLM_DECL
void
glms_persp_decomp_near(mat4s proj, float * __restrict nearVal) CGLM_ENDD
#ifndef CGLM_LIB
{
  glm_persp_decomp_near(proj.raw, nearVal);
}
#endif

/*!
 * @brief returns field of view angle along the Y-axis (in radians)
 *
 * if you need to degrees, use glm_deg to convert it or use this:
 * fovy_deg = glm_deg(glm_persp_fovy(projMatrix))
 *
 * @param[in] proj perspective projection matrix
 */
CGLM_DECL
float
glms_persp_fovy(mat4s proj) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_persp_fovy(proj.raw);
}
#endif

/*!
 * @brief returns aspect ratio of perspective projection
 *
 * @param[in] proj perspective projection matrix
 */
CGLM_DECL
float
glms_persp_aspect(mat4s proj) CGLM_ENDD
#ifndef CGLM_LIB
{
  return glm_persp_aspect(proj.raw);
}
#endif

/*!
 * @brief returns sizes of near and far planes of perspective projection
 *
 * @param[in]  proj perspective projection matrix
 * @param[in]  fovy fovy (see brief)
 * @returns    sizes as vector, sizes order: [Wnear, Hnear, Wfar, Hfar]
 */
CGLM_DECL
vec4s
glms_persp_sizes(mat4s proj, float fovy) CGLM_ENDD
#ifndef CGLM_LIB
{
  vec4s dest;
  glm_persp_sizes(proj.raw, fovy, dest.raw);
  return dest;
}
#endif

#endif /* cglms_cam_h */
