#include <stdio.h>

#include "glm/glm.hpp"
#include "glm/mat4x4.hpp"
#include <glm/ext/matrix_clip_space.hpp>

static void outputForPerspectiveLH_ZO() {
  const float fovy   = glm::radians(45.0f);
  const float aspect = 640/480.0f;
  const float near   = 0.1f;
  const float far    = 100.0f;
  glm::mat4 cmp = glm::perspectiveLH_ZO(fovy, aspect, near, far);
  puts("/*reference test data for glm_perspective_lh_zo*/");
  puts("mat4 cmp = {0};");
  printf("cmp[0][0] = %0.7ff;\n", cmp[0][0]);
  printf("cmp[1][1] = %0.7ff;\n", cmp[1][1]);
  printf("cmp[2][2] = %0.7ff;\n", cmp[2][2]);
  printf("cmp[2][3] = %0.7ff;\n", cmp[2][3]);
  printf("cmp[3][2] = %0.7ff;\n", cmp[3][2]);
}
static void outputForPerspectiveRH_ZO() {
  const float fovy   = glm::radians(45.0f);
  const float aspect = 640/480.0f;
  const float near   = 0.1f;
  const float far    = 100.0f;
  glm::mat4 cmp = glm::perspectiveRH_ZO(fovy, aspect, near, far);
  puts("/*reference test data for glm_perspective_rh_zo*/");
  puts("mat4 cmp = {0};");
  printf("cmp[0][0] = %0.7ff;\n", cmp[0][0]);
  printf("cmp[1][1] = %0.7ff;\n", cmp[1][1]);
  printf("cmp[2][2] = %0.7ff;\n", cmp[2][2]);
  printf("cmp[2][3] = %0.7ff;\n", cmp[2][3]);
  printf("cmp[3][2] = %0.7ff;\n", cmp[3][2]);
}

int main(int argc, char** argv) {
  outputForPerspectiveRH_ZO();
	return 0;
}
