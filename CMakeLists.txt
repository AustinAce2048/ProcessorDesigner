cmake_minimum_required (VERSION 3.20)

project (ProcessorDesigner)

add_executable (${PROJECT_NAME} main.cpp)
SET (TARGET_H designerHeader.h)
SET (TARGET_SRC graphics.cpp debug.cpp)

set (GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set (GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set (GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory (glfw/)

target_include_directories (${PROJECT_NAME} PUBLIC glfw)
target_link_libraries (${PROJECT_NAME} glfw)

set (IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
add_library (IMGUI STATIC)
target_sources (IMGUI PRIVATE ${IMGUI_DIR}/imgui_demo.cpp ${IMGUI_DIR}/imgui_draw.cpp ${IMGUI_DIR}/imgui_tables.cpp ${IMGUI_DIR}/imgui_widgets.cpp ${IMGUI_DIR}/imgui.cpp PRIVATE ${IMGUI_DIR}/imgui_impl_opengl3.cpp ${IMGUI_DIR}/imgui_impl_glfw.cpp ${IMGUI_DIR}/imgui_impl_opengl3.h ${IMGUI_DIR}/imgui_impl_glfw.h)
target_include_directories (IMGUI PUBLIC ${IMGUI_DIR} PUBLIC ${IMGUI_DIR}/backends)
target_link_libraries (IMGUI PUBLIC ${OPENGL_LIBRARIES})
target_link_libraries (${PROJECT_NAME} IMGUI)

add_subdirectory (glew/build/cmake)
target_include_directories (${PROJECT_NAME} PUBLIC glew)
target_link_libraries (${PROJECT_NAME} glew)

set (SOIL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/soil)
add_library (SOIL STATIC)
target_sources (SOIL PRIVATE ${SOIL_DIR}/src/soil.c ${SOIL_DIR}/include/soil/soil.h ${SOIL_DIR}/src/stb_image_aug.c ${SOIL_DIR}/src/image_helper.c ${SOIL_DIR}/src/image_dxt.c)
target_include_directories (SOIL PUBLIC ${SOIL_DIR})
target_link_libraries (${PROJECT_NAME} SOIL)

find_package (OpenGL REQUIRED)
target_link_libraries (${PROJECT_NAME} OpenGL::GL)