#include <bits/stdc++.h>
int count(vector<int>& arr, int n, int target) {
	int lb=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    int ub=upper_bound(arr.begin(),arr.end(),target)-arr.begin();
	int len=ub-lb;

    if(lb==n||arr[lb]!=target)   return 0;
    return len;
}

int main(){
    
}