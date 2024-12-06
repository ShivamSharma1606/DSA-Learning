#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // sc: 2*(n*m) and tc: (n*m) + 4*(n*m)
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // {{row,colum},time}
        queue<pair<pair<int, int>, int>> q;
        int IfreshOrange = 0; // Intially fresh Orange
        int FfreshOrange = 0; // Orange after execution
        int time = 0;         // intially time is zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Initally finding all rotten Oranges
                if (grid[i][j] == 2) {
                    q.push({{i, j}, time});
                    visited[i][j] = 2; // mark as visited
                }
                // finding the number of fresh oranges
                if (grid[i][j] == 1) {
                    IfreshOrange++;
                }
            }
        }

        //{up,left,down,right}
        int srow[4] = {-1, 0, 1, 0}; // surronding rows
        int scol[4] = {0, -1, 0, 1}; // surronding columns

        while (!q.empty()) {
            auto orange = q.front();
            q.pop();
            int r = orange.first.first;  // finding the row
            int c = orange.first.second; // finding the column
            int t = orange.second;       // finding the time

            time = max(time, t);
            // i<4 because their are only be four neighbour
            for (int i = 0; i < 4; i++) {
                int row = r + srow[i]; // row index of neighbour
                int col = c + scol[i]; // row index of neigbour
                if (row < n && col < m && row >= 0 && col >= 0 &&
                    visited[row][col] == 0 && grid[row][col] == 1) {
                    q.push({{row, col}, t + 1});
                    visited[row][col] = 2;
                    FfreshOrange++;
                }
            }
        }

        if (IfreshOrange != FfreshOrange)
            return -1;
        return time;
    }
};