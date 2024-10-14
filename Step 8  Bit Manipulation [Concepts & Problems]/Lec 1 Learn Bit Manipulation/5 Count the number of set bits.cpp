//more optimize approach
int countSetBits(int n)
{
    int cnt=0;
    while(n){
        cnt+= n&1; //this line is used in cp for finding the odd number or not(n&1)
        n=n>>1; // this line is used in cp
    }
    return cnt;
}

//most optimize apporach
int countSetBits(int n)
{
    int cnt=0;
    while(n){
        n=n&1;
        cnt++;
    }
    return cnt;
}

//one more same intersting question
// https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1