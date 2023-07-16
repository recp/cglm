/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Macros:
   GLMS_MAT3X2_ZERO_INIT
   GLMS_MAT3X2_ZERO

 Functions:
   CGLM_INLINE mat3x2s glms_mat3x2_make(float * __restrict src);
 */

#ifndef cglms_mat3x2_h
#define cglms_mat3x2_h

#include "../common.h"
#include "../types-struct.h"
#include "../mat3x2.h"

/* api definition */
#define glms_mat3x2_(NAME) CGLM_STRUCTAPI(mat3x2, NAME)

#define GLMS_MAT3X2_ZERO_INIT {GLM_MAT3X2_ZERO_INIT}

/* for C only */
#define GLMS_MAT3X2_ZERO ((mat3x2s)GLMS_MAT3X2_ZERO_INIT)

/*!
 * @brief Create mat3x2 matrix from pointer
 *
 * @param[in]  src  pointer to an array of floats
 * @return constructed matrix from raw pointer
 */
CGLM_INLINE
mat3x2s
glms_mat3x2_(make)(float * __restrict src) {
  mat3x2s r;
  glm_mat3x2_make(src, r.raw);
  return r;
}

#endif /* cglms_mat3x2_h */
