#include <iostream>
#include "src/maze.h"
#include "src/parser.h"
#include "src/solver.h"
#include "src/utils.h"
#include "src/direction.h"

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cout << "Usage: " << std::string(argv[0]) << " <path-to-maze>" << std::endl;
        return 0;
    }

    auto path = std::string(argv[1]);
    auto parser = maze::Parser();
    auto maze = parser.fromFilePath(path);
    if (!maze) {
        return 0;
    }

    auto solver = maze::Solver();
    auto solution = solver.solve(*maze);
    maze::RenderConfig rc;
    rc.visited = ' ';
    std::cout << maze::render(*maze, rc) << std::endl;
    delete maze;
    return 0;
}
