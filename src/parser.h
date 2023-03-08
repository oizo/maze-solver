#pragma once
#include <iostream>
#include "src/maze.h"
#include "src/direction.h"

using namespace std;

namespace maze {
    class Parser
    {
    public:
        Parser() {};
        Maze* fromFilePath(const std::string &path);
    };
}
