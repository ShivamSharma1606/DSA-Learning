//brute force approach
//using for loop

#include <bits/stdc++.h>
//tc: logn 
long long Pow(int x, int n)
{
    int m=n;
    n=abs(n);
    double ans=1;

    while(n>0){
        if(n%2==1){
            ans=ans*x;
            n--;
        }else{
            n=n/2;
            x=x*x;
        }
    }
    if(m<0) return 1.0/ans;

    return ans;

}

int main(){
    
}