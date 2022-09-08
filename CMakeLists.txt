cmake_minimum_required (VERSION 3.14)

project (ProcessorDesigner)

set (GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set (GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set (GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory (glfw/)

add_executable (${PROJECT_NAME} main.cpp)
target_include_directories (${PROJECT_NAME} PUBLIC glfw)
target_link_libraries (${PROJECT_NAME} glfw)

find_package (OpenGL REQUIRED)
target_link_libraries (${PROJECT_NAME} OpenGL::GL)