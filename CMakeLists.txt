cmake_minimum_required(VERSION 3.22)
project(metalib)

set(CMAKE_CXX_STANDARD 23)

add_library(metalib INTERFACE)
target_include_directories(metalib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

export(TARGETS metalib NAMESPACE metalib:: FILE "metalib_targets.cmake")

if (${PROJECT_NAME}_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif ()
