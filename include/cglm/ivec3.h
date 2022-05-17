/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
FUNCTIONS:
  CGLM_INLINE void glm_ivec3(int * __restrict v, ivec3 dest)
 */

#ifndef cglm_ivec3_h
#define cglm_ivec3_h

#include "common.h"

/*!
 * @brief init ivec3 using another vector
 *
 * @param[in]  v    a vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec3(int * __restrict v, ivec3 dest) {
  dest[0] = v[0];
  dest[1] = v[1];
  dest[2] = v[2];
}

#endif /* cglm_ivec3_h */
