#include <vector>
using namespace std;

#define vt vector

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) {
            return vt<int>{-1};
        }

        // [[start, index]]
        vt<vt<int>> starts(intervals.size());
        for (int i = 0; i < intervals.size(); i ++) {
            starts[i] = vt<int>{intervals[i][0], i};
        }
        sort(starts.begin(), starts.end());

        vt<int> res(intervals.size());
        for (int i = 0; i < intervals.size(); i ++) {
            res[i] = bnSearch(starts, intervals[i][1]);
        }
        return res;
    }

    int bnSearch(vt<vt<int>>& starts, int end) {
        if (end > starts.back()[0]) {
            return -1;
        }

        int l = 0, r = starts.size()-1;
        while (l < r-1) {
            int mid = (l+r)/2;
            if (starts[mid][0] < end) {
                l = mid;
            }
            else if (starts[mid][0] > end){
                r = mid;
            }
            else {
                return starts[mid][1];
            }
        }
        return (end == starts[l][0]) ? starts[l][1] : starts[r][1];
    }
};