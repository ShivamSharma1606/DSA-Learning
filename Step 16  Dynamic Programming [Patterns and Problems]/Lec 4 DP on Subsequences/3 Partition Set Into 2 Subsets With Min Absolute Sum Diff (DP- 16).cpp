// todo: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
//their is also one more better approach please see it[codestudio solution]

int TabulationSolution(vector<int> &nums, int n)
{
    int k = 0; // total sum of the array

    for (int i = 0; i < n; i++)
    {
        k += nums[i];
    }
    // creating the 2-d vector
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // mark true for target equal to 0
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    // always true for 0 index
    if (nums[0] <= k)
    {
        dp[0][nums[0]] = true;
    }

    // finding the subseqence
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notselect = dp[i - 1][target];
            bool select = false;
            if (target >= nums[i])
            {
                select = dp[i - 1][target - nums[i]];
            }

            dp[i][target] = select || notselect;
        }
    }

    // finding the minimum result
    int result = 1e9;
    for (int i = 0; i < k; i++)
    {
        if (dp[n - 1][i] == true)
        {

            result = min(result, abs(i - (k - i)));
        }
    }

    return result;
}


//with memory optimization

int minSubsetSumDifference(vector<int>& nums, int n)
{
	int k = 0; //total sum of the array
        
	for(int i = 0; i < n; i++){
		k += nums[i];
	}
	//creating the 2-d vector
	vector<bool> dp(k+1,false);
	

	//mark true for target equal to 0
	dp[0] = true;
	
	//always true for 0 index
	if(nums[0] <= k){
		dp[nums[0]] = true;
	}

	//finding the subseqence
	for(int i = 1; i < n; i++){
		vector<bool> curr(k+1,false);
		//main change target start from zero
		for(int target = 0; target <= k; target++){
			bool notselect = dp[target];
			bool select = false;
			if(target >= nums[i]){
				select = dp[target - nums[i]];
			}

			curr[target] = select || notselect;
		}
		dp = curr;
	}

	//finding the minimum result
	int result = 1e9;
	for(int i = 0; i <= k; i++){
		if(dp[i]){
			result = min(result, abs(i - (k - i)));
		}
	}

	return result;
}


