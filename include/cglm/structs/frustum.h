/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_frustums_h
#define cglm_frustums_h

#include "../common.h"
#include "../types-struct.h"
#include "../frustum.h"
#include "plane.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

/* you can override clip space coords
   but you have to provide all with same name
   e.g.: define GLM_CSCOORD_LBN {0.0f, 0.0f, 1.0f, 1.0f} */
#ifndef GLM_CUSTOM_CLIPSPACE

/* near */
#define GLMS_CSCOORD_LBN {-1.0f, -1.0f, -1.0f, 1.0f}
#define GLMS_CSCOORD_LTN {-1.0f,  1.0f, -1.0f, 1.0f}
#define GLMS_CSCOORD_RTN { 1.0f,  1.0f, -1.0f, 1.0f}
#define GLMS_CSCOORD_RBN { 1.0f, -1.0f, -1.0f, 1.0f}

/* far */
#define GLMS_CSCOORD_LBF {-1.0f, -1.0f,  1.0f, 1.0f}
#define GLMS_CSCOORD_LTF {-1.0f,  1.0f,  1.0f, 1.0f}
#define GLMS_CSCOORD_RTF { 1.0f,  1.0f,  1.0f, 1.0f}
#define GLMS_CSCOORD_RBF { 1.0f, -1.0f,  1.0f, 1.0f}

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
glms_frustum_planes(mat4s m, vec4s dest[6]) {
  mat4s t;

  t = glms_mat4_transpose(m);

  dest[0] = glms_vec4_add(t.col[3], t.col[0]); /* left   */
  dest[1] = glms_vec4_sub(t.col[3], t.col[0]); /* right  */
  dest[2] = glms_vec4_add(t.col[3], t.col[1]); /* bottom */
  dest[3] = glms_vec4_sub(t.col[3], t.col[1]); /* top    */
  dest[4] = glms_vec4_add(t.col[3], t.col[2]); /* near   */
  dest[5] = glms_vec4_sub(t.col[3], t.col[2]); /* far    */

  dest[0] = glms_plane_normalize(dest[0]);
  dest[1] = glms_plane_normalize(dest[1]);
  dest[2] = glms_plane_normalize(dest[2]);
  dest[3] = glms_plane_normalize(dest[3]);
  dest[4] = glms_plane_normalize(dest[4]);
  dest[5] = glms_plane_normalize(dest[5]);
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
glms_frustum_corners(mat4s invMat, vec4s dest[8]) {
  vec4s c[8];

  /* indexOf(nearCoord) = indexOf(farCoord) + 4 */
  vec4s csCoords[8] = {
    GLMS_CSCOORD_LBN,
    GLMS_CSCOORD_LTN,
    GLMS_CSCOORD_RTN,
    GLMS_CSCOORD_RBN,

    GLMS_CSCOORD_LBF,
    GLMS_CSCOORD_LTF,
    GLMS_CSCOORD_RTF,
    GLMS_CSCOORD_RBF
  };

  c[0] = glms_mat4_mulv(invMat, csCoords[0]);
  c[1] = glms_mat4_mulv(invMat, csCoords[1]);
  c[2] = glms_mat4_mulv(invMat, csCoords[2]);
  c[3] = glms_mat4_mulv(invMat, csCoords[3]);
  c[4] = glms_mat4_mulv(invMat, csCoords[4]);
  c[5] = glms_mat4_mulv(invMat, csCoords[5]);
  c[6] = glms_mat4_mulv(invMat, csCoords[6]);
  c[7] = glms_mat4_mulv(invMat, csCoords[7]);

  dest[0] = glms_vec4_scale(c[0], 1.0f / c[0].z);
  dest[1] = glms_vec4_scale(c[1], 1.0f / c[1].z);
  dest[2] = glms_vec4_scale(c[2], 1.0f / c[2].z);
  dest[3] = glms_vec4_scale(c[3], 1.0f / c[3].z);
  dest[4] = glms_vec4_scale(c[4], 1.0f / c[4].z);
  dest[5] = glms_vec4_scale(c[5], 1.0f / c[5].z);
  dest[6] = glms_vec4_scale(c[6], 1.0f / c[6].z);
  dest[7] = glms_vec4_scale(c[7], 1.0f / c[7].z);
}

/*!
 * @brief finds center of view frustum
 *
 * @param[in]  corners view frustum corners
 * @returns            view frustum center
 */
CGLM_INLINE
vec4s
glms_frustum_center(vec4s corners[8]) {
  vec4s center;

  center = glms_vec4_copy(corners[0]);

  center = glms_vec4_add(corners[1], center);
  center = glms_vec4_add(corners[2], center);
  center = glms_vec4_add(corners[3], center);
  center = glms_vec4_add(corners[4], center);
  center = glms_vec4_add(corners[5], center);
  center = glms_vec4_add(corners[6], center);
  center = glms_vec4_add(corners[7], center);

  return glms_vec4_scale(center, 0.125f);
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
glms_frustum_box(vec4s corners[8], mat4s m, vec3s box[2]) {
  vec4s v;
  vec3s min, max;
  int  i;

  min = glms_vec3_broadcast(FLT_MAX);
  max = glms_vec3_broadcast(-FLT_MAX);

  for (i = 0; i < 8; i++) {
    v = glms_mat4_mulv(m, corners[i]);

    min.x = glm_min(min.x, v.x);
    min.y = glm_min(min.y, v.y);
    min.z = glm_min(min.z, v.z);

    max.x = glm_max(max.x, v.x);
    max.y = glm_max(max.y, v.y);
    max.z = glm_max(max.z, v.z);
  }

  box[0] = glms_vec3_copy(min);
  box[1] = glms_vec3_copy(max);
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
glms_frustum_corners_at(vec4s  corners[8],
                        float splitDist,
                        float farDist,
                        vec4s  planeCorners[4]) {
  vec4s corner;
  float dist, sc;

  /* because distance and scale is same for all */
  dist = glms_vec4_distance(corners[GLM_RTF], corners[GLM_RTN]);
  sc   = dist * (splitDist / farDist);

  /* left bottom */
  corner = glms_vec4_sub(corners[GLM_LBF], corners[GLM_LBN]);
  corner = glms_vec4_scale_as(corner, sc);
  planeCorners[0] = glms_vec4_add(corners[GLM_LBN], corner);

  /* left top */
  corner = glms_vec4_sub(corners[GLM_LTF], corners[GLM_LTN]);
  corner = glms_vec4_scale_as(corner, sc);
  planeCorners[1] = glms_vec4_add(corners[GLM_LTN], corner);

  /* right top */
  corner = glms_vec4_sub(corners[GLM_RTF], corners[GLM_RTN]);
  corner = glms_vec4_scale_as(corner, sc);
  planeCorners[2] = glms_vec4_add(corners[GLM_RTN], corner);

  /* right bottom */
  corner = glms_vec4_sub(corners[GLM_RBF], corners[GLM_RBN]);
  corner = glms_vec4_scale_as(corner, sc);
  planeCorners[3] = glms_vec4_add(corners[GLM_RBN], corner);
}

#endif /* cglm_frustums_h */
