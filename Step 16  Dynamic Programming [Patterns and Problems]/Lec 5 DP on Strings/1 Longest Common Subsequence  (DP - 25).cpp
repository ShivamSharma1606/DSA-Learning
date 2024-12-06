// brute force approach using recursion:    tc: 2^n + 2^m and sc: o(n+m)

// better approach using memorization:   tc: o(n*m) and sc: o(n*m)+ o(n+m)

// optimal approach using tabulation

/*
for this approach we need to shift index by 1
i.e i=i+1
we do this because if our index<0   then we have to return 0 in memorization
but how we represent negative in tabulation for that we shift the position of element by 1
if we incounter negative while traversing then we have something[i.e 0] to return someone
*/

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        // dp[index of string 1][index of string 2]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0; // string 2 is empty
        }

        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0; // string 1 is empty
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j -1])
                { 
                  // we are not comparing [if(text1[i]==text2[j])]
                  // like that because we have already increase
                  // the indexing by 1
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                { // if both string char are not equal

                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n][m];
    }
};

// optimal solution with space optimization

#include <bits/stdc++.h>
int lcs(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    // dp[index of string 1][index of string 2]
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        prev[i] = 0; // string 2 is empty
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            { // if both string char are not equal

                curr[j] = max(curr[j - 1], prev[j]);
            }
        }
        prev = curr;
    }

    return prev[m];
}