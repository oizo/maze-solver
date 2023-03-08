#pragma once
#include <iostream>
#include "src/maze.h"
#include "src/cell.h"

namespace maze {
    std::string info(const Maze &maze);
    std::string draw(const Maze &maze);
    bool contains(const std::vector<Direction> &v, const Direction &d);
}
