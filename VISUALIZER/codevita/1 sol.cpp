#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int findMinWater(vector<vector<char>>& grid, int n, pair<int, int> start, pair<int, int> end) {
    vector<vector<int>> water(n, vector<int>(n, numeric_limits<int>::max()));
    queue<pair<int, int>> q;

    water[start.first][start.second] = 0;
    q.push(start);

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 'M') {
                int cost = (grid[x][y] == 'T' && grid[nx][ny] == 'T') ? 0 : 1;
                if (water[x][y] + cost < water[nx][ny]) {
                    water[nx][ny] = water[x][y] + cost;
                    q.push({nx, ny});
                }
            }
        }
    }

    return water[end.first][end.second];
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    pair<int, int> start, end;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') start = {i, j};
            if (grid[i][j] == 'E') end = {i, j};
        }
    }

    int result = findMinWater(grid, n, start, end);
    cout << result << endl;

    return 0;
}
