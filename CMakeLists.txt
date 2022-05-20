cmake_minimum_required(VERSION 3.8.2)
project(cglm VERSION 0.8.6 LANGUAGES C)

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

if(NOT CPack_CMake_INCLUDED)
  include(CPack)
endif()

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
  src/ivec2.c
  src/ivec3.c
  src/ivec4.c
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
  src/clipspace/persp_lh_zo.c
  src/clipspace/persp_rh_zo.c
  src/clipspace/persp_lh_no.c
  src/clipspace/persp_rh_no.c
  src/clipspace/ortho_lh_zo.c
  src/clipspace/ortho_rh_zo.c
  src/clipspace/ortho_lh_no.c
  src/clipspace/ortho_rh_no.c
  src/clipspace/view_lh_zo.c
  src/clipspace/view_rh_zo.c
  src/clipspace/view_lh_no.c
  src/clipspace/view_rh_no.c
  )

if(CGLM_SHARED)
  add_definitions(-DCGLM_EXPORTS)
else()
  target_compile_definitions(${PROJECT_NAME} PUBLIC -DCGLM_STATIC)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
                              VERSION ${PROJECT_VERSION} 
                            SOVERSION ${PROJECT_VERSION_MAJOR})

if(WIN32)
  # Because SOVERSION has no effect to file naming on Windows
  set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_NAME ${PROJECT_NAME}-${PROJECT_VERSION_MAJOR})
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Target for header-only usage
add_library(${PROJECT_NAME}_headers INTERFACE)
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
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

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

set(PACKAGE_NAME ${PROJECT_NAME})
set(prefix ${CMAKE_INSTALL_PREFIX})
set(exec_prefix ${CMAKE_INSTALL_PREFIX})
if (IS_ABSOLUTE "${CMAKE_INSTALL_INCLUDEDIR}")
  set(includedir "${CMAKE_INSTALL_INCLUDEDIR}")
else()
  set(includedir "\${prefix}/${CMAKE_INSTALL_INCLUDEDIR}")
endif()
if (IS_ABSOLUTE "${CMAKE_INSTALL_LIBDIR}")
  set(libdir "${CMAKE_INSTALL_LIBDIR}")
else()
  set(libdir "\${exec_prefix}/${CMAKE_INSTALL_LIBDIR}")
endif()
set(PACKAGE_VERSION "${PROJECT_VERSION}")
configure_file(${CMAKE_CURRENT_LIST_DIR}/cglm.pc.in ${CMAKE_BINARY_DIR}/cglm.pc @ONLY)

install(FILES ${CMAKE_BINARY_DIR}/cglm.pc
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
