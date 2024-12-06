// brute force approach using recursion:  

// better approach using memorization:  

// optimal approach using tabulation
int lcs(string &text1, string &text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0; // string 2 is empty
    }

    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0; // string 1 is empty
    }
    int ans = 0;
    string str = "";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {

                dp[i][j] = 1 + dp[i - 1][j - 1];

                ans = max(ans, dp[i][j]);
            }
            // link is brokent therefore reset its value to zero
            else
            {

                dp[i][j] = 0;
            }
        }
    }
    cout << str;

    return ans;
}