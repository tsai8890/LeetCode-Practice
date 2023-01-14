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
        vector<bool> dp(m+1);
        for (int i = 0; i <= n; i ++) {
            for (int j = m; j >= 0; j --) {
                if (j == 0) {
                    dp[j] = true;
                }
                else if (i == 0) {
                    dp[j] = false;
                }
                else {
                    if (j >= nums[i-1]) {
                        dp[j] = dp[j] || dp[j-nums[i-1]];
                    }
                    else {
                        dp[j] = dp[j];
                    }
                }
            }
        }
        return dp[m];
    }
};