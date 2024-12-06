//brute force approach using recursion[oneNote] :   tc: o(2^n)  and sc:o(n)

//better operation using memorization

class memoSolution {
public:
    int fun(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size())
            return 0;

        // if subsequence in increaesing order
        int length = 0;
        if (prev == -1 || nums[ind] > nums[prev]) {
            // previous element now become currenet element
            length = 1 + fun(ind + 1, ind, nums, dp);
        }
        // if not in increasing order

        // previous element remain the same
        int notchoselength = fun(ind + 1, prev, nums, dp);
        return max(length, notchoselength);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return fun(0, -1, nums, dp);
    }
};

//optimal solution USING TABULATION 
//must must dry run ***
//coordinate/indexing change by 1
/*
                        ****base case****
    we don't to write base Expectedly because it is already zero in dp

*/
class TabulationSolution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int pre = ind - 1; pre >= -1; pre--) {

                // the pre will remain the same pre+1 is due to indexing
                int nottaken = 0 + dp[ind + 1][pre + 1];

                int taken = 0;
                if (pre == -1 || nums[ind] > nums[pre]) {
                    // the pre will now be converted to ind
                    taken = 1 + dp[ind + 1][ind + 1];
                }

                dp[ind][pre + 1] = max(taken, nottaken);
            }
        }

        return dp[0][0];
    }
};

// optimal solution using tabulation with space optimization

//another approach but less efficient than tabulation solution
//but very useful for trace back the LIS

class notoptimalButUsefulForTracing{

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n,1);
    int maxi=1;

    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(arr[i]>arr[prev]){
                dp[i]=max(dp[i],1+dp[prev]);
            }
        }
        maxi=max(dp[i],maxi);
    }

    return maxi;
}
};


