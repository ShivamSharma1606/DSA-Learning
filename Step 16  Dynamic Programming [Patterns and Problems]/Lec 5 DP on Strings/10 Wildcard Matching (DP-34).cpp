
// brute force approach

// memorization approach

class memorize
{
#include <bits/stdc++.h>
//s[i]=="?" return f(i-1,j-1)   because ? can change the character of parent string and then both the character of string are same hece now we check the condition for shrink sub-string
    bool f(int i, int j, string pattern, string text, vector<vector<int>> &dp)
    {

        // when both are string have no length to compare
        if (i == 0 && j == 0)
        {
            return true;
        }
        // if string 1 has no character to compare with string 2
        if (i == 0 && j > 0)
        {
            return false;
        }

        // if string 2 has no character to compare with string 1
        // then both string are same only possible if all the left character of string 1 is *
        if (j == 0 && i > 0)
        {
            for (int ind = 0; ind < i; ind++)
            {
                if (pattern[ind] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
        {
            return dp[i][j] = f(i - 1, j - 1, pattern, text, dp);
        }
        if (pattern[i - 1] == '*')
        {
            bool starNull = f(i - 1, j, pattern, text, dp);   // we consider empty string for *
            bool startTaken = f(i, j - 1, pattern, text, dp); // try to compare with shrinking string 2
            return dp[i][j] = (starNull || startTaken);
        }

        // both char are different in both the string
        return dp[i][j] = false;
    }

    bool wildcardMatching(string pattern, string text)
    {
        int n = pattern.size();
        int m = text.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, pattern, text, dp);
    }
};

//optimal solution
class tabulation{
class Solution {
public:
    bool isMatch(string text, string pattern) {
        int n = pattern.size();
        int m = text.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // base case
        dp[0][0] = true;

        // base case
        for (int j = 1; j <= m; j++) {
            dp[0][j] = false;
        }

        // base case
        for (int i = 1; i <= n; i++) {
            int flag = true;
            for (int ind = 0; ind < i; ind++) {
                if (pattern[ind] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[i - 1] == '*') {
                    bool starNull = dp[i - 1][j];
                    bool startTaken = dp[i][j - 1];
                    dp[i][j] = (starNull || startTaken);
                }

                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
};

//optimal solution with space optimizaton [must watch]