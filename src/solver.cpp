#include <iostream>
#include "src/direction.h"
#include "src/move.h"
#include "src/solver.h"
#include "src/utils.h"

namespace maze {

    Solver::Solver(Maze &maze) : maze(maze) {};

    Coordinate generateNextCoordinate(const Coordinate &c, const Direction &d) {
        switch (d) {
            case Direction::NORTH: return Coordinate(c.x, c.y-1);
            case Direction::SOUTH: return Coordinate(c.x, c.y+1);
            case Direction::EAST: return Coordinate(c.x+1, c.y);
            case Direction::WEST: return Coordinate(c.x-1, c.y);
            default: throw std::logic_error("This can't happen");
        }
    }

    Move createNextMove(const Coordinate &coord, const Direction &dirTo) {
        auto nextCoord = generateNextCoordinate(coord, dirTo);
        auto fromDir = reverse(dirTo);
        return Move(fromDir, nextCoord);
    }

    bool visited(const std::vector<Move> &moves) {
        for (auto &lhs : moves) {
            for (auto &rhs : moves) {
                if (&lhs != &rhs && lhs.coord.x == rhs.coord.x && lhs.coord.y == rhs.coord.y) {
                    return true;
                }
            }
        }
        return false;
    }

    bool moveTo(Maze &maze) {

        // We need to define the entry first
        if (maze.moves.empty()) {
            auto coord = Coordinate(maze.entry - 1, 0);
            auto initMove = Move(Direction::NORTH, coord);
            maze.moves.push_back(initMove);
        }

        const int index = maze.moves.size() - 1;
        auto &cell = maze.grid[maze.moves[index].coord.y][maze.moves[index].coord.x];

        // Check if we're done
        if (maze.moves[index].coord.x == maze.exit - 1 && maze.moves[index].coord.y == maze.height - 1) {
            cell.move = &maze.moves[index];
            cell.move->isPathToExit = true;
            return true;
        }

        // Check if we're running into some recursion issues
        // TODO Visited function is way too slow, needs to be fixed
        // if (visited(maze.moves)) {
        //     maze.moves.pop_back();
        //     return false;
        // }

        // Check if we hit a dead end
        if (cell.walls.size() == 3) {
            return false;
        }

        // Check neighbouring cells
        auto openings = cell.openings;
        for (auto opening : openings) {
            if (maze.moves[index].entryFrom == opening) {
                // Don't move back in the direction we came from
                continue;
            }
            auto nextMove = createNextMove(maze.moves[index].coord, opening);
            maze.moves.push_back(nextMove);
            bool completed = moveTo(maze);
            if (completed) {
                cell.move = &maze.moves[index];
                cell.move->isPathToExit = true;
                return true;
            }
        }
        return false;
    }

    bool Solver::solve() {
        return moveTo(maze);
    }
}
