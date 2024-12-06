// brute force approach using recursion:  

// better approach using memorization:  

// optimal approach using tabulation
#include <bits/stdc++.h>
string findLCS(int n, int m, string &s1, string &s2)
{

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base case string s2 is empty
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    // base casem string s1 is empty
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int ind = 1; ind <= n; ind++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {

            if (s1[ind - 1] == s2[ind2 - 1])
            {
                dp[ind][ind2] = 1 + dp[ind - 1][ind2 - 1];
            }
            else
            {
                dp[ind][ind2] = max(dp[ind - 1][ind2], dp[ind][ind2 - 1]);
            }
        }
    }

    int length = dp[n][m];

    string str = "";
    for (int i = 0; i < length; i++)
    {
        str += "$"; // dummy string of maximum common subsequence
    }

    int l = n;
    int r = m;
    while (l > 0 && r > 0)
    {
        if (s1[l - 1] == s2[r - 1])
        { // the value(char) at that index are same
            str[--length] = s1[l - 1];
            l--;
            r--;
        }
        else if (dp[l - 1][r] > dp[l][r - 1])
        {
            l--;
        }
        else
        {
            r--;
        }
    }
    return str;
}