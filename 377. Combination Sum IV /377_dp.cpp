#include <vector>
using namespace std;

class Solution {
    /*
        Title: 377. Combination Sum IV
        Time Complexity: O(|target| * |nums|)
        Algorithm: 
            1. Dynamic Programming
            2. dp[i]: the number of possible sequences from nums
               summing up to i
                        
        Date: 12/06/2021 22:06	
        Time: 4 ms  -- beat 35.87%
        Memory: 6.6 MB  -- beat 64.21%
    */
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