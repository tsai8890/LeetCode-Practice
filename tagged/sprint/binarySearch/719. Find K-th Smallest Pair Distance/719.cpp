#include <vector>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), less<int>());
        int l = 0, r = nums.back() - nums.front();
        while (l < r) {
            int mid = (l + r) / 2;
            if (count(nums, k, mid) >= k) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    int count(vector<int>& nums, int k, int threshold) {
        int l = 0, r = 0;
        int total = 0;
        while (l < nums.size()) {
            while (r+1 < nums.size() && nums[r+1] - nums[l] <= threshold) {
                r ++;
            }
            total += (r - l);
            l ++;
        }
        return total;
    }
};