cmake_minimum_required(VERSION 3.20.0)
set(PROJECT_NAME static)
project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} MACOSX_BUNDLE)
target_sources(${PROJECT_NAME} PUBLIC  main.cpp static.cpp static_v1.cpp static_v2.cpp static_v3.cpp static_v4.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)

find_package(FreeGLUT CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)

link_libraries(FreeGLUT::freeglut GLEW::GLEW)