cmake_minimum_required(VERSION 3.10)
project(exercise CXX)

include(CheckIncludeFileCXX)

add_executable(${PROJECT_NAME} main.cc)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost 1.61.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})

target_sources(${PROJECT_NAME} PRIVATE ${SRC_DIR})