#include<bits/stdc++.h>

//tc : ac= log2 n
//tc : wc= n/2 this will occur only when duplicate element are too much hence only comparision statement will execute
bool searchInARotatedSortedArrayII(vector<int>&arr, int target) {
    int n=arr.size();
    int left=0;
    int right=n-1;
    int ans=-1;
    while(left<=right){
        int mid=left+(right-left)/2;

        if(arr[mid]==target) return true;
        //this statement help to shrink the array for duplicate(plus which is not target)
        if(arr[mid]==arr[left]&&arr[mid]==arr[right]){
            left++,right--;
            continue;
        }

        //hence part before mid is sorted 
        if(arr[left]<=arr[mid]){
            if(arr[left]<=target &&target<=arr[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        //hence part after mid is sorted 
        else{
            if(arr[mid]<=target &&target<=arr[right]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
    }
    return false;
}
