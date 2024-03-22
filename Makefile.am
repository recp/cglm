#******************************************************************************
# Copyright (c), Recep Aslantas.                                              *
#                                                                             *
# MIT License (MIT), http://opensource.org/licenses/MIT                       *
# Full license can be found in the LICENSE file                               *
#                                                                             *
#******************************************************************************

ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = -Wall \
            -std=gnu11 \
            -O3 \
            -Wstrict-aliasing=2 \
            -fstrict-aliasing

lib_LTLIBRARIES = libcglm.la
libcglm_la_LDFLAGS = -no-undefined -version-info 0:1:0

checkLDFLAGS = -L./.libs \
               -lm \
               -lcglm
checkCFLAGS = $(AM_CFLAGS) \
               -std=gnu11 \
               -O3 \
               -DCGLM_DEFINE_PRINTS \
               -I./include

check_PROGRAMS = test/tests
TESTS = $(check_PROGRAMS)

test_tests_LDFLAGS = $(checkLDFLAGS)
test_tests_CFLAGS  = $(checkCFLAGS)

cglmdir=$(includedir)/cglm
cglm_HEADERS = include/cglm/version.h \
               include/cglm/common.h \
               include/cglm/types.h \
               include/cglm/types-struct.h \
               include/cglm/cglm.h \
               include/cglm/call.h \
               include/cglm/struct.h \
               include/cglm/cam.h \
               include/cglm/io.h \
               include/cglm/mat4.h \
               include/cglm/mat4x2.h \
               include/cglm/mat4x3.h \
               include/cglm/mat3.h \
               include/cglm/mat3x2.h \
               include/cglm/mat3x4.h \
               include/cglm/mat2.h \
               include/cglm/mat2x3.h \
               include/cglm/mat2x4.h \
               include/cglm/affine-pre.h \
               include/cglm/affine-post.h \
               include/cglm/affine.h \
               include/cglm/affine-mat.h \
               include/cglm/vec2.h \
               include/cglm/vec2-ext.h \
               include/cglm/ivec2.h \
               include/cglm/vec3.h \
               include/cglm/vec3-ext.h \
               include/cglm/ivec3.h \
               include/cglm/vec4.h \
               include/cglm/vec4-ext.h \
               include/cglm/ivec4.h \
               include/cglm/euler.h \
               include/cglm/util.h \
               include/cglm/quat.h \
               include/cglm/plane.h \
               include/cglm/frustum.h \
               include/cglm/box.h \
               include/cglm/aabb2d.h \
               include/cglm/color.h \
               include/cglm/project.h \
               include/cglm/sphere.h \
               include/cglm/ease.h \
               include/cglm/curve.h \
               include/cglm/bezier.h \
               include/cglm/applesimd.h \
               include/cglm/ray.h \
               include/cglm/affine2d.h

cglm_clipspacedir=$(includedir)/cglm/clipspace
cglm_clipspace_HEADERS = include/cglm/clipspace/persp.h \
                         include/cglm/clipspace/persp_lh_no.h \
                         include/cglm/clipspace/persp_lh_zo.h \
                         include/cglm/clipspace/persp_rh_no.h \
                         include/cglm/clipspace/persp_rh_zo.h \
                         include/cglm/clipspace/ortho_lh_no.h \
                         include/cglm/clipspace/ortho_lh_zo.h \
                         include/cglm/clipspace/ortho_rh_no.h \
                         include/cglm/clipspace/ortho_rh_zo.h \
                         include/cglm/clipspace/view_lh.h \
                         include/cglm/clipspace/view_rh.h \
                         include/cglm/clipspace/view_lh_no.h \
                         include/cglm/clipspace/view_lh_zo.h \
                         include/cglm/clipspace/view_rh_no.h \
                         include/cglm/clipspace/view_rh_zo.h \
                         include/cglm/clipspace/project_no.h \
                         include/cglm/clipspace/project_zo.h

