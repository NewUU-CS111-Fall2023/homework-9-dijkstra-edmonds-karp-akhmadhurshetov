/*
 * Author: Axmad Xurshetov
 * Date: 29.12.2923
 * Name: task 5
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

// Directions: up, down, left, right
int dRow[] = {-1, 1, 0, 0};
int dCol[] = {0, 0, -1, 1};

bool isValid(int row, int col, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) return false;
    if (maze[row][col] == 1 || visited[row][col]) return false;
    return true;
}

int bfs(vector<vector<int>>& maze, pair<int, int> start, pair<int, int> end) {
    queue<pair<pair<int, int>, int>> q; // Pair of (cell, distance)
    vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

    q.push({start, 0});
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<pair<int, int>, int> cell = q.front();
        q.pop();

        int row = cell.first.first;
        int col = cell.first.second;
        int dist = cell.second;

        if (row == end.first && col == end.second) {
            return dist;
        }

        for (int i = 0; i < 4; i++) {
            int adjRow = row + dRow[i];
            int adjCol = col + dCol[i];

            if (isValid(adjRow, adjCol, maze, visited)) {
                visited[adjRow][adjCol] = true;
                q.push({{adjRow, adjCol}, dist + 1});
            }
        }
    }

    return -1; // if the exit is unreachable
}

int main() {
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> end = {ROWS - 1, COLS - 1};
    int shortest_path = bfs(maze, start, end);

    if (shortest_path != -1) {
        cout << "The shortest path from entrance to exit is: " << shortest_path << endl;
    } else {
        cout << "There is no path from entrance to exit." << endl;
    }

    return 0;
}
