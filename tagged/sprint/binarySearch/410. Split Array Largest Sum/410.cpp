#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        while (l < r) {
            int mid = (l + r) / 2;
            if (feasible(nums, mid, k)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    bool feasible(vector<int>& nums, int threshold, int k) {
        int i = 0, nGroups = 0;
        while (i < nums.size()) {
            int total = 0;
            while (i < nums.size() && total + nums[i] <= threshold) {
                total += nums[i];
                i ++;
            }
            nGroups ++;
        }
        return (nGroups <= k);
    }
};