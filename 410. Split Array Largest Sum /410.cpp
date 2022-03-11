#include <climits>
#include <vector>
using namespace std;

class Solution {
    /*
        Title: 410. Split Array Largest Sum
        Time Complexity:
            1. O(m x n^2)

        Algorithm:
            1. Dynamic Programming

        Note:
            1.  dp[i][j]: 在可使用數列為nums[0...i], 切成j份subarray的情況下，
                          可以獲得的最佳解。

                if j == 0:
                    dp[i][j] = sum(nums[0 ... i])
                else:
                    dp[i][j] = max(  
                                    min(sum(nums[i-k+1 ... i]), dp[i-k][j-1])
                                ) for k = 1 to i-j+1 

            2. 這不是最佳解，最佳解是用Greedy。

        Date: 12/18/2021 15:42						
        Time: 732ms  -- beat 15.25%
        Memory: 8.1 MB  -- beat 14.39%
    */
public:
    int splitArray(vector<int>& nums, int m) {
        vector<int> sum;
        sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i ++) {
            sum.push_back(nums[i] + sum[i-1]);
        }

        vector<vector<int>> dp(nums.size(), vector<int>(m, 0));
        for (int i = 0; i < dp.size(); i ++) {
            for (int j = 0; j < dp[0].size(); j ++) {
                if (i >= j) {
                    if (j == 0) {
                        dp[i][j] = sum[i];
                    } else {
                        dp[i][j] = INT_MAX;
                        for (int k = 1; i - k >= j - 1; k ++) {
                            dp[i][j] = min(dp[i][j], max(sum[i]-sum[i-k], dp[i-k][j-1]));
                        }
                    }
                }
            }
        }
        return dp.back().back();
    }
};