/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef test_common_h
#define test_common_h

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <time.h>

#include <cglm.h>
#include <cglm-call.h>

#define precision 0.00001f

static
void
test_rand_mat4(mat4 dest);

static
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

#endif /* test_common_h */
