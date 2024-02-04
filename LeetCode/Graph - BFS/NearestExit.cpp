/*

1926. Nearest Exit from Entrance in Maze
Medium

You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). 
You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the 
cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, 
and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. 
An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<pair<int, int>> move {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        int steps = 0;
        int row = maze.size();
        int column = maze[0].size();

        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = 'x';
        while (!q.empty())
        {
            int count = q.size();
            while (count--)
            {
                pair<int, int> current = q.front();
                q.pop();
                for (auto dir : move) // auto = pair
                {
                    int x = current.first + dir.first;
                    int y = current.second + dir.second;
                    if (x >= 0 && x < row && y >= 0 && y < column && maze[x][y] == '.')
                    {
                        maze[x][y] = 'x';
                        if (x == row - 1 || y == column - 1 || x == 0 || y == 0)
                            return (steps + 1);
                        else
                            q.push({x, y});
                    }
                }
            }
            steps++;
        }
        return (-1);
    }
};

int main()
{
    vector<vector<char>> maze {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<int> entrance = {1, 2};
    Solution solution;
    cout << solution.nearestExit(maze, entrance);
    return (0);
}