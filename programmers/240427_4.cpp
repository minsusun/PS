#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void search(vector<int> &msg, vector<vector<int>> &maze, vector<vector<bool>> &visit,
            int row, int col, int n, int side, bool dir)
{
    if (n == msg.size()) {
        visit[row][col] = true;
        return;
    }

    if (dir) {
        // on top
        if (side == 0) {
            if (col == 0)
                return;
            if (maze[row][col - 1] == msg[n])
                search(msg, maze, visit, row, col, n + 1, 3, dir);
            else if (maze[row][col - 1] != 2)
                return;
            else if (maze[row - 1][col - 1] == msg[n])
                search(msg, maze, visit, row, col - 1, n + 1, 0, dir);
            else if (maze[row - 1][col - 1] == 2 && maze[row - 1][col] == msg[n])
                search(msg, maze, visit, row - 1, col - 1, n + 1, 1, dir);
        }
        // on right
        else if (side == 1) {
            if (row == 0)
                return;
            if (maze[row - 1][col] == msg[n])
                search(msg, maze, visit, row, col, n + 1, 0, dir);
            else if (maze[row - 1][col] != 2)
                return;
            else if (maze[row - 1][col + 1] == msg[n])
                search(msg, maze, visit, row - 1, col, n + 1, 1, dir);
            else if (maze[row - 1][col + 1] == 2 && maze[row][col + 1] == msg[n])
                search(msg, maze, visit, row - 1, col + 1, n + 1, 2, dir);
        }
        // on bottom
        else if (side == 2) {
            if (col == maze[0].size() - 1)
                return;
            if (maze[row][col + 1] == msg[n])
                search(msg, maze, visit, row, col, n + 1, 1, dir);
            else if (maze[row][col + 1] != 2)
                return;
            else if (maze[row + 1][col + 1] == msg[n])
                search(msg, maze, visit, row, col + 1, n + 1, 2, dir);
            else if (maze[row + 1][col + 1] == 2 && maze[row + 1][col] == msg[n])
                search(msg, maze, visit, row + 1, col + 1, n + 1, 3, dir);
        }
        // on left
        else if (side == 3) {
            if (row == maze.size() - 1)
                return;
            if (maze[row + 1][col] == msg[n])
                search(msg, maze, visit, row, col, n + 1, 2, dir);
            else if (maze[row + 1][col] != 2)
                return;
            else if (maze[row + 1][col - 1] == msg[n])
                search(msg, maze, visit, row + 1, col, n + 1, 3, dir);
            else if (maze[row + 1][col - 1] == 2 && maze[row][col - 1] == msg[n])
                search(msg, maze, visit, row + 1, col - 1, n + 1, 0, dir);
        }
    }
    else
    {
        // on top
        if (side == 0) {
            if (col == maze[0].size() - 1)
                return;
            if (maze[row][col + 1] == msg[n])
                search(msg, maze, visit, row, col, n + 1, 1,
                       dir);
            else if (maze[row][col + 1] != 2)
                return;
            else if (maze[row - 1][col + 1] == msg[n])
                search(msg, maze, visit, row, col + 1,
                       n + 1, 0, dir);
            else if (maze[row - 1][col + 1] == 2 && maze[row - 1][col] == msg[n])
                search(msg,
                       maze, visit, row - 1, col + 1, n + 1, 3, dir);
        }
        // on right
        else if (side == 1) {
            if (row == maze.size() - 1)
                return;
            if (maze[row + 1][col] == msg[n])
                search(msg, maze, visit, row, col, n + 1, 2,
                       dir);
            else if (maze[row + 1][col] != 2)
                return;
            else if (maze[row + 1][col + 1] == msg[n])
                search(msg, maze, visit, row + 1,
                       col, n + 1, 1, dir);
            else if (maze[row + 1][col + 1] == 2 && maze[row][col + 1] == msg[n])
                search(msg, maze, visit, row + 1, col + 1, n + 1, 0, dir);
        }
        // on bottom
        else if (side == 2) {
            if (col == 0)
                return;
            if (maze[row][col - 1] == msg[n])
                search(msg, maze, visit, row, col, n + 1, 3, dir);
            else if (maze[row][col - 1] != 2)
                return;
            else if (maze[row + 1][col - 1] == msg[n])
                search(msg, maze, visit, row, col - 1, n + 1, 2, dir);
            else if (maze[row + 1][col - 1] == 2 && maze[row + 1][col] == msg[n])
                search(msg, maze, visit, row + 1, col - 1, n + 1, 1, dir);
        }
        // on left
        else if (side == 3) {
            if (row == 0)
                return;
            if (maze[row - 1][col] == msg[n])
                search(msg, maze, visit, row, col, n + 1, 0, dir);
            else if (maze[row - 1][col] != 2)
                return;
            else if (maze[row - 1][col - 1] == msg[n])
                search(msg, maze, visit, row - 1, col, n + 1, 3, dir);
            else if (maze[row - 1][col - 1] == 2 && maze[row][col - 1] == msg[n])
                search(msg, maze, visit, row - 1, col - 1, n + 1, 2, dir);
        }
    }
}
vector<vector<int>> solution(vector<int> msg, vector<vector<int>> maze) {
    int row = maze.size();
    int col = maze[0].size();
    vector<vector<int>> answer;
    vector<vector<bool>> visit(1001, vector<bool>(1001, false));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (maze[i][j] == 2) {
                if (i + 1 < row && maze[i + 1][j] == msg[0]) {
                    search(msg, maze, visit, i, j, 1, 2, true);
                    search(msg, maze, visit, i, j, 1, 2, false);
                }
                if (i - 1 >= 0 && maze[i - 1][j] == msg[0]) {
                    search(msg, maze, visit, i, j, 1, 0, true);
                    search(msg, maze, visit, i, j, 1, 0, false);
                }
                if (j + 1 < col && maze[i][j + 1] == msg[0]) {
                    search(msg, maze, visit, i, j, 1, 1, true);
                    search(msg, maze, visit, i, j, 1, 1, false);
                }
                if (j - 1 >= 0 && maze[i][j - 1] == msg[0]) {
                    search(msg, maze, visit, i, j, 1, 3, true);
                    search(msg, maze, visit, i, j, 1, 3, false);
                }
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (visit[i][j]) {
                vector<int> v = {i, j};
                answer.push_back(v);
            }
        }
    }
    return answer;
}