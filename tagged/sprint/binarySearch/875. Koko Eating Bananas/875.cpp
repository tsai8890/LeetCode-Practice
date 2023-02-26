#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = (l + r) / 2;
            if (feasible(piles, mid, h)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool feasible(vector<int>& piles, int s, int h) {
        int total = 0;
        for (int i = 0; i < piles.size(); i ++) {
            total += piles[i] / s;
            if (piles[i] % s) {
                total ++;
            }
        }
        return (total <= h);
    }
};