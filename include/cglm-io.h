/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_io_h
#define cglm_io_h

#include "cglm-common.h"

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

  fprintf(ostream, "Matrix (float%dx%d):\n", m, n);

  for (i = 0; i < m; i++) {
    fprintf(ostream, "\t|");
    for (j = 0; j < n; j++) {
      fprintf(ostream, "%0.4f", matrix[j][i]);;

      if (j != n - 1)
        fprintf(ostream, "\t");
    }

    fprintf(ostream, "|\n");
  }

  fprintf(ostream, "\n");

#undef m
#undef n
}

CGLM_INLINE
void
glm_mat3_print(mat3 matrix,
               FILE * __restrict ostream) {
  int i;
  int j;

#define m 3
#define n 3

  fprintf(ostream, "Matrix (float%dx%d):\n", m, n);

  for (i = 0; i < m; i++) {
    fprintf(ostream, "\t|");
    for (j = 0; j < n; j++) {
      fprintf(ostream, "%0.4f", matrix[j][i]);;

      if (j != n - 1)
        fprintf(ostream, "\t");
    }

    fprintf(ostream, "|\n");
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

  fprintf(ostream, "Vector (float%d):\n\t|", m);

  for (i = 0; i < m; i++) {
    fprintf(ostream, "%0.4f", vec[i]);

    if (i != m - 1)
      fprintf(ostream, "\t");
  }

  fprintf(ostream, "|\n\n");

#undef m
}

CGLM_INLINE
void
glm_vec3_print(vec3 vec,
               FILE * __restrict ostream) {
  int i;

#define m 3

  fprintf(ostream, "Vector (float%d):\n\t|", m);

  for (i = 0; i < m; i++) {
    fprintf(ostream, "%0.4f", vec[i]);

    if (i != m - 1)
      fprintf(ostream, "\t");
  }

  fprintf(ostream, "|\n\n");

#undef m
}

CGLM_INLINE
void
glm_versor_print(versor vec,
                 FILE * __restrict ostream) {
  int i;

#define m 4

  fprintf(ostream, "Versor (float%d):\n\t|", m);

  for (i = 0; i < m; i++) {
    fprintf(ostream, "%0.4f", vec[i]);

    if (i != m - 1)
      fprintf(ostream, "\t");
  }

  fprintf(ostream, "|\n\n");

#undef m
}

#endif /* cglm_io_h */
