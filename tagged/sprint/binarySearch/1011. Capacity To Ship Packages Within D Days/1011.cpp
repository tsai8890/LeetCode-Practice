#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while (l < r) {
            int mid = (l+r) / 2;
            if (feasible(weights, mid, days)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool feasible(vector<int>& weights, int C, int days) {
        int i = 0, nDays = 0;
        while (i < weights.size()) {
            int total = 0;
            while (i < weights.size() && (total+weights[i]) <= C) {
                total += weights[i];
                i ++;
            }
            nDays ++;
        }
        return (nDays <= days);
    }
};