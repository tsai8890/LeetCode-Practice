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
        vector<int> dp(m+1);
        for (int i = 0; i <= n; i ++) {
            for (int j = m; j >= 0; j --) {
                if (i == 0) {
                    dp[j] = (j == 0) ? 1 : 0;
                }
                else {
                    if (j >= nums[i-1]) {
                        dp[j] = dp[j] + dp[j-nums[i-1]];                    
                    }
                }
            }
        }
        return dp[m];
    }
};