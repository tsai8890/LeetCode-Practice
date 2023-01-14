#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& num: nums) {
            sum += num;
        }
        
        if (sum % 2 != 0) {
            return false;
        }
        
        int n = nums.size();
        int m = sum / 2;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1));
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (j == 0) {
                    dp[i][j] = true;
                }
                else if (i == 0) {
                    dp[i][j] = false;
                }
                else {
                    if (j >= nums[i-1]) {
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
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