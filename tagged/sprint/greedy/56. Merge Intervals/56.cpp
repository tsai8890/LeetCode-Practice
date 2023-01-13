#include <vector>
using namespace std;

class Solution {
public:
    static bool compare(vector<int>& interval1, vector<int>& interval2) {
        return interval1[0] < interval2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        
        int n = intervals.size();
        vector<vector<int>> res;
        int leftMost = intervals[0][0], rightMost = intervals[0][1];
        for (int i = 1; i < n; i ++) {
            if (intervals[i][0] <= rightMost) {
                rightMost = max(rightMost, intervals[i][1]);
            }
            else {
                res.push_back(vector<int>{leftMost, rightMost});
                leftMost = intervals[i][0];
                rightMost = intervals[i][1];
            }
        }
        res.push_back(vector<int>{leftMost, rightMost});
        return res;
    }
};