//tabulation solution
//todo: [status : done]


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int k = 0;
        for(int i = 0; i < n; i++){
            k += arr[i];
        }
        if(k-d < 0) return 0;
        if((k-d)%2 != 0)    return 0;
    
        int zeroCount = count(arr.begin(), arr.end(), 0);
        if (zeroCount == n && d == 0) {
            return pow(2, n);
        }
    
        int s2 = (k - d)/2;
        vector<vector<int>> dp(n,vector<int>(s2+1,0));
    
        //edge case
        if(arr[0]==0){
            dp[0][0] = 2;
        }
        else{
            dp[0][0] = 1;
            if(arr[0] <= s2) {
                dp[0][arr[0]] = 1;
            }
        }
        
        for(int i = 1; i < n; i++){
            for(int target = 0; target <= s2; target++){
                int notTaken = dp[i-1][target];
                int taken = 0;
                if(target >= arr[i]){
                    taken = dp[i - 1][target - arr[i]];
                }
    
                dp[i][target] = taken + notTaken;
            }
        }
        
    
        return dp[n-1][s2];
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends