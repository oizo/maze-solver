#pragma once
#include <vector>
#include "src/cell.h"

namespace maze
{
	typedef std::vector<std::vector<Cell>> Grid;

	class Maze
	{
	public:
		Maze(int& seed, int& width, int& height, int& entry, int& exit, Grid& grid)
			: seed(seed), width(width), height(height), entry(entry), exit(exit), grid(std::move(grid)) {}
		const int seed;
		const int width;
		const int height;
		const int entry;
		const int exit;
		Grid grid;
	};
}
