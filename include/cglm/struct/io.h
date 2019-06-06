/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

/*
 Functions:
   CGLM_INLINE void glm_mat4_print(mat4 matrix, FILE *ostream);
   CGLM_INLINE void glm_mat3_print(mat3 matrix, FILE *ostream);
   CGLM_INLINE void glm_vec4_print(vec4 vec, FILE *ostream);
   CGLM_INLINE void glm_vec3_print(vec3 vec, FILE *ostream);
   CGLM_INLINE void glm_ivec3_print(ivec3 vec, FILE *ostream);
   CGLM_INLINE void glm_versor_print(versor vec, FILE *ostream);
 */

#ifndef cglms_ios_h
#define cglms_ios_h

#include "../common.h"
#include "../io.h"
#include "mat4.h"

#include <stdio.h>
#include <stdlib.h>

CGLM_INLINE
void
glms_mat4_print(mat4s             matrix,
                FILE * __restrict ostream) {

  glm_mat4_print(matrix.raw, ostream);
}

CGLM_INLINE
void
glms_mat3_print(mat3s             matrix,
                FILE * __restrict ostream) {
  glm_mat3_print(matrix.raw, ostream);
}

CGLM_INLINE
void
glms_vec4_print(vec4s             vec,
                FILE * __restrict ostream) {
  glm_vec4_print(vec.raw, ostream);
}

CGLM_INLINE
void
glms_vec3_print(vec3s             vec,
                FILE * __restrict ostream) {
  glm_vec3_print(vec.raw, ostream);
}

CGLM_INLINE
void
glms_ivec3_print(ivec3s            vec,
                 FILE * __restrict ostream) {
  glm_ivec3_print(vec.raw, ostream);
}

CGLM_INLINE
void
glms_versor_print(versors           vec,
                  FILE * __restrict ostream) {
  glm_versor_print(vec.raw, ostream);
}

CGLM_INLINE
void
glms_aabb_print(vec3s                   bbox[2],
                const char * __restrict tag,
                FILE       * __restrict ostream) {
  vec3 rawBbox[2];

  glms_vec3_unpack(rawBbox, bbox, 2);
  glm_aabb_print(rawBbox, tag, ostream);
}

#endif /* cglms_ios_h */
