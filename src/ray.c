#include "../include/cglm/cglm.h"
#include "../include/cglm/call.h"

CGLM_EXPORT
bool
glmc_ray_triangle(vec3   origin,
                  vec3   direction,
                  vec3   v0,
                  vec3   v1,
                  vec3   v2,
                  float *d) {
    return glm_ray_triangle(origin, direction, v0, v1, v2, d);
}
