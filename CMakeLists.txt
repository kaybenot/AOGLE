cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT_NAME "my_program")

project(${PROJECT_NAME})
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
