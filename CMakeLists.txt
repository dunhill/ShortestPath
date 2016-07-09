project(ShortestPath)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SRC_COMMON_FILES ${PROJECT_SOURCE_DIR}/common/*.cpp)
file(GLOB_RECURSE SRC_ALGO_FILES ${PROJECT_SOURCE_DIR}/algo/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${SRC_COMMON_FILES} ${SRC_ALGO_FILES})

#aux_source_directory(. common/. SRC_LIST)
#aux_source_directory(common/. SRC_LIST)
#aux_source_directory(algo/. SRC_LIST)
#add_executable(${PROJECT_NAME} ${SRC_LIST})

