#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        
        int erases = 0;
        int end = INT_MIN;
        int n = intervals.size();
        
        for (auto& interval: intervals) {
            if (interval[0] < end) {
                erases ++;
            }
            else {
                end = interval[1];
            }
        }
        return erases;
    }
};