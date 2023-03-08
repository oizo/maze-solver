#include "src/maze.h"

namespace maze
{
	Maze::Maze(int seed, int width, int height, int entry, int exit, Grid grid)
	: seed(seed), width(width), height(height), entry(entry), exit(exit), grid(std::move(grid)) {}

}
