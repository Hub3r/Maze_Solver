#ifndef MAZE_CPP
#define MAZE_CPP

#include "maze_node.h"
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iostream>
#include <stack>
#include <thread>

class Maze
{
public:
    std::vector<std::vector<MazeNode> > nodes;
    int rows, cols;

    Maze(int columns, int rows, const std::string &algorithm);
    void setWall(int row, int col, int wall);
    void clearWall(int row, int col, int wall);
    bool hasWall(int row, int col, int wall) const;
    void generateMaze();
    void generateMazeRecursiveBacktracking();
    void generateMazeStackBacktracking();
    std::vector<std::pair<int, int> > getUnvisitedNeighbors(int row, int col);

    void printMaze() const;

private:
    std::string generationAlgorithm;

    void visitNodeRecursiveBacktracking(int row, int col);
    void visitNodeStackBacktracking(int row, int col);

    void unVisitNodes(int row, int col);
};

#endif // MAZE_CPP