//optimal approach
#include <bits/stdc++.h>
vector<int> superiorElements(vector<int>&arr) {

    int n=arr.size();
    int maxi=INT_MIN;
    vector<int> ans;
    
    for(int i=n-1;i>=0;i--){
        if(maxi<arr[i]){
            ans.push_back(arr[i]);
            maxi=max(maxi,arr[i]);
        }
    }

    return ans;
}