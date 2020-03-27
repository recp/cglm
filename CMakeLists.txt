cmake_minimum_required(VERSION 3.8.2)
project(cglm LANGUAGES C)

set(C_STANDARD 99)
set(C_STANDARD_REQUIRED YES)
set(C_EXTENSIONS NO)

set(CGLM_BUILD)
option(CGLM_STATIC "Static build" ON)
option(CGLM_SHARED "Shared build" OFF)

if(CGLM_STATIC AND NOT CGLM_SHARED)
  set(CGLM_BUILD STATIC)
else(CGLM_SHARED)
  set(CGLM_BUILD SHARED)
endif()

add_library(cglm
  ${CGLM_BUILD}
  src/io.c
  src/box.c
  src/ease.c
  src/config.h
  src/euler.c
  src/vec4.c
  src/mat2.c
  src/mat4.c
  src/frustum.c
  src/quat.c
  src/plane.c
  src/project.c
  src/bezier.c
  src/sphere.c
  src/curve.c
  src/cam.c
  src/vec3.c
  src/mat3.c
  src/vec2.c
  src/affine.c
  )

target_include_directories(cglm PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include)
