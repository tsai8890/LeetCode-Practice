#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int& num: nums) {
            sum += num;
        }
        if ((sum - target) % 2 != 0 || (sum - target) < 0) {
            return 0;
        }
        
        int n = nums.size();
        int m = (sum - target) / 2;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(n, m, nums, dp);
    }

    int helper(int n, int m, vector<int>& nums, vector<vector<int>>& dp) {
        if (n == 0) {
            return (m == 0) ? 1 : 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        dp[n][m] = helper(n-1, m, nums, dp);
        if (m >= nums[n-1]) {
            dp[n][m] += helper(n-1, m-nums[n-1], nums, dp);
        }
        return dp[n][m];
    }
};