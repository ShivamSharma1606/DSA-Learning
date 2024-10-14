#include <bits/stdc++.h>
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int target)
{
    int lb=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    int ub=upper_bound(arr.begin(),arr.end(),target)-arr.begin();

    if(lb==n||arr[lb]!=target)   return {-1,-1};
    return {lb,ub-1};
    
}
//homework do with binary search i.e without upper bound and lower bound use in either way

int main(){

}