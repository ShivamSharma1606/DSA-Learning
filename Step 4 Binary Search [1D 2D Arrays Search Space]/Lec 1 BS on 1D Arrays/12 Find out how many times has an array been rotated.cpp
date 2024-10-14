#include <bits/stdc++.h>
int findKRotation(vector<int> &arr){
    int n=arr.size();
	int ans=INT_MAX;
	int low=0,high=n-1;
    int index=0;

	while(low<=high){
		int mid=(high+low)/2;
        //this code can be implement without this below if part , this part is only for optimization of the code if the array is already sorted then why we do comparisions
		if(arr[low]<arr[high]){
            if(ans>arr[low]){
                ans=arr[low];
                index=low;
            }
            break;
		}
		else if(arr[mid]>=arr[low]){
			if(ans>arr[low]){
                ans=arr[low];
                index=low;
            }
			low=mid+1;
		}
		else{
			if(ans>arr[mid]){
                ans=arr[mid];
                index=mid;
            }
			high=mid-1;
		}
	}
	return index;
}

int main(){

}