// brute force approach , traverse each element
// better approach , perform binary search in each subarray (take tc: nlogm)

//optimal approach, tc: o(n+m)

#include <bits/stdc++.h> 
bool findInMatrix(int x, vector<vector<int>> &arr)
{
    int n=arr.size();
    int m=arr[0].size();
    int row=0, col=m-1;

    while(row<n && col>=0){
        if(arr[row][col]==x) return true;
        else if(arr[row][col]<x)    row++;
        else col--;
    }
    return false;
}

int main(){
    
}