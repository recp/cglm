/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_frustum_h
#define cglm_frustum_h

#include "common.h"
#include "plane.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

#define GLM_LBN 0 /* left  bottom near */
#define GLM_LTN 1 /* left  top    near */
#define GLM_RTN 2 /* right top    near */
#define GLM_RBN 3 /* right bottom near */

#define GLM_LBF 4 /* left  bottom far  */
#define GLM_LTF 5 /* left  top    far  */
#define GLM_RTF 6 /* right top    far  */
#define GLM_RBF 7 /* right bottom far  */

#define GLM_LEFT   0
#define GLM_RIGHT  1
#define GLM_BOTTOM 2
#define GLM_TOP    3
#define GLM_NEAR   4
#define GLM_FAR    5

/* you can override clip space coords
   but you have to provide all with same name
   e.g.: define GLM_CSCOORD_LBN {0.0f, 0.0f, 1.0f, 1.0f} */
#ifndef GLM_CUSTOM_CLIPSPACE

/* near */
#define GLM_CSCOORD_LBN {-1.0f, -1.0f, -1.0f, 1.0f}
#define GLM_CSCOORD_LTN {-1.0f,  1.0f, -1.0f, 1.0f}
#define GLM_CSCOORD_RTN { 1.0f,  1.0f, -1.0f, 1.0f}
#define GLM_CSCOORD_RBN { 1.0f, -1.0f, -1.0f, 1.0f}

/* far */
#define GLM_CSCOORD_LBF {-1.0f, -1.0f,  1.0f, 1.0f}
#define GLM_CSCOORD_LTF {-1.0f,  1.0f,  1.0f, 1.0f}
#define GLM_CSCOORD_RTF { 1.0f,  1.0f,  1.0f, 1.0f}
#define GLM_CSCOORD_RBF { 1.0f, -1.0f,  1.0f, 1.0f}

#endif

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
 * @param[out] dest extracted view frustum planes (see brief)
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
 * if you have a near coord at i index, you can get it's far coord by i + 4
 *
 * Find center coordinates:
 *   for (j = 0; j < 4; j++) {
 *     glm_vec3_center(corners[i], corners[i + 4], centerCorners[i]);
 *   }
 *
 * @param[in]  invMat matrix (see brief)
 * @param[out] dest   exracted view frustum corners (see brief)
 */
CGLM_INLINE
void
glm_frustum_corners(mat4 invMat, vec4 dest[8]) {
  vec4 c[8];

  /* indexOf(nearCoord) = indexOf(farCoord) + 4 */
  vec4 csCoords[8] = {
    GLM_CSCOORD_LBN,
    GLM_CSCOORD_LTN,
    GLM_CSCOORD_RTN,
    GLM_CSCOORD_RBN,

    GLM_CSCOORD_LBF,
    GLM_CSCOORD_LTF,
    GLM_CSCOORD_RTF,
    GLM_CSCOORD_RBF
  };

  glm_mat4_mulv(invMat, csCoords[0], c[0]);
  glm_mat4_mulv(invMat, csCoords[1], c[1]);
  glm_mat4_mulv(invMat, csCoords[2], c[2]);
  glm_mat4_mulv(invMat, csCoords[3], c[3]);
  glm_mat4_mulv(invMat, csCoords[4], c[4]);
  glm_mat4_mulv(invMat, csCoords[5], c[5]);
  glm_mat4_mulv(invMat, csCoords[6], c[6]);
  glm_mat4_mulv(invMat, csCoords[7], c[7]);

  glm_vec4_scale(c[0], 1.0f / c[0][3], dest[0]);
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

/*!
 * @brief finds bounding box of frustum relative to given matrix e.g. view mat
 *
 * @param[in]  corners view frustum corners
 * @param[in]  m       matrix to convert existing conners
 * @param[out] box     bounding box as array [min, max]
 */
CGLM_INLINE
void
glm_frustum_box(vec4 corners[8], mat4 m, vec3 box[2]) {
  vec4 v;
  vec3 min, max;
  int  i;

  glm_vec3_broadcast(FLT_MAX, min);
  glm_vec3_broadcast(-FLT_MAX, max);

  for (i = 0; i < 8; i++) {
    glm_mat4_mulv(m, corners[i], v);

    min[0] = glm_min(min[0], v[0]);
    min[1] = glm_min(min[1], v[1]);
    min[2] = glm_min(min[2], v[2]);

    max[0] = glm_max(max[0], v[0]);
    max[1] = glm_max(max[1], v[1]);
    max[2] = glm_max(max[2], v[2]);
  }

  glm_vec3_copy(min, box[0]);
  glm_vec3_copy(max, box[1]);
}

/*!
 * @brief finds planes corners which is between near and far planes (parallel)
 *
 * this will be helpful if you want to split a frustum e.g. CSM/PSSM. This will
 * find planes' corners but you will need to one more plane.
 * Actually you have it, it is near, far or created previously with this func ;)
 *
 * @param[in]  corners view  frustum corners
 * @param[in]  splitDist     split distance
 * @param[in]  farDist       far distance (zFar)
 * @param[out] planeCorners  plane corners [LB, LT, RT, RB]
 */
CGLM_INLINE
void
glm_frustum_corners_at(vec4  corners[8],
                       float splitDist,
                       float farDist,
                       vec4  planeCorners[4]) {
  vec4  corner;
  float dist, sc;

  /* because distance and scale is same for all */
  dist = glm_vec3_distance(corners[GLM_RTF], corners[GLM_RTN]);
  sc   = dist * (splitDist / farDist);

  /* left bottom */
  glm_vec4_sub(corners[GLM_LBF], corners[GLM_LBN], corner);
  glm_vec4_scale_as(corner, sc, corner);
  glm_vec4_add(corners[GLM_LBN], corner, planeCorners[0]);

  /* left top */
  glm_vec4_sub(corners[GLM_LTF], corners[GLM_LTN], corner);
  glm_vec4_scale_as(corner, sc, corner);
  glm_vec4_add(corners[GLM_LTN], corner, planeCorners[1]);

  /* right top */
  glm_vec4_sub(corners[GLM_RTF], corners[GLM_RTN], corner);
  glm_vec4_scale_as(corner, sc, corner);
  glm_vec4_add(corners[GLM_RTN], corner, planeCorners[2]);

  /* right bottom */
  glm_vec4_sub(corners[GLM_RBF], corners[GLM_RBN], corner);
  glm_vec4_scale_as(corner, sc, corner);
  glm_vec4_add(corners[GLM_RBN], corner, planeCorners[3]);
}

#endif /* cglm_frustum_h */
