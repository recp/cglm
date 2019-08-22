/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglms_curves_h
#define cglms_curves_h

#include "../common.h"
#include "../types-struct.h"
#include "../curve.h"
#include "vec4.h"
#include "mat4.h"

/*!
 * @brief helper function to calculate S*M*C multiplication for curves
 *
 * This function does not encourage you to use SMC,
 * instead it is a helper if you use SMC.
 *
 * if you want to specify S as vector then use more generic glm_mat4_rmc() func.
 *
 * Example usage:
 *  B(s) = glm_smc(s, GLM_BEZIER_MAT, (vec4){p0, c0, c1, p1})
 *
 * @param[in]  s  parameter between 0 and 1 (this will be [s3, s2, s, 1])
 * @param[in]  m  basis matrix
 * @param[in]  c  position/control vector
 *
 * @return B(s)
 */
CGLM_INLINE
float
glms_smc(float s, mat4s m, vec4s c) {
  return glm_smc(s, m.raw, c.raw);
}

#endif /* cglms_curves_h */
