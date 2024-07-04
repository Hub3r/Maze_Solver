#include "inc/maze_node.h"

MazeNode::MazeNode()
{
    visited = false;
    walls = 0xF;
    col = 0;
    row = 0;
}

bool MazeNode::hasWall(int wall) const
{
    return walls & (1 << wall);
}

bool MazeNode::setWall(int wall)
{
    return walls |= (1 << wall);
}

bool MazeNode::removeWall(int wall)
{
    return walls &= ~(1 << wall);
}

bool MazeNode::isVisited() const
{
    return visited;
}

void MazeNode::markVisited()
{
    visited = true;
}

void MazeNode::markUnVisited()
{
    visited = false;
}

int MazeNode::getWalls()
{
    return walls;
}

std::pair<int, int> MazeNode::getCoords()
{
    std::pair<int, int> coords;
    coords.first = row;
    coords.second = col;
    return coords;
}

void MazeNode::setCoords(int row, int col)
{
    this->row = row;
    this->col = col;
}