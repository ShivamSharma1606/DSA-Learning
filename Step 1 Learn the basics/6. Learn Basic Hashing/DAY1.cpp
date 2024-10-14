//array hashing 
#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //hash array 
    //we take 14+1=15 in has array because we assume the biggest value in the array will be 14

    //array in main() can take upto 10^6 element and globally upto 10^7
    int hash[15]={0};

    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }

    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        //fetech
        cout<<hash[number]<<endl;
    }

}