cglm_calldir=$(includedir)/cglm/call
cglm_call_HEADERS = include/cglm/call/mat4.h \
                    include/cglm/call/mat4x2.h \
                    include/cglm/call/mat4x3.h \
                    include/cglm/call/mat3.h \
                    include/cglm/call/mat3x2.h \
                    include/cglm/call/mat3x4.h \
                    include/cglm/call/mat2.h \
                    include/cglm/call/mat2x3.h \
                    include/cglm/call/mat2x4.h \
                    include/cglm/call/vec2.h \
                    include/cglm/call/vec3.h \
                    include/cglm/call/vec4.h \
                    include/cglm/call/ivec2.h \
                    include/cglm/call/ivec3.h \
                    include/cglm/call/ivec4.h \
                    include/cglm/call/io.h \
                    include/cglm/call/cam.h \
                    include/cglm/call/quat.h \
                    include/cglm/call/euler.h \
                    include/cglm/call/plane.h \
                    include/cglm/call/frustum.h \
                    include/cglm/call/box.h \
                    include/cglm/call/project.h \
                    include/cglm/call/sphere.h \
                    include/cglm/call/ease.h \
                    include/cglm/call/curve.h \
                    include/cglm/call/bezier.h \
                    include/cglm/call/ray.h \
                    include/cglm/call/affine.h \
                    include/cglm/call/affine2d.h

cglm_call_clipspacedir=$(includedir)/cglm/call/clipspace
cglm_call_clipspace_HEADERS = include/cglm/call/clipspace/persp_lh_no.h \
                              include/cglm/call/clipspace/persp_lh_zo.h \
                              include/cglm/call/clipspace/persp_rh_no.h \
                              include/cglm/call/clipspace/persp_rh_zo.h \
                              include/cglm/call/clipspace/ortho_lh_no.h \
                              include/cglm/call/clipspace/ortho_lh_zo.h \
                              include/cglm/call/clipspace/ortho_rh_no.h \
                              include/cglm/call/clipspace/ortho_rh_zo.h \
                              include/cglm/call/clipspace/view_lh_no.h \
                              include/cglm/call/clipspace/view_lh_zo.h \
                              include/cglm/call/clipspace/view_rh_no.h \
                              include/cglm/call/clipspace/view_rh_zo.h \
                              include/cglm/call/clipspace/project_no.h \
                              include/cglm/call/clipspace/project_zo.h

cglm_simddir=$(includedir)/cglm/simd
cglm_simd_HEADERS = include/cglm/simd/intrin.h \
                    include/cglm/simd/x86.h \
                    include/cglm/simd/arm.h \
                    include/cglm/simd/wasm.h

cglm_simd_sse2dir=$(includedir)/cglm/simd/sse2
cglm_simd_sse2_HEADERS = include/cglm/simd/sse2/affine.h \
                         include/cglm/simd/sse2/mat4.h \
                         include/cglm/simd/sse2/mat3.h \
                         include/cglm/simd/sse2/mat2.h \
                         include/cglm/simd/sse2/quat.h

cglm_simd_avxdir=$(includedir)/cglm/simd/avx
cglm_simd_avx_HEADERS = include/cglm/simd/avx/mat4.h \
                        include/cglm/simd/avx/affine.h

cglm_simd_neondir=$(includedir)/cglm/simd/neon
cglm_simd_neon_HEADERS = include/cglm/simd/neon/affine.h \
                         include/cglm/simd/neon/mat2.h \
                         include/cglm/simd/neon/mat4.h \
                         include/cglm/simd/neon/quat.h

cglm_simd_wasmdir=$(includedir)/cglm/simd/wasm
cglm_simd_wasm_HEADERS = include/cglm/simd/wasm/affine.h \
                         include/cglm/simd/wasm/mat2.h \
                         include/cglm/simd/wasm/mat3.h \
                         include/cglm/simd/wasm/mat4.h \
                         include/cglm/simd/wasm/quat.h

cglm_handeddir=$(includedir)/cglm/handed
cglm_handed_HEADERS = include/cglm/handed/euler_to_quat_lh.h \
                      include/cglm/handed/euler_to_quat_rh.h

