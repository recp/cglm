/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglms_frustums_h
#define cglms_frustums_h

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
  vec4 rawDest[6];
  glm_frustum_planes(m.raw, rawDest);
  glms_vec4_pack(dest, rawDest, 6);
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
  vec4 rawDest[8];
  glm_frustum_corners(invMat.raw, rawDest);
  glms_vec4_pack(dest, rawDest, 8);
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
  vec4 rawCorners[8];
  vec4s r;

  glms_vec4_unpack(rawCorners, corners, 8);
  glm_frustum_center(rawCorners, r.raw);
  return r;
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
  vec4 rawCorners[8];
  vec3 rawBox[2];

  glms_vec4_unpack(rawCorners, corners, 8);
  glm_frustum_box(rawCorners, m.raw, rawBox);
  glms_vec3_pack(box, rawBox, 2);
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
glms_frustum_corners_at(vec4s corners[8],
                        float splitDist,
                        float farDist,
                        vec4s planeCorners[4]) {
  vec4 rawCorners[8];
  vec4 rawPlaneCorners[4];

  glms_vec4_unpack(rawCorners, corners, 8);
  glm_frustum_corners_at(rawCorners, splitDist, farDist, rawPlaneCorners);
  glms_vec4_pack(planeCorners, rawPlaneCorners, 8);
}

#endif /* cglms_frustums_h */
