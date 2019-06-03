/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglms_planes_h
#define cglms_planes_h

#include "../common.h"
#include "../types-struct.h"
#include "../plane.h"
#include "vec4.h"

/*
 Plane equation:  Ax + By + Cz + D = 0;

 It stored in vec4 as [A, B, C, D]. (A, B, C) is normal and D is distance
*/

/*
 Functions:
   CGLM_INLINE vec4s glms_plane_normalize(vec4s plane);
 */

/*!
 * @brief normalizes a plane
 *
 * @param[in] plane plane to normalize
 * @returns         normalized plane
 */
CGLM_INLINE
vec4s
glms_plane_normalize(vec4s plane) {
  glm_plane_normalize(plane.raw);
  return plane;
}

#endif /* cglms_planes_h */
