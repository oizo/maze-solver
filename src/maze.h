#pragma once
#include <vector>
#include "src/cell.h"
#include "src/move.h"

namespace maze
{
	typedef std::vector<std::vector<Cell*>*> Grid;

	class Maze
	{
	public:
		Maze(int &seed, int &width, int &height, int &entry, int &exit, Grid *grid)
			: seed(seed), width(width), height(height), entry(entry), exit(exit), grid(grid) {}
		~Maze() {
			for (auto row = grid->begin(); row != grid->end(); ++row) {
				for (auto c = (*row)->begin(); c != (*row)->end(); ++c) {
					delete *c;
				}
				delete *row;
			}
			delete grid;
		}
		const int seed;
		const int width;
		const int height;
		const int entry;
		const int exit;
		Grid *grid;
	};
}
