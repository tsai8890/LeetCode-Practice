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
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0) {
                    dp[i][j] = (j == 0) ? 1 : 0;
                }
                else {
                    if (j >= nums[i-1]) {
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];                    
                    }
                    else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][m];
    }
};