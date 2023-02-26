#include <vector>
using namespace std;

// Greedy

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if (nums.size() == 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min(nums[n-2]-nums[1], min(nums[n-3]-nums[0], nums[n-1]-nums[2]));
    }
};