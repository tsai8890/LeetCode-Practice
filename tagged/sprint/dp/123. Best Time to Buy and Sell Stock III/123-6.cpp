#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n, 0));

        for (int k = 1; k <= 2; k ++) {
            for (int i = 0; i < n; i ++) {
                int maxVal = -100000;
                for (int j = k*2-2; j <= i-1; j ++) {
                    maxVal = max(maxVal, -prices[j]+dp[k-1][j+1]);
                }
                dp[k][i] = (i >= k*2-1) ? max(dp[k][i-1], prices[i]+maxVal) : 0;
            }
        }
        return dp[2][n-1];
    }
};