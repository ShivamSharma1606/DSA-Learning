#include<bits/stdc++.h>
bool possibleVal(vector<int> &arr, int capci, int dayR){
    int day=1;
    int load=0;
    for(int i=0;i<arr.size();i++){
        if(load+arr[i]>capci){
            day+=1;//move to the next day
            load=arr[i];
        }else{
            load+=arr[i];//adding weight to that same day
        }
    }
    if(day<=dayR) return true;
    return false;
}

int leastWeightCapacity(vector<int> &arr, int d)
{

    int low=*max_element(arr.begin(), arr.end());
    int high=accumulate(arr.begin(), arr.end(), 0);

    while(low<=high){
        int mid=low+(high-low)/2;

        if(possibleVal(arr,mid,d)){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;    
}

int main(){
    
}