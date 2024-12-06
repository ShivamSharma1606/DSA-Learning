// *greedy algo only work for fractional knapsack problem not for 0/1

// brute force approach using recursion  tc: 2^n and sc: n

// better approach using memeorization   tc: o(n*w)  and sc:o(n*w) + o(n)

// optimal approach using tabulation

// space optimization using tabulation  //dry run is necessary
// use concept of prev and curr

#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // dp[index][weight+1]
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0)); // we choose 0 not -1 because if their is no something then return weight would be zero

    // base case
    // if bag value is less than wt[0]  ,then  it can't be filled at 0 index
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int cap = 0; cap <= maxWeight; cap++)
        {

            int nottake = 0 + dp[i - 1][cap];
            int taken = INT_MIN;
            if (weight[i] <= cap)
            {
                taken = value[i] + dp[i - 1][cap - weight[i]];
            }

            dp[i][cap] = max(taken, nottake);
        }
    }

    return dp[n - 1][maxWeight];
}

// space optimization [pro max] using tabulation  // must must have dry run[please watch video again last 10 min]
// use only prev for this method
