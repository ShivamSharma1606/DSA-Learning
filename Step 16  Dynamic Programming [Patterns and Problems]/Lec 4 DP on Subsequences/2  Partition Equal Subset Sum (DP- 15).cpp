//todo: done[self]
//optimal approach
class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int k = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            k += arr[i];
        }

        if (k % 2 != 0)
            return false; // odd number can't be divide equally between two
                          // integers
        k = k / 2;

        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (arr[0] <= k) {
            dp[0][arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTaken = dp[ind - 1][target];
                bool taken = false;
                if (arr[ind] <= target) {
                    taken = dp[ind - 1][target - arr[ind]];
                }

                dp[ind][target] = taken || notTaken;
            }
        }

        return dp[n - 1][k];
    }
};

//optimal with space optimization [do at revision]