#include<bits/stdc++.h>
//lower bound is the first number which is equal or greater than given number
int lowerBound(vector<int> arr, int n, int x) {
    //ans =n because if thier is no element in the array then we consider it is the element after last element i.e element after the array
	int ans=n;
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]>=x){
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
// int lb=lower_bound(arr,arr+n,target)-arr;
//for vector
// int lb=lower_bound(arr.begin(),arr.end(),target)-arr.begin();

int main(){

}