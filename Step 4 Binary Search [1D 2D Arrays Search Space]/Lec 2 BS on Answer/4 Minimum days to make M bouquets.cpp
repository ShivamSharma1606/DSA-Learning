#include <bits/stdc++.h>
int minValue(vector<int> &arr){
	int n=arr.size();
	int mini=INT_MAX;
	for(int i=0;i<n;i++){
		mini=min(mini,arr[i]);
	}
	return mini;
}
int maxValue(vector<int> &arr){
	int n=arr.size();
	int maxi=INT_MIN;
	for(int i=0;i<n;i++){
		maxi=max(maxi,arr[i]);
	}
	return maxi;
}

bool possible(vector<int> &arr, int day, int flower, int bqe){
	int count=0;
	int n=arr.size();
	int ansValid=0;
	for(int i=0;i<n;i++){
		if(arr[i]<=day){
			count++;
		}else{
			ansValid+=(count/flower);
			count=0;
		}
	}
	ansValid+=(count/flower);
	if(ansValid>=bqe)	return true;
	return false;
}


int roseGarden(vector<int> arr, int k, int m)
{
	int n=arr.size();
	if(n<k*m)	return -1;
	int low=minValue(arr);
	int high=maxValue(arr);
	//you can also find low and high using one loop in this function

	while(low<=high){
		int mid=low+(high-low)/2;

		if(possible(arr,mid,k,m)){
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	return low;
}

int main(){
    
}