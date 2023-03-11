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
		Coordinate *entry = nullptr;
		Coordinate *exit = nullptr;
	};

    inline std::ostream &operator<< (std::ostream &os, Cell const &c) {
        os << "entry=" << c.entry << ", exit=" << c.exit;
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
