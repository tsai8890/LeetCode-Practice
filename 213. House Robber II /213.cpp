#include <vector>
using namespace std;

class Solution {
    /*
        Title: 213. House Robber II
        Time Complexity: O(N)
        Algorithm: 
            1. Dynamic Programming
                i. Use two-dimensional dp table.

                ii. dp[i][0]: the maximum amount of money 
                    using values from nums[0]...nums[i] 
                    except nums[0].

                    dp[i][1]: the maximum amount of money 
                    using values from nums[0]...nums[i] 
                    including nums[0].

                iii. if i != nums.size() - 1,
                        dp[i][0] = max((nums[i] + dp[i-2][0]), dp[i-1][0])
                        dp[i][1] = max((nums[i] + dp[i-2][1]), dp[i-1][1])
                     
                     otherwise,
                        dp[i][0] = max((nums[i] + dp[i-2][0]), dp[i-1][0])
                        dp[i][1] = dp[i-1][1])
    
        Date: 12/09/2021 21:09				
        Time: 0ms  -- beat 100.00%
        Memory: 8.1 MB  -- beat 14.68%
    */
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = nums[1];
        dp[1][1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); i ++) {
            if (i < nums.size() - 1) {
                dp[i][0] = max(nums[i] + dp[i-2][0], dp[i-1][0]);
                dp[i][1] = max(nums[i] + dp[i-2][1], dp[i-1][1]);
            } else {
                dp[i][0] = max(nums[i] + dp[i-2][0], dp[i-1][0]);
                dp[i][1] = dp[i-1][1];
            }
        }
        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);        
    }
};
