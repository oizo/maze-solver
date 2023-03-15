#pragma once
#include <iostream>
#include "src/maze.h"
#include "src/cell.h"

namespace maze {

    struct RenderColor {
        int path = 93;
        int visited = 90;
        int empty = 97;
    };

    struct RenderConfig {
        char corner = '+';
        char wallH = '-';
        char wallV = '|';
        char visited = '*';
        char path = '*';
        char empty = ' ';
        char entry = 'v';
        char exit = 'v';
        RenderColor color;
    };
    
    std::string info(const Maze &maze);
    std::string render(const Maze &maze, const RenderConfig &rc = RenderConfig{});
    bool contains(const std::vector<Direction> &v, const Direction &d);
}
