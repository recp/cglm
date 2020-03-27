cmake_minimum_required(VERSION 3.8.2)

# List all files containing tests. (Change as needed)
set(TESTFILES
  runner.c
  src/test_euler.c
  src/test_bezier.c
  src/test_cam.c
  src/test_struct.c
  src/test_clamp.c
  src/test_common.c
  src/tests.c
  )

set(TEST_MAIN tests)
set(TEST_RUNNER_PARAMS "")

add_executable(${TEST_MAIN} ${TESTFILES})

target_link_libraries(${TEST_MAIN} PRIVATE cglm m)
target_include_directories(${TEST_MAIN} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
  ${CMAKE_CURRENT_LIST_DIR}/src
  )

set_target_properties(${TEST_MAIN} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

if(LDFLAGS)
  target_compile_options(${TEST_MAIN} PRIVATE ${LDFLAGS})
endif()

add_test(
    NAME cglm.${TEST_MAIN}
    COMMAND ${TEST_MAIN} ${TEST_RUNNER_PARAMS})

add_custom_target(check
  make
  COMMAND ${CMAKE_CTEST_COMMAND} -V
  DEPENDS cglm)
