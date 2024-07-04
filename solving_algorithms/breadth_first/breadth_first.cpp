#include "breadth_first.hpp"

BreadthFirstSearch::BreadthFirstSearch(Maze &maze) : maze(maze), visited(maze.nodes.size(), std::vector<bool>(maze.nodes[0].size(), false))
{
}

bool BreadthFirstSearch::solveMaze(int startRow, int startCol, int endRow, int endCol)
{

    std::queue<MazeNode> mazeNodes;
    MazeNode root = maze.nodes[startRow][startCol];
    visited[startRow][startCol] = true;

    mazeNodes.push(root);

    while (!mazeNodes.empty())
    {
        MazeNode currentNode(mazeNodes.front());
        mazeNodes.pop();
        printExploration(currentNode.getCoords().first, currentNode.getCoords().second);
        std::cout << "End Row: " << endRow << " : End Col: " << endCol << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "\033[2J\033[H";
        // printf("Current Node: %d:%d\n", currentNode.getCoords().first, currentNode.getCoords().second);
        if (currentNode.getCoords().first == endRow && currentNode.getCoords().second == endCol)
        {
            printExploration(currentNode.getCoords().first, currentNode.getCoords().second);
            return true;
        }
        else
        {
            auto neighbors = maze.getUnvisitedNeighbors(currentNode.getCoords().first, currentNode.getCoords().second);
            for (auto &neighbor : neighbors)
            {
                if (!visited[neighbor.first][neighbor.second])
                {
                    if (currentNode.getCoords().first == neighbor.first)
                    { // nodes occupy the same row
                        if (currentNode.getCoords().second < neighbor.second)
                        {
                            // node is to the east
                            if (!maze.nodes[currentNode.getCoords().first][currentNode.getCoords().second].hasWall(WALL_EAST))
                            {
                                visited[neighbor.first][neighbor.second] = true;
                                mazeNodes.push(maze.nodes[neighbor.first][neighbor.second]);
                            }
                        }
                        else
                        {
                            // node is to the west
                            if (!maze.nodes[currentNode.getCoords().first][currentNode.getCoords().second].hasWall(WALL_WEST))
                            {
                                visited[neighbor.first][neighbor.second] = true;
                                mazeNodes.push(maze.nodes[neighbor.first][neighbor.second]);
                            }
                        }
                    }
                    if (currentNode.getCoords().second == neighbor.second)
                    { // nodes occupy the same column
                        if (currentNode.getCoords().first < neighbor.first)
                        {
                            // node is to the south
                            if (!maze.nodes[currentNode.getCoords().first][currentNode.getCoords().second].hasWall(WALL_SOUTH))
                            {
                                visited[neighbor.first][neighbor.second] = true;
                                mazeNodes.push(maze.nodes[neighbor.first][neighbor.second]);
                            }
                        }
                        else
                        {
                            // node is to the north
                            if (!maze.nodes[currentNode.getCoords().first][currentNode.getCoords().second].hasWall(WALL_NORTH))
                            {
                                visited[neighbor.first][neighbor.second] = true;
                                mazeNodes.push(maze.nodes[neighbor.first][neighbor.second]);
                            }
                        }
                    }
                }
            }
        }
    }

    // printExploration();
    return false;
}

#include <sstream>
#include <iostream>

// Assuming BreadthFirstSearch class and other necessary parts are defined elsewhere

void BreadthFirstSearch::printExploration(int currCol, int currRow) const
{
    int rows = maze.nodes.size();
    int cols = maze.nodes[0].size();
    std::stringstream output;
    // Print top border
    for (int col = 0; col < cols; ++col)
    {
        output << " _";
    }
    output << std::endl;

    for (int row = 0; row < rows; ++row)
    {
        // Print left border of each row
        output << "|";
        for (int col = 0; col < cols; ++col)
        {
            // Print bottom border
            if (maze.nodes[row][col].hasWall(WALL_SOUTH))
            {
                if (visited[row][col])
                {
                    output << "\033[4m*\033[0m";
                }
                else
                {
                    output << "_";
                }
            }
            else
            {
                if (visited[row][col])
                {
                    output << "*";
                }
                else
                {
                    output << " ";
                }
            }

            // Print right border
            if (maze.nodes[row][col].hasWall(WALL_EAST))
            {
                output << "|";
            }
            else
            {
                output << " ";
            }
        }
        output << std::endl;
    }
    // Print the entire output in one go
    std::cout << output.str();
}

// void BreadthFirstSearch::printExploration(int currCol, int currRow) const
// {
//     int rows = maze.nodes.size();
//     int cols = maze.nodes[0].size();

//     // Print top border
//     for (int col = 0; col < cols; ++col)
//     {
//         std::cout << " _";
//     }
//     std::cout << std::endl;

//     for (int row = 0; row < rows; ++row)
//     {
//         // Print left border of each row
//         std::cout << "|";
//         for (int col = 0; col < cols; ++col)
//         {
//             // Print bottom border
//             if (maze.nodes[row][col].hasWall(WALL_SOUTH))
//             {
//                 if (visited[row][col])
//                 {
//                     std::cout << "\033[4m*\033[0m";
//                 }
//                 else
//                 {
//                     std::cout << "_";
//                 }
//             }
//             else
//             {
//                 if (visited[row][col])
//                 {
//                     std::cout << "*";
//                 }
//                 else
//                 {
//                     std::cout << " ";
//                 }
//             }

//             // Print right border
//             if (maze.nodes[row][col].hasWall(WALL_EAST))
//             {
//                 std::cout << "|";
//             }
//             else
//             {
//                 std::cout << " ";
//             }
//         }
//         std::cout << std::endl;
//     }
// }