/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_perlin_h
#define cglm_perlin_h

#include "vec4.h"
#include "vec4-ext.h"


/*!
 * @brief Classic perlin noise
 *
 * @param[in]  point  4D vector
 * @returns           perlin noise value
 */
CGLM_INLINE
float
glm_perlin(vec4 point) {
    return point[0] + point[1] + point[2] + point[3];
}


#endif /* cglm_perlin_h */
