#include <bits/stdc++.h>
int maximumProfit(vector<int> &arr)
{
    int minbuy = arr[0];
    int profit = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        int cost = arr[i] - minbuy;
        profit = max(profit, cost);
        minbuy = min(minbuy, arr[i]);
    }
    return profit;
}

int main()
{
}