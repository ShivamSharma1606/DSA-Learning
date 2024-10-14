#include<bits/stdc++.h>
int floorSqrt(int n)
{
    int low=1;
    int ans=0;
    int high=n; //do not try with n/2 because all test cases are not  passes

    while(low<=high){
        long long mid=(low+high)/2;
        long long val=mid*mid;

        if(val<=(long long)(n)){
            ans=(int)mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high;
}

int main(){

}