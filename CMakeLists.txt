cmake_minimum_required(VERSION 3.7.2)
project(ParesGame)

# Headers
include_directories(include)

# Words
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data/words.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# OpenGL & GLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

file(GLOB_RECURSE pares_SOURCES "src/main.cpp")

add_executable(Pares ${pares_SOURCES})

target_link_libraries(Pares ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
