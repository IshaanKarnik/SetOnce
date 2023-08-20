# CMakeList.txt : CMake project for SetOnce, include source and define
# project specific logic here.
#

# Add source to this project's executable.
cmake_minimum_required (VERSION 3.8)
project(SetOnceExample)

add_executable (${PROJECT_NAME}  "main.cxx")

target_link_libraries(
    ${PROJECT_NAME}
    SetOnceLib
)
# TODO: Add tests and install targets if needed.
