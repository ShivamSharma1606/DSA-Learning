//brute force approach
//using double loop and comparing

//better approach
//using hashing TC=2N AND SC=N

//OPTIMAL APPROACH 1
//use long long because if we use int all test case will not pass
vector<int> findMissingRepeatingNumbers(vector < int > arr) {
    // Write your code here
    long long n=arr.size();
    long long s=(n*(n+1))/2;
    long long s2=((n)*(n+1)*(2*n+1))/6; //to finding the square of s
    long long sn=0;
    long long s2n=0;

    for(int i=0;i<n;i++){
        sn+=arr[i];
        s2n+=(long long)arr[i]*(long long)arr[i];
    }

    long long val1=sn-s;  //x-y
    long long val2=s2n-s2;//x^2-y^2

    val2=val2/val1; //x+y

    long long x=(val1+val2)/2;
    long long y=val2-x;
    return {(int)x,(int)y};
}   

//OPTIMAL APPROACH 2 IS POSSIBLE IF BIT MANUPLATION WAS COMPLETE

