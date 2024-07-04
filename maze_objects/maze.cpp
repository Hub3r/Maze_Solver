#include "inc/maze.h"

Maze::Maze(int columns, int rows, const std::string &algorithm) : nodes(rows, std::vector<MazeNode>(columns)), generationAlgorithm(algorithm), rows(rows), cols(columns)
{
    generateMaze();
}

void Maze::generateMaze()
{
    if (generationAlgorithm == "RecursiveBacktracking")
    {
        generateMazeRecursiveBacktracking();
    }
    else if (generationAlgorithm == "StackBacktracking")
    {
        generateMazeStackBacktracking();
    }
}

void Maze::setWall(int row, int col, int wall)
{
    nodes[row][col].setWall(wall);
}

void Maze::clearWall(int row, int col, int wall)
{
    nodes[row][col].removeWall(wall);
}

bool Maze::hasWall(int row, int col, int wall) const
{
    return nodes[row][col].hasWall(wall);
}

std::vector<std::pair<int, int>> Maze::getUnvisitedNeighbors(int row, int col)
{
    std::vector<std::pair<int, int>> neighbors;
    // North
    if (row > 0 && !nodes[row - 1][col].isVisited())
    {
        neighbors.push_back({row - 1, col});
    }
    // South
    if (row < nodes.size() - 1 && !nodes[row + 1][col].isVisited())
    {
        neighbors.push_back({row + 1, col});
    }
    // East
    if (col < nodes[0].size() - 1 && !nodes[row][col + 1].isVisited())
    {
        neighbors.push_back({row, col + 1});
    }
    // West
    if (col > 0 && !nodes[row][col - 1].isVisited())
    {
        neighbors.push_back({row, col - 1});
    }
    return neighbors;
}

void Maze::generateMazeRecursiveBacktracking()
{
    int startRow = (rand() % (rows - 1)) + 1;
    int startCol = (rand() % (cols - 1)) + 1;
    visitNodeRecursiveBacktracking(startRow, startCol);
    unVisitNodes(0, 0);
}

void Maze::generateMazeStackBacktracking()
{
    visitNodeStackBacktracking(0, 0);
    unVisitNodes(0, 0);
}

void Maze::visitNodeStackBacktracking(int row, int col)
{
    std::stack<MazeNode> nodeList;
    nodes[row][col].markVisited();
    nodeList.push(nodes[row][col]);
    std::random_device rd;
    std::mt19937 g(rd());
    while (!nodeList.empty())
    {
        MazeNode current = nodeList.top();
        nodeList.pop();
    }
}

void Maze::visitNodeRecursiveBacktracking(int row, int col)
{
    nodes[row][col].markVisited();
    nodes[row][col].setCoords(row, col);
    auto neighbors = getUnvisitedNeighbors(row, col);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(neighbors.begin(), neighbors.end(), g);

    for (auto &neighbor : neighbors)
    {
        int nextRow = neighbor.first;
        int nextCol = neighbor.second;

        if (!nodes[nextRow][nextCol].isVisited())
        {
            if (nextRow == row - 1)
            { // North
                nodes[row][col].removeWall(WALL_NORTH);
                nodes[nextRow][nextCol].removeWall(WALL_SOUTH);
            }
            else if (nextRow == row + 1)
            { // South
                nodes[row][col].removeWall(WALL_SOUTH);
                nodes[nextRow][nextCol].removeWall(WALL_NORTH);
            }
            else if (nextCol == col + 1)
            { // East
                nodes[row][col].removeWall(WALL_EAST);
                nodes[nextRow][nextCol].removeWall(WALL_WEST);
            }
            else if (nextCol == col - 1)
            { // West
                nodes[row][col].removeWall(WALL_WEST);
                nodes[nextRow][nextCol].removeWall(WALL_EAST);
            }
            printMaze();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            std::cout << "\033[2J\033[H";
            visitNodeRecursiveBacktracking(nextRow, nextCol);
        }
    }
}

void Maze::unVisitNodes(int row, int col)
{
    for (int currentRow = 0; currentRow < nodes.size(); currentRow++)
    {
        for (int currentCol = 0; currentCol < nodes[0].size(); currentCol++)
        {
            nodes[currentRow][currentCol].markUnVisited();
        }
    }
}

void Maze::printMaze() const
{
    int rows = nodes.size();
    int cols = nodes[0].size();
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
            if (nodes[row][col].hasWall(WALL_SOUTH))
            {
                output << "_";
            }
            else
            {
                output << " ";
            }

            // Print right border
            if (nodes[row][col].hasWall(WALL_EAST))
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

// void Maze::printMaze() const
// {
//     int rows = nodes.size();
//     int cols = nodes[0].size();
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
//             if (nodes[row][col].hasWall(WALL_SOUTH))
//             {
//                 std::cout << "_";
//             }
//             else
//             {
//                 std::cout << " ";
//             }
//             // Print right border
//             if (nodes[row][col].hasWall(WALL_EAST))
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