#include "inc/maze_node.h"
#include <cassert>
#include <iostream>

class MazeNodeTest
{
public:
    MazeNode node;

    void assertEquals(bool expected, bool actual, std::string message)
    {
        if (expected != actual)
        {
            std::cerr << "Assertion failed: " << message << std::endl;
            std::cerr << "Expected: " << expected << ", but got: " << actual << std::endl;
            assert(false);
        }
    }
};

void testSetWall() {
    MazeNodeTest nodeTest;
    nodeTest.node.setWall(WALL_NORTH);
    nodeTest.assertEquals(true, nodeTest.node.hasWall(WALL_NORTH), "WALL_NORTH");
    nodeTest.assertEquals(false, nodeTest.node.hasWall(WALL_SOUTH), "WALL_SOUTH");
}

void testRemoveWall() {
    MazeNodeTest nodeTest;
    nodeTest.node.setWall(WALL_NORTH);
    nodeTest.assertEquals(true, nodeTest.node.hasWall(WALL_NORTH), "WALL_NORTH");
    nodeTest.node.removeWall(WALL_NORTH);
    nodeTest.assertEquals(false, nodeTest.node.hasWall(WALL_NORTH), "WALL_NORTH");
}

void testVisited() {
    MazeNodeTest nodeTest;
    nodeTest.assertEquals(false, nodeTest.node.isVisited(), "NOT VISITED");
    nodeTest.node.markVisited();
    nodeTest.assertEquals(true, nodeTest.node.isVisited(), "VISITED");
}

int main() {
    testSetWall();
    testRemoveWall();
    testVisited();

    std::cout << "All Tests Passed!\n" << std::endl;
    return 0;
}