#include<bits/stdc++.h>

int getLongestZeroSumSubarrayLength(vector<int> &arr){
	unordered_map<int ,int> mpp; //because map take more TC
    int n=arr.size();
    int sum=0;
    int maxi=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0)  maxi=i+1;
        else{
            if(mpp.find(sum)!=mpp.end()){
                maxi=max(maxi,i-mpp[sum]);
            }else{
                mpp[sum]=i;
            }
        }
    }
    return maxi;
	
}

int main(){
    
}