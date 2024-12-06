#include <bits/stdc++.h>
int fun(int index, vector<int> &nums, vector<int> &dp)
{
    if (index == 0)
    {
        return nums[0];
    }
    if (index < 0)
    {
        return 0;
    }

    if (dp[index] != -1)
        return dp[index];

    int select = nums[index] + fun(index - 2, nums, dp);
    int notselect = fun(index - 1, nums, dp);

    int value = max(select, notselect);
    dp[index] = value;
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return fun(n - 1, nums, dp);
}
F