#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool static comp(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);

        int freetime = intervals[0][1];
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= freetime)
            {
                cnt++;
                freetime = intervals[i][1];
            }
        }
        return n - cnt;
    }
};