//brute force approach 
//method 1: using for loop (ss in samNotes) 
//method 2: map data structure and counting the occurence

//optimal solution using xor
#include <bits/stdc++.h> 
int findOdd(int * arr,int n)
{
    int ans=0;
    for(int i=0;i<n;i++){
        ans^=arr[i];
    }
    return ans;
}

int main(){
    
}