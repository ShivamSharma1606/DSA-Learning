class RecursiveSolution
{

    int ninja(int n, vector<vector<int>> &points, int last)
    {
        if (n == 0)
        {
            int maxi = 0;
            for (int i = 0; i < 3; i++)
            {
                if (last != i)
                {
                    maxi = max(maxi, points[n][i]);
                }
            }
            return maxi;
        }

        int maxi = 0;

        for (int j = 0; j < 3; j++)
        {
            if (last != j)
            {
                int earn = points[n][j] + ninja(n - 1, points, j);
                maxi = max(maxi, earn);
            }
        }
        return maxi;
    }
    int ninjaTraining(int n, vector<vector<int>> &points)
    {

        return ninja(n - 1, points, 3); // we initially last 3 because at first we can visit any node
    }
};

class MemorizationSolution
{

    int ninja(int n, vector<vector<int>> &points, int last, vector<vector<int>> &dp)
    {
        if (dp[n][last] != -1)
            return dp[n][last];

        if (n == 0)
        {
            int maxi = 0;
            for (int i = 0; i < 3; i++)
            {
                if (last != i)
                {
                    maxi = max(maxi, points[n][i]);
                }
            }
            return dp[n][last] = maxi;
        }

        int maxi = 0;

        for (int j = 0; j < 3; j++)
        {
            if (last != j)
            {
                int earn = points[n][j] + ninja(n - 1, points, j, dp);
                maxi = max(maxi, earn);
            }
        }
        return dp[n][last] = maxi;
    }
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        // Write your code here.
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return ninja(n - 1, points, 3, dp); // we initially last 3 because at first we can visit any node
    }
};

class TabularSolution
{
    int maximumPoints(vector<vector<int>> &arr, int n)
    {

        //{day, acitivity performed last}
        vector<vector<int>> dp(n, vector<int>(4, -1));

        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2])); // if we have not selected any activity

        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last <= 3; last++)
            {
                // dp[day][last]=0;
                for (int task = 0; task <= 2; task++)
                { // for finding the maximum task from which can't be selected
                    if (last != task)
                    {
                        int activity = arr[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], activity);
                    }
                }
            }
        }

        return dp[n - 1][3];
    }
};

// todo: homeWork[done]
class TabularWithOptimizespace
{
    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        vector<int> prev(4, 0);

        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < points.size(); day++)
        {
            vector<int> temp(4, 0);
            for (int last = 0; last <= 3; last++)
            {
                for (int task = 0; task <= 2; task++)
                {
                    if (task != last)
                    {
                        int pt = points[day][task] + prev[task];
                        temp[last] = max(temp[last], pt);
                    }
                }
            }
            prev = temp;
        }

        return prev[3];
    }
};
