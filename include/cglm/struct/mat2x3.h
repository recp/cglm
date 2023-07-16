/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_MAT2X3_ZERO_INIT
   GLMS_MAT2X3_ZERO

 Functions:
   CGLM_INLINE mat2x3s glms_mat2x3_make(float * __restrict src);
 */

#ifndef cglms_mat2x3_h
#define cglms_mat2x3_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat2x3.h"

/* api definition */
#define glms_mat2x3_(NAME) CGLM_STRUCTAPI(mat2x3, NAME)

#define GLMS_MAT2X3_ZERO_INIT {GLM_MAT2X3_ZERO_INIT}

/* for C only */
#define GLMS_MAT2X3_ZERO ((mat2x3s)GLMS_MAT2X3_ZERO_INIT)

/*!
 * @brief Create mat2x3 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @return constructed matrix from raw pointer
 */
CGLM_INLINE
mat2x3s
glms_mat2x3_(make)(float * __restrict src) {
  mat2x3s r;
  glm_mat2x3_make(src, r.raw);
  return r;
}

#endif /* cglms_mat2x3_h */
