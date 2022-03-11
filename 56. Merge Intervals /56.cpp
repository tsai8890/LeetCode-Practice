#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    /*
        Title: 56. Merge Intervals
        Time Complexity: O(nlogn)
        Algorithm: 
            1. Sorting
        
        Date: 12/24/2021 16:35						
        Time: 12 ms  -- beat 98.58%
        Memory: 14.2 MB  -- beat 55.12%
    */
public:
    static bool compare(vector<int>& interval1, vector<int>& interval2) {
        return interval1[0] < interval2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<vector<int>> result;
        vector<int> cur_interval = intervals[0];
        for (int i = 1; i < intervals.size(); i ++) {
            if (cur_interval[1] < intervals[i][0]) {
                result.push_back(cur_interval);
                cur_interval = intervals[i];
            } else {
                cur_interval[1] = max(cur_interval[1], intervals[i][1]);
            }
        }
        result.push_back(cur_interval);
        return result;
    }
};