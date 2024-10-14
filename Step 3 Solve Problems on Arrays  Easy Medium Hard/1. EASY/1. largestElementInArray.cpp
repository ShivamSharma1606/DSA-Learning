#include <bits/stdc++.h> 
using namespace std;

int largestElement(vector<int> &arr, int n) {
    // Write your code here.

    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}

int main(){
    vector<int> arr={2,5,6,6,1,0,9};

    int largest=largestElement(arr,7);
    cout<<largest;
}