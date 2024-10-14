#include<bits/stdc++.h>
int maxE(vector<int> &arr){
	int maxi=INT_MIN;
	for(int i=0;i<arr.size();i++){
		maxi=max(maxi,arr[i]);
	}
	return maxi;
}

int possibleValue(vector<int> &arr,int val){
	int sum=0;
	for(int i=0;i<arr.size();i++){
		sum+=ceil((double)(arr[i])/(double)(val));
	}
	return sum;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	int low=1;
	int high=maxE(arr);
	if(arr.size()>limit)	return -1;

	while(low<=high){
		int mid=low+(high-low)/2;

		if(possibleValue(arr,mid)<=limit){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return low;

}
int main(){
    
}