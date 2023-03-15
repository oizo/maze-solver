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

    void color(std::string &result, const int &color, const char &c) {
        result += "\033[";
        result += std::to_string(color);
        result += ";1m";
        result += c;
        result += "\033[0m";
    }

    void noColor(std::string &result, const char &c) {
        result += c;
    }

    std::string render(const Maze &maze, const RenderConfig &rc) {

        std::string result;

        auto grid = maze.grid;

        // Build entry indicator
        int width = (maze.width * 2) + 1;
        int entry = maze.entry * 2;
        std::string entryIndicator(entry - 1, rc.empty);
        color(entryIndicator, rc.color.path, rc.entry);
        entryIndicator.append(width - entry, rc.empty);
        result += entryIndicator + "\n";

        // Build maze cell by cell
        for (int y = 0; y < grid->size(); ++y) {
            std::string top;
            std::string botttom;
            for (int x = 0; x < grid->at(y)->size(); ++x) {
                auto *c = grid->at(y)->at(x);
                noColor(top, rc.corner);
                // Draw horizontal walls
                contains(c->walls, Direction::NORTH)
                    ? noColor(top, rc.wallH)
                    : color(top, rc.color.empty, rc.empty);
                // Draw vertical walls
                contains(c->walls, Direction::WEST)
                    ? noColor(botttom, rc.wallV)
                    : color(botttom, rc.color.empty, rc.empty);
                // Draw the cell
                c->entry
                    ? c->exit
                        ? color(botttom, rc.color.path, rc.path)
                        : color(botttom, rc.color.visited, rc.visited)
                    : color(botttom, rc.color.empty, rc.empty);

            }
            noColor(top, rc.corner);
            noColor(botttom, rc.wallV);
            result += top + "\n";
            result += botttom + "\n";
        }

        // Build bottom row of maze
        std::string bottomRow;
        noColor(bottomRow, rc.corner);
        for (auto cell = grid->back()->begin(); cell != grid->back()->end(); ++cell) {
            contains((*cell)->openings, Direction::SOUTH)
                ? color(bottomRow, rc.color.empty, rc.empty)
                : noColor(bottomRow, rc.wallH);
            noColor(bottomRow, rc.corner);
        }
        result += bottomRow + "\n";

        // Build exit indicator
        int exit = maze.exit * 2;
        std::string exitIndicator(exit - 1, rc.empty);
        color(exitIndicator, rc.color.path, rc.exit);
        exitIndicator.append(width - exit, rc.empty);
        result += exitIndicator;

        return result;
    }
}
