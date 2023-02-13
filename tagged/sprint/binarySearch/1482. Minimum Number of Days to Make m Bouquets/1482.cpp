#include <vector>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() / k < m) {
            return -1;
        }

        int l = 1;
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l < r) {
            int mid = (l + r) / 2;
            if (feasible(bloomDay, m, k, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool feasible(vector<int>& bloomDay, int m, int k, int day) {
        int res = 0, len = 0;
        for (int i = 0; i < bloomDay.size(); i ++) {
            len = (bloomDay[i] <= day) ? len+1 : 0;
            if (len == k) {
                res ++;
                len = 0;
            }
        }
        return (res >= m);
    }
};