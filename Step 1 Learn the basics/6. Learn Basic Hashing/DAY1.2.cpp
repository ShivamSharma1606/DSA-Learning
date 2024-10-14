//MAP HASHING 
#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //map
    //it also work with unordered_map
    //advantage of unordered map is that it take less time in average and worst 
    map<int,int> mpp;

    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    //homework try this with character i.e map<char,int> mpp

    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        //fetech
        cout<<mpp[number]<<endl;
    }

}