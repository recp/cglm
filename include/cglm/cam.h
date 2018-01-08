/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void glm_frustum(float left,
                                float right,
                                float bottom,
                                float top,
                                float nearVal,
                                float farVal,
                                mat4  dest);
   CGLM_INLINE void glm_ortho(float left,
                              float right,
                              float bottom,
                              float top,
                              float nearVal,
                              float farVal,
                              mat4  dest);
   CGLM_INLINE void glm_ortho_default(float aspect, mat4  dest);
   CGLM_INLINE void glm_ortho_default_s(float aspect, float size, mat4  dest);
   CGLM_INLINE void glm_perspective(float fovy,
                                    float aspect,
                                    float nearVal,
                                    float farVal,
                                    mat4  dest);
   CGLM_INLINE void glm_perspective_default(float aspect, mat4  dest);
   CGLM_INLINE void glm_perspective_resize(float aspect, mat4  proj);
   CGLM_INLINE void glm_lookat(vec3 eye, vec3 center, vec3 up, mat4 dest);
   CGLM_INLINE void glm_persp_decomp(mat4 proj,
                                     float * __restrict nearVal,
                                     float * __restrict farVal,
                                     float * __restrict top,
                                     float * __restrict bottom,
                                     float * __restrict left,
                                     float * __restrict right);
   CGLM_INLINE void glm_persp_decompv(mat4  proj, float dest[6]);
   CGLM_INLINE void glm_persp_decomp_x(mat4 proj,
                                       float * __restrict left,
                                       float * __restrict right);
   CGLM_INLINE void glm_persp_decomp_y(mat4 proj,
                                       float * __restrict top,
                                       float * __restrict bottom);
   CGLM_INLINE void glm_persp_decomp_z(mat4 proj,
                                       float * __restrict nearVal,
                                       float * __restrict farVal);
   CGLM_INLINE void glm_persp_decomp_far(mat4 proj, float * __restrict farVal);
   CGLM_INLINE void glm_persp_decomp_near(mat4 proj, float *__restrict nearVal);
   CGLM_INLINE void glm_frustum_planes(mat4 m, vec4 dest[6]);
   CGLM_INLINE void glm_frustum_corners(mat4 invMat, vec4 dest[8]);
 */

#ifndef cglm_vcam_h
#define cglm_vcam_h

#include "common.h"
#include "plane.h"

/*!
 * @brief set up perspective peprojection matrix
 *
 * @param[in]  left    viewport.left
 * @param[in]  right   viewport.right
 * @param[in]  bottom  viewport.bottom
 * @param[in]  top     viewport.top
 * @param[in]  nearVal near clipping plane
 * @param[in]  farVal  far clipping plane
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_frustum(float left,
            float right,
            float bottom,
            float top,
            float nearVal,
            float farVal,
            mat4  dest) {
  float rl, tb, fn, nv;

  glm__memzero(float, dest, sizeof(mat4));

  rl = 1.0f / (right  - left);
  tb = 1.0f / (top    - bottom);
  fn =-1.0f / (farVal - nearVal);
  nv = 2.0f * nearVal;

  dest[0][0] = nv * rl;
  dest[1][1] = nv * tb;
  dest[2][0] = (right  + left)    * rl;
  dest[2][1] = (top    + bottom)  * tb;
  dest[2][2] = (farVal + nearVal) * fn;
  dest[2][3] =-1.0f;
  dest[3][2] = farVal * nv * fn;
}

/*!
 * @brief set up orthographic projection matrix
 *
 * @param[in]  left    viewport.left
 * @param[in]  right   viewport.right
 * @param[in]  bottom  viewport.bottom
 * @param[in]  top     viewport.top
 * @param[in]  nearVal near clipping plane
 * @param[in]  farVal  far clipping plane
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_ortho(float left,
          float right,
          float bottom,
          float top,
          float nearVal,
          float farVal,
          mat4  dest) {
  float rl, tb, fn;

  glm__memzero(float, dest, sizeof(mat4));

  rl = 1.0f / (right  - left);
  tb = 1.0f / (top    - bottom);
  fn =-1.0f / (farVal - nearVal);

  dest[0][0] = 2.0f * rl;
  dest[1][1] = 2.0f * tb;
  dest[2][2] = 2.0f * fn;
  dest[3][0] =-(right  + left)    * rl;
  dest[3][1] =-(top    + bottom)  * tb;
  dest[3][2] = (farVal + nearVal) * fn;
  dest[3][3] = 1.0f;
}

/*!
 * @brief set up unit orthographic projection matrix
 *
 * @param[in]  aspect aspect ration ( width / height )
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_ortho_default(float aspect,
                  mat4  dest) {
  if (aspect >= 1.0f) {
    glm_ortho(-1.0f * aspect,
               1.0f * aspect,
              -1.0f,
               1.0f,
              -100.0f,
               100.0f,
               dest);
	  return;
  }

  glm_ortho(-1.0f,
             1.0f,
            -1.0f / aspect,
             1.0f / aspect,
            -100.0f,
             100.0f,
             dest);
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
glm_ortho_default_s(float aspect,
                    float size,
                    mat4  dest) {
  if (aspect >= 1.0f) {
    glm_ortho(-size * aspect,
               size * aspect,
              -size,
               size,
              -size - 100.0f,
               size + 100.0f,
               dest);
	  return;
  }

  glm_ortho(-size,
             size,
            -size / aspect,
             size / aspect,
            -size - 100.0f,
             size + 100.0f,
             dest);
}

/*!
 * @brief set up perspective projection matrix
 *
 * @param[in]  fovy    field of view angle
 * @param[in]  aspect  aspect ratio ( width / height )
 * @param[in]  nearVal near clipping plane
 * @param[in]  farVal  far clipping planes
 * @param[out] dest    result matrix
 */
