# CMakeList.txt : CMake project for SetOnce, include source and define
# project specific logic here.
#

# Add source to this project's executable.
cmake_minimum_required (VERSION 3.8)
project(SetOnceLib)

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET SetOnce PROPERTY CXX_STANDARD 11)
#endif()
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_library(
    ${PROJECT_NAME}
    INTERFACE
    ${SRC_SETONCE}
)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    ${PROJECT_SOURCE_DIR}
)
# TODO: Add tests and install targets if needed.
