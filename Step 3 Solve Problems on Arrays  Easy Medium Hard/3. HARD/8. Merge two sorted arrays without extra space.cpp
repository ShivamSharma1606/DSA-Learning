//optimial approach 1 in notes


//optimal approach 2

#include <bits/stdc++.h>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n=a.size();
	int m=b.size();
	int len=(n+m);
	int gap=(len/2)+(len%2);
	// cout<<gap;

	while(gap>0){
		int left=0;
		int right=left+gap;
		while(right<len){
			// arr1& arr2
			if(left<n && right>=n){
				if(a[left]>b[right-n]){
					swap(a[left],b[right-n]);
				}
			}
			//arr2
			else if(left>=n){
				if(b[right-n]<b[left-n]){
					swap(b[left-n],b[right-n]);
				}				
			}
			//arr1
			else{
				if(a[right]<a[left]){
					swap(a[left],a[right]);
				}
			}
			left++;
			right++;		
		}
		if(gap==1)	break;
		gap=(gap/2)+(gap%2);
	}
}