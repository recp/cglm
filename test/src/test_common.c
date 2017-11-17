/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#include "test_common.h"
#include <stdlib.h>

void
test_rand_mat4(mat4 dest) {
  glm_mat4_copy(GLM_MAT4_IDENTITY, dest);
  
  srand((unsigned int)time(NULL));

  /* random position */
  dest[3][0] = drand48();
  dest[3][1] = drand48();
  dest[3][2] = drand48();
  
  /* random rotatation around random axis with random angle */
  glm_rotate(dest, drand48(), (vec3){drand48(), drand48(), drand48()});
  
  /* random scale */
  /* glm_scale(dest, (vec3){drand48(), drand48(), drand48()}); */
}

void
test_assert_mat4_eq(mat4 m1, mat4 m2) {
  int i, j, k;

#define m 4
#define n 4
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < m; k++)
        assert_true(fabsf(m1[i][j] - m2[i][j]) <= 0.00009);
    }
  }
#undef m
#undef n
}

