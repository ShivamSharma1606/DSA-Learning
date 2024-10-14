#include<bits/stdc++.h>
//binary search
//tc: o(log2 n)
//binary search using iterative method 
int search(vector<int> &arr, int target) {
    int n=arr.size();
    int low=0,high=n-1;

    while(low<=high){
        int mid=(low+high)/2;
        // for large data use mid data type as long long or mid=low+(high-low)/2 by this mid do not overflow for INT_MAX2.
        if(arr[mid]==target) return mid;
        else if(target>arr[mid]) low=mid+1;
        else   high=mid-1;
    }
    return -1;
}

//homework do with recursive method