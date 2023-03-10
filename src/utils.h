#pragma once
#include <iostream>
#include "src/maze.h"
#include "src/cell.h"

namespace maze {
    struct RenderConfig {
        char corner = '+';
        char wallH = '-';
        char wallV = '|';
        char visited = '.';
        char solution = '*';
        char empty = ' ';
        char entry = 'v';
        char exit = 'v';
    };
    
    std::string info(const Maze &maze);
    std::string render(const Maze &maze, const RenderConfig &rc = RenderConfig{});
    bool contains(const std::vector<Direction> &v, const Direction &d);
}
