/*
 * Copyright (c), Recep Aslantas.
 * MIT License (MIT), http://opensource.org/licenses/MIT
 */

#ifndef test_tests_h
#define test_tests_h

/* mat4 */
void test_mat4(void **state);

/* camera */
void
test_camera_lookat(void **state);

void
test_camera_decomp(void **state);

void
test_clamp(void **state);

void
test_euler(void **state);

#endif /* test_tests_h */
