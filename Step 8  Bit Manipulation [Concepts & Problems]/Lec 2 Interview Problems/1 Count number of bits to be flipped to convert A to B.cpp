//Count number of bits to be flipped to convert A to B

#include <bits/stdc++.h> 
int numberOfFlips(int a, int b)
{
    int ans=a^b;
    int cnt=0;
    while(ans){
        if(ans&1==1)    cnt++;
        ans=ans>>1;
    }
    return cnt;
}

int main(){
    
}