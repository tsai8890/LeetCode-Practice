#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 300. Longest Increasing Subsequence
    Time Complexity: O(n^2)
    Space Complexity: O(n)

    Algorithm: 
        1. Dynamic Programming
            
    Note:   
        1. 最直觀的DP，dp[i]: 以nums[i]為結尾的longest increasing subsequence的長度
        2. DP transition:
            dp[i] = max(dp[j]) + 1 if nums[j] < nums[i] for j from 0 to i-1

    Date: 03/24/2022 09:54						
    Time: 208 ms  -- beat 64.42%
    Memory: 10.6 MB  -- beat 14.82%
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = 1;
        
        int max_len = 1;
        for (int i = 1; i < nums.size(); i ++) {
            int max_ = 0;
            for (int j = 0; j <= i-1; j ++) {
                if (nums[j] < nums[i]) {
                    max_ = max(max_, dp[j]);
                }
            }
            dp[i] = max_ + 1;
            max_len = max(dp[i], max_len);
        }
        return max_len;
    }
};