#include<bits/stdc++.h>
//SAME CODE OF LOWER BOUND

int searchInsert(vector<int>& arr, int x)
{
	//same code of lower bound
	int n=arr.size();
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

int main(){

}