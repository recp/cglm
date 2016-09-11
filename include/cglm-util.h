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
      fprintf(ostream, "\t%0.2f,", matrix[i][j]);;

    fprintf(ostream, "\n");
  }

  fprintf(ostream, "\n");

#undef m
#undef n
}

#endif /* cglm_util_h */
