#include "src/utils.h"


namespace maze
{
    
    bool contains(const std::vector<Direction> &v, const Direction &d) {
        return std::find(v.begin(), v.end(), d) != v.end();
    }

    std::string info(const Maze &maze) {
        return "Maze[ w=" + std::to_string(maze.width) + 
        ", h=" + std::to_string(maze.height) + 
        ", entry=" + std::to_string(maze.entry) + 
        ", exit=" + std::to_string(maze.exit) + " ]";
    }

    Move* findMove(const Maze &maze, int &x, int &y) {
        for (auto move : maze.moves) {
            if (move.coord.x == x && move.coord.y == y) {
                return new Move(move);
            }
        }
        return nullptr;
    }

    std::string render(const Maze &maze, const RenderConfig &rc) {
        
        std::string result;

        auto grid = maze.grid;

        // Build entry indicator
        int width = (maze.width * 2) + 1;
        int entry = maze.entry * 2;
        std::string entryIndicator(entry - 1, rc.empty);
        entryIndicator += rc.entry;
        entryIndicator.append(width - entry, rc.empty);
        result += entryIndicator + "\n";

        // Build maze cell by cell
        for (int y = 0; y < grid.size(); ++y) {
            std::string top;
            std::string botttom;
            for (int x = 0; x < grid[y].size(); ++x) {
                auto &c = grid[y][x];
                top += rc.corner;
                top += contains(c.walls, Direction::NORTH) ? rc.wallH : rc.empty;
                botttom += contains(c.walls, Direction::WEST) ? rc.wallV : rc.empty;
                auto move = findMove(maze, x, y);
                botttom += move ? (move->isPathToExit ? rc.solution : rc.visited) : rc.empty;
            }
            top += rc.corner;
            botttom += rc.wallV;
            result += top + "\n";
            result += botttom + "\n";
        }

        // Build bottom row of maze
        std::string bottomRow;
        bottomRow += rc.corner;
        for (auto cell = grid.back().begin(); cell != grid.back().end(); ++cell) {
            bottomRow += contains((*cell).openings, Direction::SOUTH) ? rc.empty : rc.wallV;
            bottomRow += rc.corner;
        }
        result += bottomRow + "\n";

        // Build exit indicator
        int exit = maze.exit * 2;
        std::string exitIndicator(exit - 1, rc.empty);
        exitIndicator += rc.exit;
        exitIndicator.append(width - exit, rc.empty);
        result += exitIndicator;
        
        return result;
    }
}
