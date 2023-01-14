#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n, 0));

        for (int k = 1; k <= 2; k ++) {
            int maxVal = -100000;
            for (int i = 0; i < n; i ++) {
                if (i >= k*2-1) {
                    maxVal = max(maxVal, -prices[i-1]+dp[k-1][i]);                
                }
                dp[k][i] = (i >= k*2-1) ? max(dp[k][i-1], prices[i]+maxVal) : 0;
            }
        }
        return dp[2][n-1];
    }
};