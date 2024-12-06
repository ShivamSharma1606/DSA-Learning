// brute force approach using RECURSION
//  Algorithm : file:///D:/ALL%20_LEANING/ONE%20NOTE%20IMAGE%20SOURCE/Untitled%20picture.png
//  tc: 2^(m*n) and sc: o(m-1+n-1)[recursion space]

// better approach using memorization
//  algo: oneNote
// tc: O(n*m) and sc: o(m-1+n-1) + o(n*m) [dp array/

// optimal approach using tabulation
// tc: o(m*n) and sc: o(m*n)

class SolutionTabular
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        //

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if (i > 0)
                    up = dp[i - 1][j]; // if we are on the first row [horizontally [1,1,1,.....1]]
                if (j > 0)
                    left = dp[i][j - 1]; // if we are on the first column [vertically [1,1,1,...1]]

                dp[i][j] = up + left;
            }
        }

        return dp[m - 1][n - 1];
    }
};

// optimal approach using tabulation with space optimazation
// homework
