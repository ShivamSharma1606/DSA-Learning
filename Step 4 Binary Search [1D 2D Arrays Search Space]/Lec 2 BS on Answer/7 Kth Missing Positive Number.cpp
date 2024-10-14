//dry will explain more as you need at last where high and low go at last
#include<bits/stdc++.h>
int missingK(vector < int > vec, int n, int k) {
    int low=0,high=n-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        int missing=vec[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return k+high+1;
    //or we can try// return low+1;
}

int main(){
    
}