CGLM_INLINE
void
glm_perspective(float fovy,
                float aspect,
                float nearVal,
                float farVal,
                mat4  dest) {
  float f, fn;

  glm__memzero(float, dest, sizeof(mat4));

  f  = 1.0f / tanf(fovy * 0.5f);
  fn = 1.0f / (nearVal - farVal);

  dest[0][0] = f / aspect;
  dest[1][1] = f;
  dest[2][2] = (nearVal + farVal) * fn;
  dest[2][3] =-1.0f;
  dest[3][2] = 2.0f * nearVal * farVal * fn;
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
glm_perspective_default(float aspect,
                        mat4  dest) {
  glm_perspective((float)CGLM_PI_4,
                  aspect,
                  0.01f,
                  100.0f,
                  dest);
}

/*!
 * @brief resize perspective matrix by aspect ratio ( width / height )
 *        this very make easy to resize proj matrix when window, viewport
 *        reized
 *
 * @param[in]      aspect aspect ratio ( width / height )
 * @param[in, out] proj   perspective projection matrix
 */
CGLM_INLINE
void
glm_perspective_resize(float aspect,
                       mat4  proj) {
  if (proj[0][0] == 0.0f)
    return;

  proj[0][0] = proj[1][1] / aspect;
}

/*!
 * @brief set up view matrix
 *
 * @param[in]  eye    eye vector
 * @param[in]  center center vector
 * @param[in]  up     up vector
 * @param[out] dest   result matrix
 */
CGLM_INLINE
void
glm_lookat(vec3 eye,
           vec3 center,
           vec3 up,
           mat4 dest) {
  vec3 f, u, s;

  glm_vec_sub(center, eye, f);
  glm_vec_normalize(f);

  glm_vec_cross(f, up, s);
  glm_vec_normalize(s);

  glm_vec_cross(s, f, u);

  dest[0][0] = s[0];
  dest[0][1] = u[0];
  dest[0][2] =-f[0];
  dest[1][0] = s[1];
  dest[1][1] = u[1];
  dest[1][2] =-f[1];
  dest[2][0] = s[2];
  dest[2][1] = u[2];
  dest[2][2] =-f[2];
  dest[3][0] =-glm_vec_dot(s, eye);
  dest[3][1] =-glm_vec_dot(u, eye);
  dest[3][2] = glm_vec_dot(f, eye);
  dest[0][3] = dest[1][3] = dest[2][3] = 0.0f;
  dest[3][3] = 1.0f;
}

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
CGLM_INLINE
void
glm_persp_decomp(mat4 proj,
                 float * __restrict nearVal,
                 float * __restrict farVal,
                 float * __restrict top,
                 float * __restrict bottom,
                 float * __restrict left,
                 float * __restrict right) {
  float m00, m11, m20, m21, m22, m32, n, f;
  float n_m11, n_m00;

  m00 = proj[0][0];
  m11 = proj[1][1];
  m20 = proj[2][0];
  m21 = proj[2][1];
  m22 = proj[2][2];
  m32 = proj[3][2];

  n = m32 / (m22 - 1);
  f = m32 / (m22 + 1);

  n_m11 = n / m11;
  n_m00 = n / m00;

  *nearVal = n;
  *farVal  = f;
  *bottom  = n_m11 * (m21 - 1);
  *top     = n_m11 * (m21 + 1);
  *left    = n_m00 * (m20 - 1);
  *right   = n_m00 * (m20 + 1);
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
  glm_persp_decomp(proj, &dest[0], &dest[1], &dest[2],
                         &dest[3], &dest[4], &dest[5]);
}

/*!
 * @brief decomposes left and right values of perspective projection.
 *        x stands for x axis (left / right axis)
 *
 * @param[in]  proj perspective projection matrix
 * @param[out] left  left
 * @param[out] right right
 */
CGLM_INLINE
void
glm_persp_decomp_x(mat4 proj,
                   float * __restrict left,
                   float * __restrict right) {
  float nearVal, m20, m00;

  m00 = proj[0][0];
  m20 = proj[2][0];

  nearVal = proj[3][2] / (proj[3][3] - 1);
  *left   = nearVal * (m20 - 1) / m00;
  *right  = nearVal * (m20 + 1) / m00;
}

/*!
 * @brief decomposes top and bottom values of perspective projection.
 *        y stands for y axis (top / botom axis)
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
  float nearVal, m21, m11;

  m21 = proj[2][1];
  m11 = proj[1][1];

  nearVal = proj[3][2] / (proj[3][3] - 1);
  *bottom = nearVal * (m21 - 1) / m11;
  *top    = nearVal * (m21 + 1) / m11;
}

/*!
 * @brief decomposes near and far values of perspective projection.
 *        z stands for z axis (near / far axis)
 *
 * @param[in]  proj    perspective projection matrix
 * @param[out] nearVal near
 * @param[out] farVal  far
 */
CGLM_INLINE
void
glm_persp_decomp_z(mat4 proj,
                   float * __restrict nearVal,
                   float * __restrict farVal) {
  float m32, m22;

  m32 = proj[3][2];
  m22 = proj[2][2];

  *nearVal = m32 / (m22 - 1);
  *farVal  = m32 / (m22 + 1);
}

/*!
 * @brief decomposes far value of perspective projection.
 *
 * @param[in]  proj   perspective projection matrix
 * @param[out] farVal far
 */
CGLM_INLINE
void
glm_persp_decomp_far(mat4 proj, float * __restrict farVal) {
  *farVal = proj[3][2] / (proj[2][2] + 1.0f);
}

/*!
 * @brief decomposes near value of perspective projection.
 *
 * @param[in]  proj    perspective projection matrix
 * @param[out] nearVal near
 */
CGLM_INLINE
void
glm_persp_decomp_near(mat4 proj, float * __restrict nearVal) {
  *nearVal = proj[3][2] / (proj[2][2] - 1.0f);
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
glm_persp_fovy(mat4 proj) {
  return 2.0f * atanf(1.0f / proj[1][1]);
}

/*!
 * @brief returns aspect ratio of perspective projection
 *
 * @param[in] proj perspective projection matrix
 */
CGLM_INLINE
float
glm_persp_aspect(mat4 proj) {
  return proj[1][1] / proj[0][0];
}

/*!
 * @brief returns aspect ratio of perspective projection
 *
 * if you don't have fovy then use glm_persp_fovy(proj) to get it
 * or pass directly: glm_persp_sizes(proj, glm_persp_fovy(proj), sizes);
 *
 * @param[in]  proj perspective projection matrix
 * @param[in]  fovy fovy (see brief)
 * @param[out] dest sizes order: [Wnear, Hnear, Wfar, Hfar]
 */
CGLM_INLINE
void
glm_persp_sizes(mat4 proj, float fovy, vec4 dest) {
  float t, a, nearVal, farVal;

  t = 2.0f * tanf(fovy * 0.5f);
  a = glm_persp_aspect(proj);

  glm_persp_decomp_z(proj, &nearVal, &farVal);

  dest[1]  = t * nearVal;
  dest[3]  = t * farVal;
  dest[0]  = a * dest[1];
  dest[2]  = a * dest[3];
}

/*!
 * @brief extracts view frustum planes
 *
 * planes' space:
 *  1- if m = proj:     View Space
 *  2- if m = viewProj: World Space
 *  3- if m = MVP:      Object Space
 *
 * You probably want to extract planes in world space so use viewProj as m
 * Computing viewProj:
 *   glm_mat4_mul(proj, view, viewProj);
 *
 * Exracted planes order: [left, right, bottom, top, near, far]
 *
 * @param[in]  m    matrix (see brief)
 * @param[out] dest exracted view frustum planes (see brief)
 */
CGLM_INLINE
void
glm_frustum_planes(mat4 m, vec4 dest[6]) {
  mat4 t;

  glm_mat4_transpose_to(m, t);

  glm_vec4_add(t[3], t[0], dest[0]); /* left   */
  glm_vec4_sub(t[3], t[0], dest[1]); /* right  */
  glm_vec4_add(t[3], t[1], dest[2]); /* bottom */
  glm_vec4_sub(t[3], t[1], dest[3]); /* top    */
  glm_vec4_add(t[3], t[2], dest[4]); /* near   */
  glm_vec4_sub(t[3], t[2], dest[5]); /* far    */

  glm_plane_normalize(dest[0]);
  glm_plane_normalize(dest[1]);
  glm_plane_normalize(dest[2]);
  glm_plane_normalize(dest[3]);
  glm_plane_normalize(dest[4]);
  glm_plane_normalize(dest[5]);
}

/*!
 * @brief extracts view frustum corners using clip-space coordinates
 *
 * corners' space:
 *  1- if m = invViewProj: World Space
 *  2- if m = invMVP:      Object Space
 *
 * You probably want to extract corners in world space so use invViewProj
 * Computing invViewProj:
 *   glm_mat4_mul(proj, view, viewProj);
 *   ...
 *   glm_mat4_inv(viewProj, invViewProj);
 *
 * @param[in]  invMat matrix (see brief)
 * @param[out] dest   exracted view frustum corners (see brief)
 */
CGLM_INLINE
void
glm_frustum_corners(mat4 invMat, vec4 dest[8]) {
  vec4 c[8];
  vec4 csCoords[8] = {
    {-1.0f, -1.0f, -1.0f, 1.0f},
    {-1.0f,  1.0f, -1.0f, 1.0f},
    { 1.0f, -1.0f, -1.0f, 1.0f},
    { 1.0f,  1.0f, -1.0f, 1.0f},
    {-1.0f, -1.0f,  1.0f, 1.0f},
    {-1.0f,  1.0f,  1.0f, 1.0f},
    { 1.0f, -1.0f,  1.0f, 1.0f},
    { 1.0f,  1.0f,  1.0f, 1.0f}
  };

  glm_mat4_mulv(invMat, csCoords[0], c[0]);
  glm_mat4_mulv(invMat, csCoords[1], c[1]);
  glm_mat4_mulv(invMat, csCoords[2], c[2]);
  glm_mat4_mulv(invMat, csCoords[3], c[3]);
  glm_mat4_mulv(invMat, csCoords[4], c[4]);
  glm_mat4_mulv(invMat, csCoords[5], c[5]);
  glm_mat4_mulv(invMat, csCoords[6], c[6]);
  glm_mat4_mulv(invMat, csCoords[7], c[7]);

  glm_vec4_scale(c[1], 1.0f / c[1][3], dest[1]);
  glm_vec4_scale(c[2], 1.0f / c[2][3], dest[2]);
  glm_vec4_scale(c[3], 1.0f / c[3][3], dest[3]);
  glm_vec4_scale(c[4], 1.0f / c[4][3], dest[4]);
  glm_vec4_scale(c[5], 1.0f / c[5][3], dest[5]);
  glm_vec4_scale(c[6], 1.0f / c[6][3], dest[6]);
  glm_vec4_scale(c[7], 1.0f / c[7][3], dest[7]);
}

/*!
 * @brief finds center of view frustum
 *
 * @param[in]  corners view frustum corners
 * @param[out] dest    view frustum center
 */
CGLM_INLINE
void
glm_frustum_center(vec4 corners[8], vec4 dest) {
  vec4 center;

  glm_vec4_copy(corners[0], center);

  glm_vec4_add(corners[1], center, center);
  glm_vec4_add(corners[2], center, center);
  glm_vec4_add(corners[3], center, center);
  glm_vec4_add(corners[4], center, center);
  glm_vec4_add(corners[5], center, center);
  glm_vec4_add(corners[6], center, center);
  glm_vec4_add(corners[7], center, center);

  glm_vec4_scale(center, 0.125f, dest);
}

#endif /* cglm_vcam_h */
