//brute force approach : O(n^2)
// samNotes

//take test case:  1110011110 and k=2

//better solution: o(2n)

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.

    int l=0;
    int r=0;
    int zero=0;
    int len=0;
    int maxi=0;

    while(r<n){

        if(arr[r]==0)   zero++;

        while(k<zero){
            if(arr[l]==0)    zero--;
            l++;
        }

        if(zero<=k){
            len=r-l+1;
        }
        maxi=max(maxi,len);
        r++;
    }
    return maxi;
}

//optimal solution : O(n)

class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {

        int l=0;
        int r=0;
        int zero=0;
        int len=0;
        int maxi=0;

        while(r<arr.size()){

            if(arr[r]==0)   zero++;

            if(k<zero){
                if(arr[l]==0)    zero--;
                l++;
            }

            if(zero<=k){
                len=r-l+1;
            }
            maxi=max(maxi,len);
            r++;
        }
        return maxi;        
    }
};

