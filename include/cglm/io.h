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

#ifndef cglm_io_h
#define cglm_io_h
#if defined(DEBUG) || defined(_DEBUG) \
   || defined(CGLM_DEFINE_PRINTS) || defined(CGLM_LIB_SRC)

#include "common.h"

#include <stdio.h>
#include <stdlib.h>

#define CGLM_PRINT_PRECISION    5
#define CGLM_PRINT_MAX_TO_SHORT 1e5
#define CGLM_PRINT_COLOR        "\033[36m"
#define CGLM_PRINT_COLOR_RESET  "\033[0m"

CGLM_INLINE
void
glm_mat4_print(mat4              matrix,
               FILE * __restrict ostream) {
  char buff[16];
  int  i, j, cw[4], cwi;

#define m 4
#define n 4

  fprintf(ostream, "Matrix (float%dx%d): " CGLM_PRINT_COLOR "\n" , m, n);

  cw[0] = cw[1] = cw[2] = cw[3] = 0;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (matrix[i][j] < CGLM_PRINT_MAX_TO_SHORT)
        cwi = sprintf(buff, "% .*f", CGLM_PRINT_PRECISION, matrix[i][j]);
      else
        cwi = sprintf(buff, "% g", matrix[i][j]);
      cw[i] = GLM_MAX(cw[i], cwi);
    }
  }

  for (i = 0; i < m; i++) {
    fprintf(ostream, "  |");

    for (j = 0; j < n; j++)
      if (matrix[i][j] < CGLM_PRINT_MAX_TO_SHORT)
        fprintf(ostream, " % *.*f", cw[j], CGLM_PRINT_PRECISION, matrix[j][i]);
      else
        fprintf(ostream, " % *g", cw[j], matrix[j][i]);

    fprintf(ostream, "  |\n");
  }

  fprintf(ostream, CGLM_PRINT_COLOR_RESET "\n");

#undef m
#undef n
}


CGLM_INLINE
void
glm_mat3_print(mat3              matrix,
               FILE * __restrict ostream) {
  char buff[16];
  int  i, j, cw[4], cwi;

#define m 3
#define n 3

  fprintf(ostream, "Matrix (float%dx%d): " CGLM_PRINT_COLOR "\n", m, n);

  cw[0] = cw[1] = cw[2] = 0;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (matrix[i][j] < CGLM_PRINT_MAX_TO_SHORT)
        cwi = sprintf(buff, "% .*f", CGLM_PRINT_PRECISION, matrix[i][j]);
      else
        cwi = sprintf(buff, "% g", matrix[i][j]);
      cw[i] = GLM_MAX(cw[i], cwi);
    }
  }

  for (i = 0; i < m; i++) {
    fprintf(ostream, "  |");
    
    for (j = 0; j < n; j++)
      if (matrix[i][j] < CGLM_PRINT_MAX_TO_SHORT)
        fprintf(ostream, " % *.*f", cw[j], CGLM_PRINT_PRECISION, matrix[j][i]);
      else
        fprintf(ostream, " % *g", cw[j], matrix[j][i]);
    
    fprintf(ostream, "  |\n");
  }

  fprintf(ostream, CGLM_PRINT_COLOR_RESET "\n");

#undef m
#undef n
}

CGLM_INLINE
void
glm_mat2_print(mat2              matrix,
               FILE * __restrict ostream) {
  char buff[16];
  int  i, j, cw[4], cwi;

#define m 2
#define n 2

  fprintf(ostream, "Matrix (float%dx%d): " CGLM_PRINT_COLOR "\n", m, n);

  cw[0] = cw[1] = 0;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (matrix[i][j] < CGLM_PRINT_MAX_TO_SHORT)
        cwi = sprintf(buff, "% .*f", CGLM_PRINT_PRECISION, matrix[i][j]);
      else
        cwi = sprintf(buff, "% g", matrix[i][j]);
      cw[i] = GLM_MAX(cw[i], cwi);
    }
  }

  for (i = 0; i < m; i++) {
    fprintf(ostream, "  |");
    
    for (j = 0; j < n; j++)
      if (matrix[i][j] < CGLM_PRINT_MAX_TO_SHORT)
        fprintf(ostream, " % *.*f", cw[j], CGLM_PRINT_PRECISION, matrix[j][i]);
      else
        fprintf(ostream, " % *g", cw[j], matrix[j][i]);
    
    fprintf(ostream, "  |\n");
  }

  fprintf(ostream, CGLM_PRINT_COLOR_RESET "\n");

