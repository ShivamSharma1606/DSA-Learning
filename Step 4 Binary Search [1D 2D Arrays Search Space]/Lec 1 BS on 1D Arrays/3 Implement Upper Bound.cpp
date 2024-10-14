#include<bits/stdc++.h>
//upper bound is first number which is greater than given number;
int upperBound(vector<int> &arr, int x, int n){
	int ans=n;
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]>x){// only change with lower boud is >= will become >
			ans=mid;
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	return ans;	
}

//shortcut method using c++ STL

//give index
//for array
// int lb=upper_bound(arr,arr+n,target)-arr;
//for vector
// int lb=upper_bound(arr.begin(),arr.end(),target)-arr.begin();

int main(){

}