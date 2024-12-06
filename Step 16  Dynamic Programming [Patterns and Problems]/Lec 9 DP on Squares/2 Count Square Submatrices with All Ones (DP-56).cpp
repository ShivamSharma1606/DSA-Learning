//only tabulation solution 

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();    // no of rows
        int m = matrix[0].size(); // no of column

        // dp vector of same size of matrix
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // setting same value of first row of dp as matrix 
        int cnt = 0;
        for (int i = 0; i < m; i++) {

            dp[0][i] = matrix[0][i];
            cnt += dp[0][i];
        }

        // setting same value of first column of dp as matrix
        for (int i = 1; i < n; i++) {

            dp[i][0] = matrix[i][0];
            cnt += dp[i][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {

                if (matrix[i][j] != 0) {
                    // finding the min value from diagonal left and right
                    int value =
                        min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    dp[i][j] = value + 1;
                    cnt += dp[i][j];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return cnt;
    }
};