cmake_minimum_required(VERSION 3.12)

set(BUILD_SHARED_LIBS OFF)
set(EXTERNALS glm SDL2-static SDL2main opengl32)

add_subdirectory(external/glm)
add_subdirectory(external/SDL)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME "AOGLE")

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} ${EXTERNALS})
