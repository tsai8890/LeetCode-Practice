#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    /*
        Title: 198. House Robber
        Time Complexity: O(N)
        Algorithm: 
            1. Dynamic Programming
                i. dp[i] = max(nums[i] + d[i-2], dp[i-1])

        Date: 12/09/2021 17:44				
        Time: 0ms  -- beat 100.00%
        Memory: 7.8 MB  -- beat 21.03%
    */
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[nums.size()-1];
    }
};