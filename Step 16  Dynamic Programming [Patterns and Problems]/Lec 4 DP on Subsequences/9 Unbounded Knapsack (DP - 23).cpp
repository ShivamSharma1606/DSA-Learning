// todo: [status done]

int unboundedKnapsack(int n, int k, vector<int> &profit, vector<int> &weight)
{

    // {index, target}
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = weight[0]; i <= k; i++)
    {
        dp[0][i] = (i / weight[0]) * profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= k; target++)
        {
            int notTaken = dp[i - 1][target];
            int taken = -1e9;
            if (target >= weight[i])
            {
                // value of i don't decrease as their are infinite no of each element
                taken = profit[i] + dp[i][target - weight[i]];
            }

            dp[i][target] = max(taken, notTaken);
        }
    }

    return dp[n - 1][k];
}