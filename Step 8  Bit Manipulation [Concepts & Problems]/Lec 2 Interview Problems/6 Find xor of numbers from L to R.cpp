//brute force approach
//using the for loop for given range and find the xor for that range

//optimal approach 
//pen and paper: find the xor for first 12 number

int calculateXOR(int n)
{
    // Write your code here.
    if(n%4==1)  return 1;
    else if (n%4==2) return n+1;
    else if (n%4==3) return 0;
    else if (n%4==0) return n;   
}


//for a give range(eg from 4 to 8)

class Solution {
  public:
    int calculateXOR(int n)
    {
    // Write your code here.
    if(n%4==1)  return 1;
    else if (n%4==2) return n+1;
    else if (n%4==3) return 0;
    else if (n%4==0) return n;   
    }
    
    int findXOR(int l, int r) {
        // complete the function here
        return  calculateXOR(l-1)^calculateXOR(r);
    }
};

int main(){

}

