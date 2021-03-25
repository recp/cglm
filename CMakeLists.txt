cmake_minimum_required(VERSION 3.8.2)
project(cglm VERSION 0.8.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)
set(DEFAULT_BUILD_TYPE "Release")

set(CGLM_BUILD)
option(CGLM_SHARED "Shared build" ON)
option(CGLM_STATIC "Static build" OFF)
option(CGLM_USE_C99 "" OFF)
option(CGLM_USE_TEST "Enable Tests" OFF)

if(NOT CGLM_STATIC AND CGLM_SHARED)
  set(CGLM_BUILD SHARED)
else(CGLM_STATIC)
  set(CGLM_BUILD STATIC)
endif()

if(CGLM_USE_C99)
  set(CMAKE_C_STANDARD 99)
endif()

if(MSVC)
  add_definitions(-DNDEBUG -D_WINDOWS -D_USRDLL)
  add_compile_options(/W3 /Ox /Gy /Oi /TC)
  
  # Ref: https://skia.googlesource.com/third_party/sdl/+/refs/heads/master/CMakeLists.txt#225
  # Make sure /RTC1 is disabled, otherwise it will use functions from the CRT
  foreach(flag_var
      CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
      CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
    string(REGEX REPLACE "/RTC(su|[1su])" "" ${flag_var} "${${flag_var}}")
  endforeach(flag_var)
else()
  add_compile_options(-Wall -Werror -O3)
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

include(GNUInstallDirs)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Target Start
add_library(${PROJECT_NAME}
  ${CGLM_BUILD}
  src/euler.c
  src/affine.c
  src/io.c
  src/quat.c
  src/cam.c
  src/vec2.c
  src/vec3.c
  src/vec4.c
  src/mat2.c
  src/mat3.c
  src/mat4.c
  src/plane.c
  src/frustum.c
  src/box.c
  src/project.c
  src/sphere.c
  src/ease.c
  src/curve.c
  src/bezier.c
  src/ray.c
  src/affine2d.c
  )

if(CGLM_SHARED)
  add_definitions(-DCGLM_EXPORTS)
else()
  target_compile_definitions(${PROJECT_NAME} PUBLIC -DCGLM_STATIC)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
                              VERSION ${PROJECT_VERSION} 
                            SOVERSION ${PROJECT_VERSION_MAJOR})

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Target for header-only usage
add_library(${PROJECT_NAME}_headers INTERFACE
  include/cglm/affine-mat.h
  include/cglm/affine.h
  include/cglm/affine2d.h
  include/cglm/applesimd.h
  include/cglm/bezier.h
  include/cglm/box.h
  include/cglm/call.h
  include/cglm/cam.h
  include/cglm/cglm.h
  include/cglm/color.h
  include/cglm/common.h
  include/cglm/curve.h
  include/cglm/ease.h
  include/cglm/euler.h
  include/cglm/frustum.h
  include/cglm/io.h
  include/cglm/mat2.h
  include/cglm/mat3.h
  include/cglm/mat4.h
  include/cglm/plane.h
  include/cglm/project.h
  include/cglm/quat.h
  include/cglm/ray.h
  include/cglm/sphere.h
  include/cglm/struct.h
  include/cglm/types-struct.h
  include/cglm/types.h
  include/cglm/util.h
  include/cglm/vec2-ext.h
  include/cglm/vec2.h
  include/cglm/vec3-ext.h
  include/cglm/vec3.h
  include/cglm/vec4-ext.h
  include/cglm/vec4.h
  include/cglm/version.h
  include/cglm/simd/arm.h
  include/cglm/simd/avx/affine.h
  include/cglm/simd/avx/mat4.h
  include/cglm/simd/intrin.h
  include/cglm/simd/neon/mat4.h
  include/cglm/simd/sse2/affine.h
  include/cglm/simd/sse2/mat2.h
  include/cglm/simd/sse2/mat3.h
  include/cglm/simd/sse2/mat4.h
  include/cglm/simd/sse2/quat.h
  include/cglm/simd/x86.h
  include/cglm/struct/affine.h
  include/cglm/struct/affine2d.h
  include/cglm/struct/box.h
  include/cglm/struct/cam.h
  include/cglm/struct/color.h
  include/cglm/struct/curve.h
  include/cglm/struct/euler.h
  include/cglm/struct/frustum.h
  include/cglm/struct/io.h
  include/cglm/struct/mat2.h
  include/cglm/struct/mat3.h
  include/cglm/struct/mat4.h
  include/cglm/struct/plane.h
  include/cglm/struct/project.h
  include/cglm/struct/quat.h
  include/cglm/struct/sphere.h
  include/cglm/struct/vec2-ext.h
  include/cglm/struct/vec2.h
  include/cglm/struct/vec3-ext.h
  include/cglm/struct/vec3.h
  include/cglm/struct/vec4-ext.h
  include/cglm/struct/vec4.h
  )

target_include_directories(${PROJECT_NAME}_headers INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Test Configuration
if(CGLM_USE_TEST)
  include(CTest)
  enable_testing()
  add_subdirectory(test)
endif()

# Install 
install(TARGETS ${PROJECT_NAME}
        EXPORT  ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY include/${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        PATTERN ".*" EXCLUDE)

# Config
export(TARGETS ${PROJECT_NAME}
       NAMESPACE ${PROJECT_NAME}::
       FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
)

install(EXPORT      ${PROJECT_NAME}
        FILE        "${PROJECT_NAME}Config.cmake"
        NAMESPACE   ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

