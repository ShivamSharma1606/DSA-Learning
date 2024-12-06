#include <bits/stdc++.h>

//https://www.naukri.com/code360/problems/mining-diamonds_4244494?source=youtube&campaign=striver_dp_videos
/*
For this question we have to traverse from the last element i.e
The intuition is to first find the last balloon, then the 
last, and so on. This is the sequence we need to follow to solve this problem.
*/

int fun(int i,int j, vector<int> &a,vector<vector<int>> &dp){

	//array does not exist if left index is greater than right index
	if(i>j){
		return 0;
	}

	if (dp[i][j] != -1) {
        return dp[i][j];
    }

	//treating them as the last ballon[diamond]

	int maxi=INT_MIN;
	for(int ind=i;ind<=j;ind++)
	{
		int cost=a[ind]*a[i-1]*a[j+1] + fun(i,ind-1,a,dp) + fun(ind+1,j,a,dp);
		maxi=max(maxi,cost);
	}
	
	return dp[i][j] = maxi;
}
int maxCoins(vector<int> &a) 
{
	int n=a.size();
	//inserting the element before and after the array
  	a.push_back(1);
  	a.insert(a.begin(), 1);
	  vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	return fun(1,n,a,dp);
}
