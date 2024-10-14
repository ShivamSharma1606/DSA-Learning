//without converting into binary (if 1's equal to 1 then it is power of 2)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)    return false;
        if(n==INT_MIN) return false;
        if((n&(n-1))==0)  return true;
        return false;
    }
};