//dynamic soltution

//we increase the indexing by 1 to handle negative value

class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n=s.size();  //parent string
        int m=t.size(); //child string

        vector<vector<double>> dp(n+1,vector<double>(m+1,0));

        //base case[ if size of child string is zero i.e we have find the subsequences]
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }

        //base case [if size of parent string is zero i.e but we can't find the subsequence as we have no length]

        for(int i=1;i<=m;i++){  //start with 1 as 0 can change the base change case [above]
            dp[0][i]=0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    //then their are two possibility[1. we take that char in child or 2. don't consider]
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    //reduce the index of parent string
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        return (int)dp[n][m];
    }
};

// tabulation with space optimization[hw]


//tabulation with space optimization pro max[same as 0/1 knapsack problem]



