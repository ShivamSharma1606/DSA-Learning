#include<bits/stdc++.h>
bool canPossible(vector<int> &stalls,int dist, int cow){
    int cntCow=1,last=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-last>=dist){
            cntCow++;
            last=stalls[i];
        }
        if(cntCow>=cow) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int low=0;// why can also use low=1  find out why
    int high=stalls[n-1]-stalls[0];

    while(low<=high){
        int mid=low+(high-low)/2;

        if(canPossible(stalls,mid,k)){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high;
}

int main(){
    
}