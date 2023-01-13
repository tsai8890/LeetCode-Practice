#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> lastMaxSum = {nums[0]};
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            lastMaxSum.push_back(max(nums[i], nums[i]+lastMaxSum[i-1]));
            maxSum = max(maxSum, lastMaxSum[i]);
        }
        return maxSum;
    }
};