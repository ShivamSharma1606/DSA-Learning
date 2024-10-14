#include<bits/stdc++.h>
//tc nlogn
//sc : o(n)
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {

    unordered_map<int ,int> mpp;
    int count=0;
    int sum=0;
    mpp[0]=1;

    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        int remove=sum-k;
        count+=mpp[remove];
        mpp[sum]++;// or -> mpp[sum]+=1;
    }

    return count;   
}

int main(){

}