class bruteforce
{

    long fun(long *values, int buy, int day, int n)
    {

        // their is no possiblity to sell and buy stock
        if (day == n)
        {
            return 0;
        }

        long profit = 0;
        // we have chance to buy the stock
        if (buy)
        {
            long chosetobuy = -values[day] + fun(values, 0, day + 1, n);
            long chosetohold = fun(values, 1, day + 1, n);
            profit = max(chosetohold, chosetobuy);
        }
        // we have to sell the stock
        else
        {
            long chosetosell = values[day] + fun(values, 1, day + 1, n);
            long chosetohold = 0 + fun(values, 0, day + 1, n);
            profit = max(chosetobuy, chosetosell);
        }
        return profit;
    }

    long getMaximumProfit(long *values, int n)
    {

        return fun(values, 1, 0, n);
    }
};

class bettermemo{
    #include<bits/stdc++.h>
long fun(long *values,int buy,int day,int n,vector<vector<long>> &dp){
    
    //their is no possiblity to sell and buy stock
    if(day==n){
        return  0;
    }

    if(dp[day][buy]!= -1)   return dp[day][buy];
    long profit=0;
    //we have chance to buy the stock
    if(buy){
        long chosetobuy = - values[day]+fun(values, 0, day + 1,n,dp);
        long chosetohold =   fun(values, 1, day + 1,n,dp);
        profit = max(chosetohold,chosetobuy);
    }
    //we have chance to sell the stock
    else{
        long chosetosell = values[day] + fun(values, 1, day + 1,n,dp);
        long chosetohold = 0 + fun(values, 0, day + 1,n,dp);
        profit =max(chosetobuy,chosetosell);
    }
    return dp[day][buy]=profit;
}

long getMaximumProfit(long *values, int n)
{
    
    vector<vector<long>> dp(n,vector<long>(2,-1));
    return fun(values,1, 0,n,dp);
}
};

class TaublationSolution {
public:
    int maxProfit(vector<int>& values) {
        int n = values.size();
        vector<vector<long>> dp(n + 1, vector<long>(2, -1));

        // base case
        dp[n][0] = 0, dp[n][1] = 0;

        for (int day = n-1; day >= 0; day--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit=0;
                if (buy) {
                    int chosetosell = -values[day] + dp[day+1][0];
                    int chosetohold = dp[day+1][1];
                    profit = max(chosetohold, chosetosell);
                }
                // we have to buy the stock
                else {
                    int chosetobuy = values[day] + dp[day+1][1];
                    int chosetohold = 0 + dp[day+1][0];
                    profit = max(chosetobuy, chosetohold);
                }
                dp[day][buy] = profit;
            }
        }

        return dp[0][1];
    }
};


//tabulation with space optimization[hw]

//taublation with space optimization pro max[using four variable][hw]