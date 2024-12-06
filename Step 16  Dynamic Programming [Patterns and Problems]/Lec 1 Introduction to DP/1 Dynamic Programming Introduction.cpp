//memorization , tabulation

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long int mod = 1000000007;
    long long fibonacci(int n,vector<long long> &dp){
        if(n==0)    return 0;
        if(n==1){
            return 1;
        }
        if(dp[n]!= -1)  return dp[n];
        return dp[n]=(fibonacci(n-1,dp)%mod +fibonacci(n-2,dp)%mod)%mod;
    }
    
    long long int topDown(int n) {
        // code here
        vector<long long> dp(n+1,-1);
        return fibonacci(n,dp);
    }
    
    long long int bottomUp(int n) {
        // code here
        if(n==0)    return 0;
        vector<long long> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        
        //more better bottomup approach [even without space compelexity]
        // if(n==1 || n==0)    return n;
        // int prev=1;
        // int prev2=1;
        // int result;
        // for(int i=2;i<n;i++){
        //     result=prev+prev2;
        //     prev=result;
        //     prev2=prev;
        // }
        // return prev;
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends   