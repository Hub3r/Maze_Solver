#ifndef MAZE_NODE
#define MAZE_NODE

#include <stdio.h>
#include <string>

// Wall Locations are based on bit positions
//  0xWESN
const int WALL_NORTH = 0; // 0x0001
const int WALL_SOUTH = 1; // 0x0010
const int WALL_EAST = 2;  // 0x0100
const int WALL_WEST = 3;  // 0x1000

class MazeNode
{
public:
    MazeNode();

    bool setWall(int wall);
    bool removeWall(int wall);
    bool hasWall(int wall) const;
    bool isVisited() const;
    void markVisited();
    void markUnVisited();
    int getWalls();
    std::pair<int , int> getCoords();
    void setCoords(int row, int col);

private:
    int walls;
    bool visited;
    int row, col;
};

#endif