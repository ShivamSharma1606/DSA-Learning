// todo:[status :done]

#include <bits/stdc++.h>
using namespace std;
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    for (int i = 0; i <= x; i++)
    {
        if (i % num[0] == 0)
            dp[0][i] = i / num[0];
        else
            dp[0][i] = 1e9; // Set it to a very large value if not possible
    }

    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= x; target++)
        {
            int notSelect = dp[i - 1][target];
            int select = 1e9;
            if (target >= num[i])
            {
                select = 1 + dp[i][target - num[i]];
            }

            dp[i][target] = min(select, notSelect);
        }
    }

    int ans = dp[n - 1][x];
    if (ans >= 1e9)
        return -1;

    return ans;
}

//todo : tabulation with space optimization