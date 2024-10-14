#include <bits/stdc++.h>
//decimal to binary


//binary to decimal
int convert(int N, string &str)
{
    // Write your code here.
    int p2=1;
    int num=0;
    for(int i=N-1;i>=0;i--){

        if(str[i]=='1') num=num+p2;
        p2=p2*2;
    }
    return num;
}

//1's complement(fliping the binary bits)
//2's complement(1's complement +1) : negative no is 2's complement of +ve number
//AND
//0R
//XOR
/*
no of 1's is odd -> 1
no of 1's is even-> 0
*/

//RIGHT SHIFT(>>) 
/*
X= (X/2^K) 
where k is no of right shift
it divide the number by 2
*/

//LEFT SHIFT(<<)
/*
it multiply the number by 2
*/

//NOT OPERATOR(~)
/*
flip the bits of the number(i.e 1's complement)
*/

