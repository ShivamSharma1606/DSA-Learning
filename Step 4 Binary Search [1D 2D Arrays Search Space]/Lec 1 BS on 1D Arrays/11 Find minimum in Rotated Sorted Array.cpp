#include<bits/stdc++.h>

int findMin(vector<int>& arr)
{
	int n=arr.size();
	int ans=INT_MAX;
	int low=0,high=n-1;

	while(low<=high){
		int mid=(high+low)/2;

        //this code can be implement without this below if part , this part is only for optimization of the code if the array is already sorted then why we do comparisions
		if(arr[low]<arr[high]){
			ans=min(ans,arr[low]);
			break;
		}
		else if(arr[mid]>=arr[low]){
			ans=min(ans,arr[low]);
			//we get the minimum number from the left sorted array and below statement help to try to find the next minimum no(if possible) from unsorted array
			low=mid+1;
		}
		else{
			ans=min(ans,arr[mid]);
			high=mid-1;
		}
	}
	return ans;
}

int main(){

}