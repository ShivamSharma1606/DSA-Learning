#include<bits/stdc++.h>

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<n;i++){
        if(i>0 && arr[i-1]==arr[i]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum>0)   k--;
            else if(sum<0)  j++;
            else{
                vector<int> temp;
                temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++,k--;
                while(j<k && arr[j-1]==arr[j])   j++;
                while(j<k && arr[k+1]==arr[k])   k--;
            }
        }
    }

    return ans;
}

int main(){
    
}