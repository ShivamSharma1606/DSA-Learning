//! tc: o(n*k) and sc :o(2n)
class memoSolution
{
    int fun(int ind, vector<int> height, int k, vector<int> &dp)
    {

        if (ind >= height.size() - 1)
        {
            return 0;
        }

        if (dp[ind] != -1)
            return dp[ind];

        int value = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (ind + i < height.size())
            {

                int cost = fun(ind + i, height, k, dp) + abs(height[i + ind] - height[ind]);
                value = min(cost, value);
            }
        }

        return dp[ind] = value;
    }
    int minimizeCost(int n, int k, vector<int> &height)
    {
        vector<int> dp(n, -1);
        return fun(0, height, k, dp);
    }
};


//! tc: o(n*k) and sc :o(n)
class TabulationSolution
{
    int minimizeCost(int k, vector<int> &arr)
    {

        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int ind = 1; ind < n; ind++)
        {
            int value = INT_MAX;
            for (int i = 1; i <= k; i++)
            {
                if (ind - i >= 0)
                {
                    int cost = dp[ind - i] + abs(arr[ind - i] - arr[ind]);
                    value = min(value, cost);
                }
            }
            dp[ind] = value;
        }

        return dp[n - 1];
    }
};
