// Greedy does not work for eg  [30 60 10 60 10 50]

class memorizationSolution
{
public:
    int fjdp(int n, vector<int> &heights, vector<int> &dp)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int left = fjdp(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
        int right = INT_MAX; // if our don't have right value then we give some value which is uncomparable
        if (n > 1)
            right = fjdp(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);

        return dp[n] = min(left, right);
    }

    int frogJump(int n, vector<int> &heights)
    {
        // Write your code here.
        vector<int> dp(n + 1, -1);

        return fjdp(n - 1, heights, dp);
    }
};

class TabularSolution
{
    int minimumEnergy(vector<int> &height, int n)
    {
        // Code here
        vector<int> dp(n, 0);
        dp[0] = 0;

        for (int i = 1; i < n; i++)
        {
            int fs = dp[i - 1] + abs(height[i] - height[i - 1]);
            int ss = INT_MAX;
            if (i > 1)
            {
                ss = dp[i - 2] + abs(height[i] - height[i - 2]);
            }

            dp[i] = min(fs, ss);
        }
        return dp[n - 1];
    }
};

class TabularSpaceOptimize
{

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {

        int jumpTwo = INT_MAX;
        int jumpOne = prev + abs(height[i] - height[i - 1]);
        if (i > 1)
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);

        int cur_i = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = cur_i;
    }
    cout << prev;
};