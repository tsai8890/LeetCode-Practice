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
        vector<vector<bool>> dp(2, vector<bool>(m+1));
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (j == 0) {
                    dp[1][j] = true;
                }
                else if (i == 0) {
                    dp[1][j] = false;
                }
                else {
                    if (j >= nums[i-1]) {
                        dp[1][j] = dp[0][j] || dp[0][j-nums[i-1]];
                    }
                    else {
                        dp[1][j] = dp[0][j];
                    }
                }
            }
            dp[0].swap(dp[1]);
        }
        return dp[0][m];
    }
};