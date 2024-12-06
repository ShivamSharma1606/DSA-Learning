//todo :[status done]

#include <bits/stdc++.h>
int targetSum(int n, int target, vector<int> &arr)
{

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }

    if (total - target < 0)
        return 0;
    if ((total - target) % 2 != 0)
        return 0;

    int zerocount = count(arr.begin(), arr.end(), 0);
    if (zerocount == n)
    {
        return pow(2, n);
    }

    int s2 = (total - target) / 2;
    vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));

    if (arr[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][0] = 1;
        if (s2 >= arr[0])
        {
            dp[0][arr[0]] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= s2; j++)
        {
            int notselect = dp[i - 1][j];
            int select = 0;
            if (j >= arr[i])
            {
                select = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = select + notselect;
        }
    }

    return dp[n - 1][s2];
}
