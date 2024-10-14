//brute force apprach using for loop three times or two time and count sum of each subarray of the array

//optimal approach using kandes's algorithm
#include<bits/stdc++.h>

long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum=0;
    long long maxi=INT_MIN;
    int start =-1;
    int end=-1;
    for(int i=0;i<n;i++){
        if(sum==0) start=i;
        sum+=arr[i];
        if (sum < 0) {
          sum = 0;
        }
        if(sum>maxi){
            maxi=sum;
            int arrayStart=start;//return the starting index of largest arrauy
            int arrayEnd=i;//return the end index of largest arrauy
        }
    }
    if(maxi>0) return maxi;
    else return 0;
    
}

int main(){

}