cglm_structdir=$(includedir)/cglm/struct
cglm_struct_HEADERS = include/cglm/struct/mat4.h \
                      include/cglm/struct/mat4x2.h \
                      include/cglm/struct/mat4x3.h \
                      include/cglm/struct/mat3.h \
                      include/cglm/struct/mat3x2.h \
                      include/cglm/struct/mat3x4.h \
                      include/cglm/struct/mat2.h \
                      include/cglm/struct/mat2x3.h \
                      include/cglm/struct/mat2x4.h \
                      include/cglm/struct/affine-pre.h \
                      include/cglm/struct/affine-post.h \
                      include/cglm/struct/affine-mat.h \
                      include/cglm/struct/affine.h \
                      include/cglm/struct/affine2d.h \
                      include/cglm/struct/vec2.h \
                      include/cglm/struct/vec2-ext.h \
                      include/cglm/struct/ivec2.h \
                      include/cglm/struct/vec3.h \
                      include/cglm/struct/vec3-ext.h \
                      include/cglm/struct/ivec3.h \
                      include/cglm/struct/vec4.h \
                      include/cglm/struct/vec4-ext.h \
                      include/cglm/struct/ivec4.h \
                      include/cglm/struct/io.h \
                      include/cglm/struct/cam.h \
                      include/cglm/struct/quat.h \
                      include/cglm/struct/euler.h \
                      include/cglm/struct/plane.h \
                      include/cglm/struct/frustum.h \
                      include/cglm/struct/box.h \
                      include/cglm/struct/aabb2d.h \
                      include/cglm/struct/project.h \
                      include/cglm/struct/sphere.h \
                      include/cglm/struct/color.h \
                      include/cglm/struct/curve.h \
                      include/cglm/struct/ray.h

cglm_struct_clipspacedir=$(includedir)/cglm/struct/clipspace
cglm_struct_clipspace_HEADERS = include/cglm/struct/clipspace/persp_lh_no.h \
                                include/cglm/struct/clipspace/persp_lh_zo.h \
                                include/cglm/struct/clipspace/persp_rh_no.h \
                                include/cglm/struct/clipspace/persp_rh_zo.h \
                                include/cglm/struct/clipspace/ortho_lh_no.h \
                                include/cglm/struct/clipspace/ortho_lh_zo.h \
                                include/cglm/struct/clipspace/ortho_rh_no.h \
                                include/cglm/struct/clipspace/ortho_rh_zo.h \
                                include/cglm/struct/clipspace/view_lh_no.h \
                                include/cglm/struct/clipspace/view_lh_zo.h \
                                include/cglm/struct/clipspace/view_rh_no.h \
                                include/cglm/struct/clipspace/view_rh_zo.h \
                                include/cglm/struct/clipspace/project_no.h \
                                include/cglm/struct/clipspace/project_zo.h

cglm_struct_handeddir=$(includedir)/cglm/struct/handed
cglm_struct_handed_HEADERS = include/cglm/struct/handed/euler_to_quat_lh.h \
                             include/cglm/struct/handed/euler_to_quat_rh.h

libcglm_la_SOURCES=\
    src/euler.c \
    src/affine.c \
    src/io.c \
    src/quat.c \
    src/cam.c \
    src/vec2.c \
    src/ivec2.c \
    src/vec3.c \
    src/ivec3.c \
    src/vec4.c \
    src/ivec4.c \
    src/mat2.c \
    src/mat2x3.c \
    src/mat2x4.c \
    src/mat3.c \
    src/mat3x2.c \
    src/mat3x4.c \
    src/mat4.c \
    src/mat4x2.c \
    src/mat4x3.c \
    src/plane.c \
    src/frustum.c \
    src/box.c \
    src/project.c \
    src/sphere.c \
    src/ease.c \
    src/curve.c \
    src/bezier.c \
    src/ray.c \
    src/affine2d.c \
    src/clipspace/ortho_lh_no.c \
    src/clipspace/ortho_lh_zo.c \
    src/clipspace/ortho_rh_no.c \
    src/clipspace/ortho_rh_zo.c \
    src/clipspace/persp_lh_no.c \
    src/clipspace/persp_lh_zo.c \
    src/clipspace/persp_rh_no.c \
    src/clipspace/persp_rh_zo.c \
    src/clipspace/view_lh_no.c \
    src/clipspace/view_lh_zo.c \
    src/clipspace/view_rh_no.c \
    src/clipspace/view_rh_zo.c \
    src/clipspace/project_no.c \
    src/clipspace/project_zo.c
    
test_tests_SOURCES=\
    test/runner.c \
    test/src/test_common.c \
    test/src/tests.c \
    test/src/test_clamp.c \
    test/src/test_euler.c \
    test/src/test_bezier.c \
    test/src/test_struct.c

pkgconfig_DATA=cglm.pc

# When running configure with --prefix, $VPATH references
# the source directory that post-build.sh is in. When not
# using a prefix, $VPATH will be unset, so we need to fall
# back to using . to run the script.
#export VPATH

# all-local:
#	sh $${VPATH:-.}/post-build.sh
