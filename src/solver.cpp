#include <iostream>
#include "src/direction.h"
#include "src/move.h"
#include "src/solver.h"
#include "src/utils.h"

namespace maze {

    Coordinate generateNextCoordinate(const Coordinate &c, const Direction &d) {
        switch (d) {
            case Direction::NORTH: return Coordinate(c.x, c.y-1);
            case Direction::SOUTH: return Coordinate(c.x, c.y+1);
            case Direction::EAST: return Coordinate(c.x+1, c.y);
            case Direction::WEST: return Coordinate(c.x-1, c.y);
            default: throw std::logic_error("This can't happen");
        }
    }

    Direction getDirectionFrom(const Coordinate &from, const Coordinate &to) {
        if (from.x < to.x) return Direction::WEST;
        if (from.x > to.x) return Direction::EAST;
        if (from.y < to.y) return Direction::NORTH;
        return Direction::SOUTH;
    }

    bool Solver::solve(Maze &maze, Coordinate &from, Coordinate &current) {

        auto cell = maze.grid->at(current.y)->at(current.x);
        cell->entry = &from;

        // Check if we're done
        if (current.x == maze.exit - 1 && current.y == maze.height - 1) {
            cell->exit = &current;
            return true;
        }

        // Check if we hit a dead end
        if (cell->walls.size() == 3) {
            return false;
        }

        // Check neighbouring cells
        auto entryFrom = getDirectionFrom(from, current);
        for (auto opening : cell->openings) {
            if (entryFrom == opening) {
                // Don't move back in the direction we came from
                continue;
            }
            auto nextCoord = generateNextCoordinate(current, opening);
            bool solved = solve(maze, current, nextCoord);
            if (solved) {
                cell->exit = &nextCoord;
                return true;
            }
        }
        return false;
    }

    bool Solver::solve(Maze &maze) {
        // We'll make the from coordinate start out side of the maze
        // it's a bit of a hack, but it'll work
        auto from = Coordinate(maze.entry - 1, -1);
        auto to = Coordinate(maze.entry - 1, 0);
        return solve(maze, from, to);
    }
}
