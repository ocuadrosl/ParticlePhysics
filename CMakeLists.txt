cmake_minimum_required(VERSION 3.5)

project(ParticlePhysics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

file(GLOB src "*.h"  "*.cpp" )

add_executable(ParticlePhysics main.cpp ${src})

INCLUDE_DIRECTORIES(${QT_QTOPENGL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})
#target_link_libraries(${PROJECT_NAME} ${GLUT_LIBRARIES})
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES})
