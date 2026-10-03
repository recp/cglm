#include "../include/cglm/cglm.h"
#include "../include/cglm/call.h"

CGLM_EXPORT
bool
glmc_ray_triangle(const vec3 origin,
                  const vec3 direction,
                  const vec3 v0,
                  const vec3 v1,
                  const vec3 v2,
                  float *d) {
  return glm_ray_triangle(origin, direction, v0, v1, v2, d);
}

CGLM_EXPORT
bool
glmc_ray_sphere(const vec3 origin,
                const vec3 dir,
                const vec4 s,
                float * __restrict t1,
                float * __restrict t2) {
  return glm_ray_sphere(origin, dir, s, t1, t2);
}

CGLM_EXPORT
void
glmc_ray_at(const vec3 orig, const vec3 dir, float t, vec3 point) {
  glm_ray_at(orig, dir, t, point);
}
