//brute force approach
/*
samsung notes
*/

//optiaml approach
//O(n)

#include <bits/stdc++.h> 
int lengthOfLongestSubstring(string &s) {
    //testcase on : cadbzabcde
    // Write your code here.
    int arr[256] = {-1}; // we can also use hash map but array also be used of 256 lenght because thieir are only 256 character in cpp
    int l=0;
    int r=0;
    int maxlen=0;

    while(r<s.size()){

        if(arr[s[r]]!= -1){
            if(arr[s[r]]>=l){ //important lines(if the character exist before left pointer then we discard to modifiy its value i.e if condition is not satasify)
            
                l=arr[s[r]]+1;// important lines
            }
        }

        maxlen=max(maxlen,r-l+1);
        arr[s[r]]=r; // it put the max index value of the character in the defined array
        r++;
    }

    return maxlen;
}