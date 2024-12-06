//brute force approach[algo on oneNote same as dp 36 only cap is added]
//better approach using memorization
//optimal approach using tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // dp[n][buy/sell][capicity left: 2 , 1, 0]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // base case
        // when bag  capcity is zero
        //  for(int i=0;i<=n;i++){
        //      for(int j=0;j<2;j++){
        //          dp[i][j][0]=0;
        //      }
        //  }

        // bag case when size of n=0
        //  for(int i=0;i<2;i++){
        //      for(int j=0;j<3;j++){
        //          dp[0][i][j]=0;
        //      }
        //  }

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {

                    // we can buy the stock
                    if (buy == 0) {
                        // max(buy the stock , hold the stock)
                        dp[ind][buy][cap] =max(-prices[ind] + dp[ind + 1][1][cap],dp[ind + 1][0][cap]);
                    }
                    // we can sell the stock[then only our capacity will decresae
                    // (curiouse question that when we buy the stock then
                    // capacity should be reduce but while buying we don't know
                    // when the stock will be sold, but at time of selling that
                    // stock was defenitely buy before)]
                    else {
                        // max(sell the stock, hold the stock)
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][0][cap - 1], dp[ind + 1][1][cap]);
                    }
                }
            }
        }

        return dp[0][0][2];
    }
};
//optimal approach using tabulation with space optimization

//oa with so pro max[most unique till date]
