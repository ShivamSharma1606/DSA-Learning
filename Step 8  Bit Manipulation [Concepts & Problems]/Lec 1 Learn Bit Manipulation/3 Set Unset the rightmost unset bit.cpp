    //without converting into binary form


// Set kth bit
int setKthBit(int N, int K)
{
    return (N | (1 << K));
}


// Unset the kth bit

int clearBit(int n, int k) {
    return n & (~(1 << k)); 
}

// Set the rightmost unset bit
int setBit(int n)
{
    return (n | n + 1);
}

//toggle the kth bit
int toggle(int n,int k){

    return (n^(1<<k));
}
//remove the last bit
int removeLast(int n){
    /*
    1. first way : ~n+1 & n
    2. second way : n & n-1
    */
   return n&(n-1);
}

/*
some more interestin question like that
https://www.naukri.com/code360/problems/set-k-bits_972999

*/