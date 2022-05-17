/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
FUNCTIONS:
  CGLM_INLINE void glm_ivec4(int * __restrict v, ivec4 dest)
 */

#ifndef cglm_ivec4_h
#define cglm_ivec4_h

#include "common.h"

/*!
 * @brief init ivec4 using ivec3
 *
 * @param[in]  v3   vector3
 * @param[in]  last last item
 * @param[out] dest destination
 */
CGLM_INLINE
void
glm_ivec4(ivec3 v3, int last, ivec4 dest) {
  dest[0] = v3[0];
  dest[1] = v3[1];
  dest[2] = v3[2];
  dest[3] = last;
}

#endif /* cglm_ivec4_h */
