// brute force approach using recursion:    tc: exponentially[can't be accurate find] and sc: o(Target)

//better approach using memeorization:  tc(n*t) and sc: o(n*t)+o(target)

//optimal solution using tabulation

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int amt = 0; amt <= amount; amt++) {
                long long nottaken = dp[i - 1][amt];

                long long taken = 0;
                if (coins[i] <= amt) {
                    taken = dp[i][amt - coins[i]]; // the main change in the
                                                   // line as compared to memo
                }

                dp[i][amt] = nottaken + taken;
            }
        }

        return dp[n - 1][amount];
    }
};
//todo :optimal solution using tabulation with space optimization
//using curr and prev

