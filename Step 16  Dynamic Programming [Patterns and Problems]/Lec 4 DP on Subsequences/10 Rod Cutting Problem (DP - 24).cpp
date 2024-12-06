// *brute force approach using recursion:    tc: exponentially[can't be accurate find] and sc: o(Target)

// *better approach using memeorization:  tc(n*n) and sc: o(n*n)+o(target)

class Memorization {
    //this is code if we have to find the max sum from the array of cutting the rod
  public:
    int fun(int ind, int length, vector<int> &price, vector<vector<int>> &dp){
        
        if(ind == 0)    {
            return length * price[0];
        }
        // if(length == 0) return 0;
        
        if(dp[ind][length] != -1){
            return dp[ind][length];
        }
        
        int notTaken = fun(ind-1, length, price, dp);
        int curr_rodlength = ind + 1;
        int taken = 0;
        if(length >= curr_rodlength){
            taken = price[ind] + fun(ind, length - curr_rodlength, price, dp)   ;
        }
        
        return dp[ind][length] = max(taken, notTaken);
    }
    
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return fun(n-1, n, price,dp);
    }
};


// *optimal solution using tabulation
class TabulationSolution
{
    int cutRod(vector<int> &price, int n)
    {
        // remeber in most case for max min value we take 0 not -1[is used for present or not question type]
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[0][i] = price[0] * i;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= n; target++)
            {

                int nottaken = 0 + dp[ind - 1][target];

                int taken = INT_MIN;
                int rodlength = ind + 1;
                if (target >= rodlength)
                {
                    taken = price[ind] + dp[ind][target - rodlength];
                }

                dp[ind][target] = max(taken, nottaken);
            }
        }

        return dp[n - 1][n];
    }
};

//optimal solution using tabulation with space optimization

int cutRod(vector<int> &price, int n)
{
	// remeber in most case for max min value we take 0 not -1[is used for present or not question type]
		vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);

    	for(int i=0;i<=n;i++){
    		prev[i]=price[0]*i;
    	}
    
    	for(int ind=1;ind<n;ind++){
    		for(int target=0;target<=n;target++){
    			
    			int nottaken=0+prev[target];
    
    			int taken=INT_MIN;
    			int rodlength=ind+1;
    			if(target>=rodlength){
    				taken=price[ind]+ curr[target-rodlength];
    			}
    
    			curr[target]=max(taken,nottaken);
    		}
    		prev=curr;
    	}
    
    	return prev[n];

}
