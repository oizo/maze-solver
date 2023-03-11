#pragma once
#include <algorithm>
#include <vector>
#include "src/direction.h"
#include "src/move.h"

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
		Move *move;
	};

    inline std::ostream &operator<< (std::ostream &os, Cell const &c) {
        os << "visited=" << c.visited << ", solution=" << c.solution;
		os << ", openings[";
		bool first = true;
		for (auto o = c.openings.begin(); o != c.openings.end(); ++o) {
			if (!first) {
				os << ", ";
			}
			first = false;
			os << (*o);
		}
		os << "], walls[";
		first = true;
		for (auto w = c.walls.begin(); w != c.walls.end(); ++w) {
			if (!first) {
				os << ", ";
			}
			first = false;
			os << (*w);
		}
		os << "]";
        return os;
    }
}
