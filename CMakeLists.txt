cmake_minimum_required(VERSION 3.0.0)
project(Maze VERSION 0.1.0)

#include(CTest)
#enable_testing()

include_directories(${PROJECT_SOURCE_DIR})

set(MY_SOURCES
    src/main.cpp
    src/cell.h
    src/cell.cpp
    src/coordinate.h
    src/coordinate.cpp
    src/parser.h
    src/parser.cpp
    src/solver.h
    src/solver.cpp
    src/maze.h
    src/maze.cpp
    src/utils.h
    src/utils.cpp
)

add_executable(maze ${MY_SOURCES})


#find_package(nlohmann_json 3.2.0 REQUIRED)
#target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
SET(CMAKE_BUILD_TYPE Debug) 
include(CPack)
