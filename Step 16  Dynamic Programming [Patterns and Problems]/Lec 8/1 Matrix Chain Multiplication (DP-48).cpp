#include <bits/stdc++.h>

int fun(int i,int j, vector<int> &arr, vector<vector<int>> &dp ){
    //that is only one self matrix is left hence no operation can't be performed on single matrix
    if(i==j){
        return 0;
    }

    if(dp[i][j]!= -1)   return dp[i][j];

    int mini=INT_MAX;
    for(int k=i;k<j;k++){

        int operations= arr[i-1]*arr[k]*arr[j] + fun(i,k,arr,dp) +fun(k+1,j,arr,dp);
        mini=min(mini,operations);
    }

    return dp[i][j]=mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    //
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return fun(1,N-1,arr,dp);
}