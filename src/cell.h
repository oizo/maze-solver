#pragma once
#include <algorithm>
#include <vector>
#include "src/coordinate.h"
#include "src/direction.h"

namespace maze
{

	class Cell
	{
	private:
	public:
		Cell(std::vector<Direction> walls, std::vector<Direction> openings)
			: walls(std::move(walls)), openings(std::move(openings)) {};
		const std::vector<Direction> openings;
		const std::vector<Direction> walls;
		bool visited = false;
		bool solution = false;
	};
}
