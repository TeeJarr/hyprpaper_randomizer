cmake_minimum_required(VERSION 3.16)
project(random_paper VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS "-Wall")
SET(CMAKE_CXX_FLAGS_DEBUG "-g")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3")

# file(GLOB_RECURSE DATA src/data/*.cpp)

add_executable(${PROJECT_NAME} main.cpp)
# target_include_directories(${PROJECT_NAME} PUBLIC include include/pokemon include/data)
# target_link_libraries(${PROJECT_NAME} PUBLIC tlib)