#undef m
#undef n
}

CGLM_INLINE
void
glm_vec4_print(vec4              vec,
               FILE * __restrict ostream) {
  int i;

#define m 4

  fprintf(ostream, "Vector (float%d): " CGLM_PRINT_COLOR "\n  (", m);

  for (i = 0; i < m; i++) {
    if (vec[i] < CGLM_PRINT_MAX_TO_SHORT)
      fprintf(ostream, " % .*f", CGLM_PRINT_PRECISION, vec[i]);
    else
      fprintf(ostream, " % g", vec[i]);
  }

  fprintf(ostream, "  )" CGLM_PRINT_COLOR_RESET "\n\n");

#undef m
}

CGLM_INLINE
void
glm_vec3_print(vec3              vec,
               FILE * __restrict ostream) {
  int i;

#define m 3

  fprintf(ostream, "Vector (float%d): " CGLM_PRINT_COLOR "\n  (", m);

  for (i = 0; i < m; i++) {
    if (vec[i] < CGLM_PRINT_MAX_TO_SHORT)
      fprintf(ostream, " % .*f", CGLM_PRINT_PRECISION, vec[i]);
    else
      fprintf(ostream, " % g", vec[i]);
  }

  fprintf(ostream, "  )" CGLM_PRINT_COLOR_RESET "\n\n");

#undef m
}

CGLM_INLINE
void
glm_ivec3_print(ivec3             vec,
                FILE * __restrict ostream) {
  int i;

#define m 3

  fprintf(ostream, "Vector (int%d): " CGLM_PRINT_COLOR "\n  (", m);

  for (i = 0; i < m; i++)
    fprintf(ostream, " % d", vec[i]);

  fprintf(ostream, "  )" CGLM_PRINT_COLOR_RESET "\n\n");
  
#undef m
}

CGLM_INLINE
void
glm_vec2_print(vec2              vec,
               FILE * __restrict ostream) {
  int i;

#define m 2

  fprintf(ostream, "Vector (float%d): " CGLM_PRINT_COLOR "\n  (", m);

  for (i = 0; i < m; i++) {
    if (vec[i] < CGLM_PRINT_MAX_TO_SHORT)
      fprintf(ostream, " % .*f", CGLM_PRINT_PRECISION, vec[i]);
    else
      fprintf(ostream, " % g", vec[i]);
  }

  fprintf(ostream, "  )" CGLM_PRINT_COLOR_RESET "\n\n");

#undef m
}

CGLM_INLINE
void
glm_versor_print(versor            vec,
                 FILE * __restrict ostream) {
  int i;

#define m 4

  fprintf(ostream, "Quaternion (float%d): " CGLM_PRINT_COLOR "\n  (", m);

  for (i = 0; i < m; i++) {
    if (vec[i] < CGLM_PRINT_MAX_TO_SHORT)
      fprintf(ostream, " % .*f", CGLM_PRINT_PRECISION, vec[i]);
    else
      fprintf(ostream, " % g", vec[i]);
  }


  fprintf(ostream, "  )" CGLM_PRINT_COLOR_RESET "\n\n");

#undef m
}

CGLM_INLINE
void
glm_aabb_print(vec3                    bbox[2],
               const char * __restrict tag,
               FILE       * __restrict ostream) {
  int i, j;

#define m 3

  fprintf(ostream, "AABB (%s): " CGLM_PRINT_COLOR "\n", tag ? tag: "float");

  for (i = 0; i < 2; i++) {
    fprintf(ostream, "  (");
    
    for (j = 0; j < m; j++) {
      if (bbox[i][j] < CGLM_PRINT_MAX_TO_SHORT)
        fprintf(ostream, " % .*f", CGLM_PRINT_PRECISION, bbox[i][j]);
      else
        fprintf(ostream, " % g", bbox[i][j]);
    }

    fprintf(ostream, "  )\n");
  }

  fprintf(ostream, CGLM_PRINT_COLOR_RESET "\n");

#undef m
}

#elif !defined(CGLM_NO_PRINTS_NOOP)

#include "common.h"

#include <stdio.h>
#include <stdlib.h>

/* NOOP: Remove print from DEBUG */
#define glm_mat4_print(...)
#define glm_mat3_print(...)
#define glm_mat2_print(...)
#define glm_vec4_print(...)
#define glm_vec3_print(...)
#define glm_ivec3_print(...)
#define glm_vec2_print(...)
#define glm_versor_print(...)
#define glm_aabb_print(...)

#endif
#endif /* cglm_io_h */
