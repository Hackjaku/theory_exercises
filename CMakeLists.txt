cmake_minimum_required(VERSION 3.10)
project(exercise CXX)

include(CheckIncludeFileCXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cc)

find_package(Boost 1.78.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})


aux_source_directory(utils UTIL_SRC)
aux_source_directory(models MODEL_SRC)

target_include_directories(${PROJECT_NAME}
                            PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
                                    ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${PROJECT_NAME}
                PRIVATE
                ${UTIL_SRC}
                ${MODEL_SRC}
                ${SRC_DIR})