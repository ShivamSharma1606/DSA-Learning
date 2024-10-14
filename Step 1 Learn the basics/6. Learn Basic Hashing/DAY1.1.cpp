//string hashing
#include<bits/stdc++.h>
using namespace std;
int main(){

    string str;
    cin>>str;

    //hash array 
    //we use 256 because in ASCII their are 256 character
    int hash[256]={0};

    for(int i=0;i<str.size();i++){
        hash[str[i]]++;
    }

    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        //fetech
        cout<<hash[c]<<endl;
    }

}