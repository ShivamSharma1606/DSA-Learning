class Solution
{
public:
    // Checks if given cell coordinates are valid and unvisited
    bool isValid(vector<vector<bool>> &visited, int row, int col)
    {
        return row >= 0 && col >= 0 && row < visited.size() &&
               col < visited[0].size() && !visited[row][col];
    }

    int minimumTime(vector<vector<int>> &grid)
    {
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int time = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (r == rows - 1 && c == cols - 1)
            {
                return time;
            }

            if (visited[r][c])
            {
                continue;
            }

            visited[r][c] = true;

            for (auto d : directions)
            {
                int nextrow = r + d[0];
                int nextcol = c + d[1];

                if (!isValid(visited, nextrow, nextcol))
                {
                    continue;
                }

                // why this line
                int waitTime = ((grid[nextrow][nextcol] - time) % 2 == 0) ? 1 : 0;
                int nextTime = max(grid[nextrow][nextcol] + waitTime, time + 1);

                pq.push({nextTime, nextrow, nextcol});
            }
        }
        return -1;
    }
};