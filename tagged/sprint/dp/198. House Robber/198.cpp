#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = {nums[0]};
        for (int i = 1; i < n; i ++) {
            if (i == 1) {
                dp.push_back(max(nums[0], nums[1]));
            }
            else {
                dp.push_back(max(nums[i] + dp[i-2], dp[i-1]));            
            }
        }
        return dp[n-1];
    }
};