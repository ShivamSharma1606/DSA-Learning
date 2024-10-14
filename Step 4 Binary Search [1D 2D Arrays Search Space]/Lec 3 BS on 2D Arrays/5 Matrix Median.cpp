//brute force approach , first add all the element in the 1D array(using add in built function ), then sort the array , and then pick the middle element of 
// that sorted array

//optimal approach


#include<bits/stdc++.h>
int upperBound(vector<int> &arr, int x, int n){
	int ans=n;
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]>x){
			ans=mid;
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	return ans;	
}
int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x){
    int cnt=0;
    for(int i=0;i<m;i++){
        cnt+=upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low=INT_MAX;
    int high=INT_MIN;
    
    

    low=matrix[0][0];
    high=matrix[m-1][n-1];  

    /*
    striver use this to find low and high
    for(int i=0;i<m;i++){
        low=min(low,matrix[i][0]);
        high=max(high,matrix[i][n-1]);
    }
    */

    int req=(n*m)/2;
    while(low<=high){
        int mid=(low+high)/2;
        int smallEqual=countSmallEqual(matrix, m, n, mid);
        if(smallEqual<=req) low=mid+1;
        else    high=mid-1;
    }
    return low;
}