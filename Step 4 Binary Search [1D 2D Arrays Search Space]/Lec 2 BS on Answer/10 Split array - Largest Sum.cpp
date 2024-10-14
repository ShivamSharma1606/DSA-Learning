//same code of book allocation
#include<bits/stdc++.h>
int painterCnt(vector<int>&arr, int time){
    int painter=1;
    long long count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]+count<=time){
            count+=arr[i];
        }else{
            painter++;
            count=arr[i];
        }
    }
    return painter;
}

int largestSubarraySumMinimized(vector<int>& arr, int m) {
   
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);

    while(low<=high){
        int mid=low+(high-low)/2;

        int val =painterCnt(arr,mid);

        
        if( val>m){
            low=mid+1;//remove the left page
        }
        else{
            high=mid-1;//we remove the right part 
        }
    }
    return low;
}


int main(){

}