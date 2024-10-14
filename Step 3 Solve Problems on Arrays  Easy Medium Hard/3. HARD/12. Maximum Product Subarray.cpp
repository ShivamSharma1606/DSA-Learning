//brute force approach using n3 
//better n2 using nested loop
//optimal approach or modified version of kadana's algo

#include <bits/stdc++.h>

int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
	int pre=1;
	int suff=1;
	int n=arr.size();
	int ans=INT_MIN;
	for(int i=0;i<n;i++){
		if(pre==0) pre=1;
		if(suff==0) suff=1;

		pre=arr[i]*pre;
		suff=arr[n-i-1]*suff;
		ans=max(ans,max(pre,suff));
	}
	return ans;
}