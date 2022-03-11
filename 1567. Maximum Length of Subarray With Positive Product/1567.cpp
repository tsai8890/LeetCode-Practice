#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 1567. Maximum Length of Subarray With Positive Product
    Time Complexity: O(N)
    Space Complexity: O(N)

    Algorithm:
        1. Dynamic Programming        
    
    Note:
        1. dp[i][0]: 以nums[i]為結尾最長的正乘積subarray之長度
           dp[i][1]: 以nums[i]為結尾最長的負乘積subarray之長度

    Date: 01/27/2022 11:44			
    Time: 192 ms  -- beat 22.44%
    Memory: 91.6 MB  -- beat 5.66%
*/

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        
        if (nums[0] > 0) {
            dp[0][0] = 1;
            dp[0][1] = 0;
        }
        else if (nums[0] == 0) {
            dp[0][0] = 0;
            dp[0][1] = 0;
        }
        else {
            dp[0][0] = 0;
            dp[0][1] = 1;
        }
        
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] > 0) {
                if (dp[i-1][1] != 0)
                    dp[i][1] = dp[i-1][1] + 1;
                else 
                    dp[i][1] = 0;
                
                dp[i][0] = dp[i-1][0] + 1;
            }
            else if (nums[i] < 0) {
                if (dp[i-1][1] != 0)
                    dp[i][0] = dp[i-1][1] + 1;
                else 
                    dp[i][0] = 0;
                
                dp[i][1] = dp[i-1][0] + 1;
            }
            else {
                dp[i][0] = 0;
                dp[i][1] = 0;
            }
        }
        
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i ++) {
            maxLen = max(dp[i][0], maxLen);
        }
        return maxLen;
    }
};