#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
/*
    Title: 45. Jump Game II
    Time Complexity: O(n^2)
    Space Complexity: O(n)

    Algorithm:
        1. Dynamic Programming

    Date: 12/27/2021 19:33						
    Time: 1068 ms  -- beat 6.24%
    Memory: 48.2 MB  -- beat 78.11%
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        
        for (int i = 1; i < dp.size(); i ++) {
            int cur_step = INT_MAX;
            for (int j = 0; j <= i - 1; j ++) {
                if (j + nums[j] >= i) {
                    cur_step = min(cur_step, dp[j]);
                }
            }
            dp[i] = cur_step + 1;
        }
        return dp.back();
    }
};