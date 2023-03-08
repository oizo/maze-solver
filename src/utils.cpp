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

    std::string draw(const Maze &maze) {
        
        std::string result;

        auto grid = maze.grid;

        // Build entry indicator
        int width = (maze.width * 2) + 1;
        int entry = maze.entry * 2;
        std::string entryIndicator(entry - 1, ' ');
        entryIndicator += 'v';
        entryIndicator.append(width - entry, ' ');
        result += entryIndicator + "\n";

        // Build maze cell by cell
        for (auto row = grid.begin(); row != grid.end(); ++row) {
            std::string top;
            std::string botttom;
            for (auto cell = (*row).begin(); cell != (*row).end(); ++cell) {
                auto c = *cell;
                top += '+';
                top += contains(c.walls, Direction::NORTH) ? '-' : ' ';
                botttom += contains(c.walls, Direction::WEST) ? '|' : ' ';
                botttom += c.visited ? (c.solution ? '*' : '.') : ' ';
            }
            top += '+';
            botttom += '|';
            result += top + "\n";
            result += botttom + "\n";
        }

        // Build bottom row of maze
        std::string bottomRow("+");
        for (auto cell = grid.back().begin(); cell != grid.back().end(); ++cell) {
            bottomRow += contains((*cell).openings, Direction::SOUTH) ? " +" : "-+";
        }
        result += bottomRow + "\n";

        // Build exit indicator
        int exit = maze.exit * 2;
        std::string exitIndicator(exit - 1, ' ');
        exitIndicator += 'v';
        exitIndicator.append(width - exit, ' ');
        result += exitIndicator;
        
        return result;
    }
}
