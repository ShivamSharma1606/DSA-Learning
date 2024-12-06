#include <bits/stdc++.h>
using namespace std;
// tc: n and sc: n
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        /*
        first left half contain which is not affected interval
        middle half where operation to be performed
        third half contain which is not affect with interval
        */

        vector<vector<int>> result;
        int i = 0;
        int n = intervals.size();

        //first half which is not affected by the interval
        while (i < n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }

        //merging of the interval
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        //3rd half which is not affected by the interval    
        while (i < n)
        {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};