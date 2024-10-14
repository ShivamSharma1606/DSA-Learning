#include<bits/stdc++.h>
//it only work for unique element in the array
//tc : log2 n
int search(vector<int>& arr, int n, int target)
{
    int left=0;
    int right=n-1;
    int ans=-1;
    while(left<=right){
        int mid=left+(right-left)/2;

        if(arr[mid]==target) return mid;

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
    return -1;
    
}
int main(){

}
