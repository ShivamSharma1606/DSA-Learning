/*
brute force approach tc: 3n and sc: 2n [I have done on codestudio]
1.  find the candies from left to right and store in a vector
        if it is greater than its previous element give him more
        else give him only one cany
2.  find the candies from right to left and store in a vector
        if it is greater than its previous element give him more
        else give him only one cany
3.  compare the ltr vector and rtl vector which have greater candies for each element 
        store in vector result.add( max(ltr[i],rtl[i]))
*/

//optimal approach[oneNote must]
class Solution {
public:
    int candy(vector<int>& rating) {

        int i = 1;
        int n = rating.size();
        int sum = 1;

        while (i < n) {
            if (rating[i] == rating[i - 1]) {
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while (i < n && rating[i] > rating[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while (i < n && rating[i] < rating[i - 1]) {
                sum += down;
                i++;
                down++;
            }
            if (down > peak) {
                sum = sum + (down - peak); //slope of down is greater than upper[oneNote necessary]
            }
        }
        return sum;
    }
};