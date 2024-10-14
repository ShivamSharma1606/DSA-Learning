#include<bits/stdc++.h>
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int target) {

	int low=0;
	int high=n-1;
	int ans1=-1,ans2=-1;

	//for finding the ceil i.e value greater than target or equal
	while(low<=high){
		int mid=low+(high-low)/2;

		if(arr[mid]>=target){
			ans1=arr[mid];
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	//for finding the floor i.e value lesser or equal to target
	low=0;
	high=n-1;
	while(low<=high){
		int mid=low+(high-low)/2;

		if(arr[mid]<=target){
			ans2=arr[mid];
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	return {ans2,ans1};
}

int main(){
    
}