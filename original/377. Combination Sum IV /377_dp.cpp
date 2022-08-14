#include <vector>
using namespace std;

/*
    Title: 377. Combination Sum IV
    Time Complexity: O(|target| * |nums|)
    Space Complexity: O(|target|)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. dp[i]: the number of possible sequences from nums
           summing up to i
        
        2. Transition function:
            i.  dp[i] = sum(dp[i-nums[j]]) for j in [0..n-1] if i >= nums[j]
            ii. dp[0] = 1

    Date: 04/21/2022 14:35									
    Time: 0 ms  -- beat 100.00%    
    Memory: 6.5 MB  -- beat 93.01% 
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= target; i ++) {
            for (int j = 0; j < nums.size(); j ++) {
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};