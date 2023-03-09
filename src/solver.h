#pragma once
#include <vector>
#include "src/direction.h"
#include "src/maze.h"
#include "src/coordinate.h"

namespace maze {
    class Solver
    {
    private:
        Maze &maze;
    public:
        Solver(Maze &maze);
        std::vector<Direction> solve();
    };
}
