/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_MAT2X4_ZERO_INIT
   GLMS_MAT2X4_ZERO

 Functions:
   CGLM_INLINE mat2x4s glms_mat2x4_make(float * __restrict src);
 */

#ifndef cglms_mat2x4_h
#define cglms_mat2x4_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat2x4.h"

/* api definition */
#define glms_mat2x4_(NAME) CGLM_STRUCTAPI(mat2x4, NAME)

#define GLMS_MAT2X4_ZERO_INIT {GLM_MAT2X4_ZERO_INIT}

/* for C only */
#define GLMS_MAT2X4_ZERO ((mat2x4s)GLMS_MAT2X4_ZERO_INIT)

/*!
 * @brief Create mat2x4 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @return constructed matrix from raw pointer
 */
CGLM_INLINE
mat2x4s
glms_mat2x4_(make)(float * __restrict src) {
  mat2x4s r;
  glm_mat2x4_make(src, r.raw);
  return r;
}

#endif /* cglms_mat2x4_h */
