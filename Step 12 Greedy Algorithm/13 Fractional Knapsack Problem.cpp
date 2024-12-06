#include <bits/stdc++.h>
bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return (double)a.second / a.first > (double)b.second / b.first;
}
double maximumValue(vector<pair<int, int>> &a, int n, int w)
{
    sort(a.begin(), a.end(), comp);
    int wt = w;
    double result = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (wt >= a[i].first)
        {
            wt -= a[i].first;
            result += a[i].second;
        }
        else
        {
            double remain = (double)a[i].second / a[i].first * wt;
            result += remain;
            break;
        }
    }
    return result;
}