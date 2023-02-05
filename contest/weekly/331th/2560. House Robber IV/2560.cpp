#include <vector>
using namespace std;

// Binary Search

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 1, r = 1000000000;
        while (l < r) {
            int mid = (l + r) / 2;
            if (valid(nums, mid, k)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
    
    bool valid(vector<int>& nums, int threshold, int k) {
        int res = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] <= threshold) {
                res ++;
                i ++;
            }
            if (res >= k) {
                return true;
            } 
            i ++;
        }
        return false;
    }
};