#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = 1;
        
        int longest = 1;
        for (int i = 1; i < n; i ++) {
            dp[i] = 1;
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            longest = max(longest, dp[i]);
        }
        return longest;
    }
};