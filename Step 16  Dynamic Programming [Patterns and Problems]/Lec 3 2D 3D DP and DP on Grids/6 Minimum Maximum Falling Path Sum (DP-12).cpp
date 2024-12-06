// brute force approach [oneNote]
// tc: o(3^n) and sc: o(n)

// memorization solution for max
class memosolution
{
public:
    int memosol(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j)
    {
        if (j < 0 || j >= matrix[0].size())
            return -1e8; // out of bound condition

        if (i == 0)
        {
            return matrix[0][j]; // base case first row
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int u = matrix[i][j] + memosol(matrix, dp, i - 1, j);
        int dl = matrix[i][j] + memosol(matrix, dp, i - 1, j - 1);
        int dr = matrix[i][j] + memosol(matrix, dp, i - 1, j + 1);

        return dp[i][j] = max(u, max(dl, dr));
    }

    int getMaxPathSum(vector<vector<int>> &matrix)

    {
        //  Write your code here.

        if (matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size();    // number of rows
        int m = matrix[0].size(); // number of columns
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int maxi = -1e8;
        for (int i = 0; i < m; i++)
        {
            maxi = max(maxi, memosol(matrix, dp, n - 1, i));
        }

        return maxi;
    }
};

// tabulation solution for mini

class Solution {
public:
    // tabulation solution
    int minFallingPathSum(vector<vector<int>>& matrix) {

        if (matrix.empty() || matrix[0].empty())
            return 0;
        int n = matrix.size();    // number of rows
        int m = matrix[0].size(); // number of columns
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // base case
        for (int i = 0; i < m; i++) {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int u = matrix[i][j] + dp[i - 1][j];

                int dl = 1e8; // for out of bound case
                if (j - 1 >= 0)
                    dl = matrix[i][j] + dp[i - 1][j - 1];

                int dr = 1e8; // for out of bound case
                if (j + 1 < m)
                    dr = matrix[i][j] + dp[i - 1][j + 1];

                dp[i][j] = min(u, min(dl, dr));
            }
        }

        int mini = 1e8;
        for (int i = 0; i < m; i++) {
            mini = min(mini, dp[n - 1][i]);
        }

        return mini;
    }
};

// space optimize solution 