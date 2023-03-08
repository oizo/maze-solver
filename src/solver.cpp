#include <iostream>
#include "src/solver.h"
#include "src/direction.h"
#include "src/utils.h"

namespace maze {

    Solver::Solver(Maze &maze) : maze(maze) {};

    Coordinate nextCoordinate(const Coordinate &c, const Direction &d) {
        switch (d)
        {
        case Direction::NORTH: return Coordinate(c.x, c.y-1);
        case Direction::SOUTH: return Coordinate(c.x, c.y+1);
        case Direction::EAST: return Coordinate(c.x+1, c.y);
        case Direction::WEST: return Coordinate(c.x-1, c.y);
        default: throw std::logic_error("This can't happen");
        }
    }

    bool move(Maze &maze, std::vector<Direction> &solution, const Direction &entry, const Coordinate &current) {
        Cell& cell = maze.grid[current.y][current.x];

        // Check if we're running into some recursion issues
        if (cell.visited) {
            return false;
        }
        cell.visited = true;

        // Check if we're done
        if (current.x == maze.exit - 1 && current.y == maze.height - 1) {
            cell.solution = true;
            return true;
        }

        // Check if we hit a dead end
        if (cell.walls.size() > 3) {
            return false;
        }

        // Check neighbouring cells
        auto openings = cell.openings;
        for (auto o = openings.begin(); o != openings.end(); ++o) {
            if (entry == *o) {
                // Don't move back in the direction we came from
                continue;
            }
            solution.push_back(*o);
            auto next = nextCoordinate(current, *o);
            auto reversed = reverse(*o);
            bool mazeCompleted = move(maze, solution, reversed, next);
            if (mazeCompleted) {
                cell.solution = true;
                return true;
            } else {
                solution.pop_back();
            }
        }
        return false;
    }

    std::vector<Direction> Solver::solve()
    {
        auto solution = std::vector<Direction>();
        auto initCell = Coordinate(maze.entry - 1, 0);
        auto success = move(maze, solution, Direction::NORTH, initCell);
        return solution;
    }

}
