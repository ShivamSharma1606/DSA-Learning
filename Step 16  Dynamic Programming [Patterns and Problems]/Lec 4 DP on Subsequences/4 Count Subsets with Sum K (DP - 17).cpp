//todo [status done]
int mod = (int)(1e9 + 7);
int findWays(vector<int> &arr, int k)

{

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // we use this because if first element is zero than it can create duplicate with same value
    //  i.e for eg arr = { 0 ,1,2,3} target is 4 so one subarray will be {0,1,3} and other is {1,3}
    if (arr[0] == 0)
        dp[0][0] = 2;

    else

        dp[0][0] = 1;

    if (arr[0] <= k && arr[0] != 0)
    {

        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {

        for (int target = 0; target <= k; target++)
        {

            // not take

            int nottake = dp[i - 1][target];

            int take = 0;

            if (arr[i] <= target)
            {

                take = dp[i - 1][target - arr[i]];
            }

            dp[i][target] = (take + nottake) % mod;
        }
    }

    return dp[n - 1][k];
}