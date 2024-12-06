// brute [same as dp8]
// better [same as dp8]

// optimal [same as dp8]

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int up = 0;
                int left = 0;

                if (i > 0)
                    up = grid[i][j] + dp[i - 1][j];
                else
                    up = INT_MAX; // we come to that index that does't exist
                                  // hence we don't want to compare
                if (j > 0)
                    left = grid[i][j] + dp[i][j - 1];
                else
                    left = INT_MAX; // we come to that index that does't exist
                                    // hence we don't want to compare

                dp[i][j] = min(left, up);
            }
        }

        return dp[m - 1][n - 1]; 
    }
};

// optimal with space optimization[same as dp8] //revision work
