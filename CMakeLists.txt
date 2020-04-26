cmake_minimum_required(VERSION 3.8.2)
project(cglm LANGUAGES C)

set(C_STANDARD 11)
set(C_STANDARD_REQUIRED YES)

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
  set(C_STANDARD 99)
endif()

if(MSVC)
	add_definitions(-DNDEBUG -D_WINDOWS -D_USRDLL -DCGLM_EXPORTS -DCGLM_DLL)
	add_compile_options("/W3" "/Ox" "/Gy" "/Oi" "/TC" "/analyze")
else()
    add_compile_options("-Wall" "-Werror" "-O3")
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
		add_compile_options("-stdlib=libc++" "-Weverything")
    else()
		add_compile_options("-Werror=strict-prototypes" "-fstrict-aliasing")
    endif()
endif()

set(HEADERS
  include/cglm/sphere.h
  include/cglm/ease.h
  include/cglm/applesimd.h
  include/cglm/io.h
  include/cglm/mat3.h
  include/cglm/affine-mat.h
  include/cglm/util.h
  include/cglm/common.h
  include/cglm/box.h
  include/cglm/cam.h
  include/cglm/vec3-ext.h
  include/cglm/types.h
  include/cglm/version.h
  include/cglm/vec4-ext.h
  include/cglm/euler.h
  include/cglm/vec2-ext.h
  include/cglm/project.h
  include/cglm/quat.h
  include/cglm/call.h
  include/cglm/plane.h
  include/cglm/vec2.h
  include/cglm/cglm.h
  include/cglm/mat2.h
  include/cglm/mat4.h
  include/cglm/curve.h
  include/cglm/affine.h
  include/cglm/vec3.h
  include/cglm/frustum.h
  include/cglm/vec4.h
  include/cglm/struct.h
  include/cglm/color.h
  include/cglm/types-struct.h
  include/cglm/bezier.h
  )

set(HEADERS_CALL
  include/cglm/call/sphere.h
  include/cglm/call/ease.h
  include/cglm/call/io.h
  include/cglm/call/mat3.h
  include/cglm/call/box.h
  include/cglm/call/cam.h
  include/cglm/call/euler.h
  include/cglm/call/project.h
  include/cglm/call/quat.h
  include/cglm/call/plane.h
  include/cglm/call/vec2.h
  include/cglm/call/mat2.h
  include/cglm/call/mat4.h
  include/cglm/call/curve.h
  include/cglm/call/affine.h
  include/cglm/call/vec3.h
  include/cglm/call/frustum.h
  include/cglm/call/vec4.h
  include/cglm/call/bezier.h
  )

set(HEADERS_SIMD
  include/cglm/simd/arm.h
  include/cglm/simd/x86.h
  include/cglm/simd/intrin.h
  include/cglm/simd/neon/mat4.h
  )
set(HEADERS_SIMD_AVX
   include/cglm/simd/avx/mat4.h
   include/cglm/simd/avx/affine.h
   )
set(HEADERS_SIMD_SSE2
  include/cglm/simd/sse2/mat3.h
  include/cglm/simd/sse2/quat.h
  include/cglm/simd/sse2/mat2.h
  include/cglm/simd/sse2/mat4.h
  include/cglm/simd/sse2/affine.h
  )



set(HEADERS_STRUCT
  include/cglm/struct/sphere.h
  include/cglm/struct/io.h
  include/cglm/struct/mat3.h
  include/cglm/struct/box.h
  include/cglm/struct/cam.h
  include/cglm/struct/vec3-ext.h
  include/cglm/struct/vec4-ext.h
  include/cglm/struct/euler.h
  include/cglm/struct/vec2-ext.h
  include/cglm/struct/project.h
  include/cglm/struct/quat.h
  include/cglm/struct/plane.h
  include/cglm/struct/vec2.h
  include/cglm/struct/mat2.h
  include/cglm/struct/mat4.h
  include/cglm/struct/curve.h
  include/cglm/struct/affine.h
  include/cglm/struct/vec3.h
  include/cglm/struct/frustum.h
  include/cglm/struct/vec4.h
  include/cglm/struct/color.h
  )

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
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install(
	TARGETS	cglm
	EXPORT cglm
	ARCHIVE DESTINATION lib/ COMPONENT development
	LIBRARY DESTINATION lib/ COMPONENT runtime NAMELINK_SKIP
	RUNTIME DESTINATION ${CMAKE_INSTALL_NAME_DIR} COMPONENT runtime
)

if(CGLM_SHARED)
	install(
		TARGETS	cglm
		EXPORT cglm
		LIBRARY DESTINATION include/ COMPONENT development NAMELINK_ONLY
	)
endif()


INSTALL(DIRECTORY include/ DESTINATION include)

# Test Configuration
if(CGLM_USE_TEST)
  enable_testing()
  add_subdirectory(test)
endif()
