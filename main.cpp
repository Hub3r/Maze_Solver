#include <cstdio>
#include <cstdlib> // For atoi
#include <iostream>
#include "maze_objects/inc/maze.h"
#include "solving_algorithms/breadth_first/breadth_first.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <rows> <cols> <algorithm>" << std::endl;
        return 1;
    }

    int rows = std::atoi(argv[1]);
    int cols = std::atoi(argv[2]);

    if (rows > 65 || cols > 100)
    {
        std::cerr << "Error! Large Mazes will cause issues because of recursion depth enter a row/col less than 50" << std::endl;
        return 1;
    }

    std::string algorithm = argv[3];
    Maze maze(cols, rows, algorithm);

    // maze.printMaze();
    // printf("Rows %d: Cols %d\n", maze.rows, maze.cols);
    int startRow = (rand() % (rows - 1)) + 1;
    int startCol = (rand() % (cols - 1)) + 1;

    int endRow = (rand() % (rows - 1)) + 1;
    int endCol = (rand() % (cols - 1)) + 1;

    BreadthFirstSearch bfs(maze);
    if (bfs.solveMaze(startRow, startCol, endRow, endCol))
    {
        printf("yay\n");
    }
    else
    {
        printf("boo\n");
    }

    return 0;
}
