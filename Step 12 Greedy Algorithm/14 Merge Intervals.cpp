class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {}; // Handle the edge case of an empty list
        
        // Sort intervals by the starting value
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                // Overlapping interval, extend the end if needed
                end = max(end, intervals[i][1]);
            } else {
                // No overlap, add the previous interval to result
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        // Add the last interval
        result.push_back({start, end});
        
        return result;
    }
};
