/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#include "test_common.h"
#include <stdlib.h>

void
test_rand_mat4(mat4 dest) {
  int i, j;

  srand((unsigned int)time(NULL));
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      dest[i][j] = drand48();
    }
  }
}

void
test_assert_mat4_eq(mat4 m1, mat4 m2) {
  int i, j, k;

#define m 4
#define n 4
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      for (k = 0; k < m; k++)
        assert_true(fabsf(m1[i][j] - m2[i][j]) <= 0.0001);
    }
  }
#undef m
#undef n
}

