// dry run is necessary for both brute and optimal solution

// brute force approach using recursion
// tc: o(2^n) and sc: o(n)

// better approach using memorization
// tc: o(n*target) and sc: O(n*target)

// optimal solution using tabulation
class optimal solution
{
#include <bits/stdc++.h>
    bool subsetSumToK(int n, int k, vector<int> &arr)
    {
        // dp[index][target]

        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // filling all target value as true[1]
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        /*
        we are taking this value , when we start with array it must be a part of the dp to satisfy the 
        value of other dp values[i.e it is a part of subset hence must be true]

        for eg. first element value of array is 3 i.e dp[0][3]
        and our target is 7 and we get 4 value at any index(suppose at 1 [for easy example])  i.e arr={3,4,....}
        so dp[ind - 1][target - 4]=dp[0][7-4]=dp[0][3]
        and we know that at index 0 value 3 exist but we don't consider as part of dp[which can contribute for the result obtain] as we give him false value
        then even we know that result is true[subset value can be 7], but  dp[0][3] will give false even result actually it is true

        it is also important if our first index value is equal to result
        */
        if (arr[0] <= k)
        {
            dp[0][arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++)
        { // we start with 1 because for 0 we have already consider in if statement
            for (int target = 1; target <= k; target++)
            { // we start with 1 beacause value of 0 already consider in for loop
                bool notTaken = dp[ind - 1][target];
                bool taken = false;
                if (arr[ind] <= target)
                {
                    taken = dp[ind - 1][target - arr[ind]];
                }

                dp[ind][target] = taken || notTaken;
            }
        }

        return dp[n - 1][k];
    }
};

//todo: with space optimization[homework] //dry run is necessary
