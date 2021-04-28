cmake_minimum_required(VERSION 3.17)
project(glm_cmp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMP_MAIN glmcmp)

add_subdirectory(glm)

add_executable(${CMP_MAIN} src/main.cpp)

target_link_libraries(${CMP_MAIN} PRIVATE glm)

