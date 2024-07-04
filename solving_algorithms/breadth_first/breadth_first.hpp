#ifndef BREADTH_FIRST_CPP
#define BREADTH_FIRST_CPP

#include "../../maze_objects/inc/maze.h"
#include <queue>
#include <vector>

class BreadthFirstSearch
{
public:
    BreadthFirstSearch(Maze &maze);
    bool solveMaze(int startRow, int startCol, int endRow, int endCol);
    void printSolution() const;
    void printExploration(int currCol, int currRow) const;
private:
    Maze& maze;
    std::vector<std::vector<bool>> visited;
    std::vector<std::pair<int, int>> path;
};

#endif