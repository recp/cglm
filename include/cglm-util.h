/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_util_h
#define cglm_util_h

#include "cglm.h"
#include <stdio.h>
#include <stdlib.h>

CGLM_INLINE
void
glm_mat4_print(mat4   matrix,
               FILE * __restrict ostream) {
  int i;
  int j;

#define m 4
#define n 4

  fprintf(ostream, "Matrix (%dx%d):\n", m, n);

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++)
      fprintf(ostream, "\t%0.2f,", matrix[j][i]);;

    fprintf(ostream, "\n");
  }

  fprintf(ostream, "\n");

#undef m
#undef n
}

CGLM_INLINE
void
glm_vec4_print(vec4 vec,
               FILE * __restrict ostream) {
  int i;

#define m 4

  fprintf(ostream, "Vector (%d):\n", m);

  for (i = 0; i < m; i++)
    fprintf(ostream, "\t%0.2f,", vec[i]);;

  fprintf(ostream, "\n");

#undef m
}

CGLM_INLINE
void
glm_vec3_print(vec3 vec,
               FILE * __restrict ostream) {
  int i;

#define m 3

  fprintf(ostream, "Vector (%d):\n", m);

  for (i = 0; i < m; i++)
    fprintf(ostream, "\t%0.2f,", vec[i]);;

  fprintf(ostream, "\n");

#undef m
}

CGLM_INLINE
void
glm_versor_print(versor vec,
                 FILE * __restrict ostream) {
  int i;

#define m 4

  fprintf(ostream, "Versor (%d):\n", m);

  for (i = 0; i < m; i++)
    fprintf(ostream, "\t%0.2f,", vec[i]);;

  fprintf(ostream, "\n");

#undef m
}

#endif /* cglm_util_h */
