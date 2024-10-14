#include <bits/stdc++.h>
int maxElement(vector<int> &v){
    int maxi=INT_MIN;
    int n=v.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,v[i]);
    }
    return maxi;
}

int eatingTime(vector<int> &v, int time,int h){
    int n=v.size();
    int ans=0;
    for(int i=0;i<n;i++){
        ans += ceil((double)v[i]/(double)time);
        //to avoid overflow imp.otherwise some test case will not pass
        if(ans>h) break;
    }
    return ans;
}

int minimumRateToEatBananas(vector<int> v, int h) {

    int low=1;
    int high=maxElement(v);

    while(low<=high){
        int mid=low+(high-low)/2;

        int val =eatingTime(v,mid,h);
        if(val<=h){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}

int main(){

}