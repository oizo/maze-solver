#include <fstream>
#include <sstream>
#include <iostream>
#include "src/parser.h"
#include "src/cell.h"
#include "src/maze.h"

namespace maze {

    std::vector<Direction> toOpenings(const int &value)
    {
        std::vector<Direction> tmp;
        if (~value & 1) tmp.push_back(Direction::NORTH);
        if (~value & 2) tmp.push_back(Direction::SOUTH);
        if (~value & 4) tmp.push_back(Direction::EAST);
        if (~value & 8) tmp.push_back(Direction::WEST);
        return tmp;
    }

    std::vector<Direction> toWalls(const int &value)
    {
        std::vector<Direction> tmp;
        if (value & 1) tmp.push_back(Direction::NORTH);
        if (value & 2) tmp.push_back(Direction::SOUTH);
        if (value & 4) tmp.push_back(Direction::EAST);
        if (value & 8) tmp.push_back(Direction::WEST);
        return tmp;
    }

    Maze* Parser::fromFilePath(const std::string& path)
    {
        // We should check the file format, but for now we'll assume proprietary
        std::ifstream file;
        file.open(path);
        if (!file.is_open()) {
            cout << "Invalid file path: " << path << std::endl;
            return nullptr;
        }
        std::string line;
        int current = 0, seed = 0, width = 0, height = 0, entry = 0, exit = 0;
        Grid grid;
        while (std::getline(file, line)) {
            switch (current)
            {
            case 0:
                sscanf(line.c_str(), "%d", &seed);
                break;
            case 1:
                sscanf(line.c_str(), "%d %d", &width, &height);
                break;
            case 2:
                sscanf(line.c_str(), "%d %d", &entry, &exit);
                break;
            default:
                stringstream ss(line);
                vector<Cell> row;
                while(ss.good())
                {
                    string substr;
                    getline(ss, substr, ',');
                    auto values = atoi(substr.c_str());
                    auto openings = toOpenings(values);
                    auto walls = toWalls(values);
                    auto cell = Cell(walls, openings);
                    row.push_back(cell);
                }
                grid.push_back(row);
                break;
            }
            current++;
        }
        auto maze = new Maze(seed, width, height, entry, exit, grid);
        return maze;
    }

}
