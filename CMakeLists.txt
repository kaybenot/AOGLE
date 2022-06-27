cmake_minimum_required(VERSION 3.12)

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

set(BUILD_SHARED_LIBS OFF)
set(EXTERNALS glm assimp glad SDL2-static SDL2main opengl32)

add_subdirectory(external/glm)
add_subdirectory(external/assimp)
add_subdirectory(external/glad)
add_subdirectory(external/SDL)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME "AOGLE")

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/AOGLE/*.cpp)

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/include/AOGLE)
target_link_libraries(${PROJECT_NAME} ${EXTERNALS})
