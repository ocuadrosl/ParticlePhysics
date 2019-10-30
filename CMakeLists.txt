cmake_minimum_required(VERSION 3.5)

project(ParticlePhysics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

file(GLOB src "*.h"  "*.cpp" )

add_executable(ParticlePhysics main.cpp ${src})

INCLUDE_DIRECTORIES(${QT_QTOPENGL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} )

target_link_libraries(${PROJECT_NAME}  ${OPENGL_gl_LIBRARY})
target_link_libraries(${PROJECT_NAME}  ${GLUT_LIBRARIES})
