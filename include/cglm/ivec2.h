/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
FUNCTIONS:
  CGLM_INLINE void glm_ivec2(int * __restrict v, ivec2 dest)
 */

#ifndef cglm_ivec2_h
#define cglm_ivec2_h

#include "common.h"

/*!
 * @brief init ivec2 using another vector
 *
 * @param[in]  v    a vector
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec2(int * __restrict v, ivec2 dest) {
  dest[0] = v[0];
  dest[1] = v[1];
}

#endif /* cglm_ivec2_h */
