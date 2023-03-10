cmake_minimum_required(VERSION 3.0.0)
project(Maze VERSION 0.1.0)

#include(CTest)
#enable_testing()

include_directories(${PROJECT_SOURCE_DIR})

set(MY_SOURCES
    src/cell.h
    src/coordinate.h
    src/direction.h
    src/main.cpp
    src/maze.h
    src/move.h
    src/parser.cpp
    src/parser.h
    src/solver.cpp
    src/solver.h
    src/utils.cpp
    src/utils.h
)

add_executable(maze ${MY_SOURCES})


#find_package(nlohmann_json 3.2.0 REQUIRED)
#target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
SET(CMAKE_BUILD_TYPE Debug) 
include(CPack)
