#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        
        // dp[j][0]: 在第i天處於「買完第j次股票」時的最大利潤
        // dp[j][1]: 在第i天處於「賣完第j次股票」時的最大利潤
        vector<vector<int>> dp(k, vector<int>(2));
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < k; j ++) {
                if (i == 0) {
                    dp[j][0] = -prices[0];
                    dp[j][1] = 0;
                }
                else if (j == 0) {
                    dp[j][1] = max(dp[j][1], dp[j][0] + prices[i]);
                    dp[j][0] = max(dp[j][0], -prices[i]);
                }
                else {
                    dp[j][1] = max(dp[j][1], dp[j][0] + prices[i]);
                    dp[j][0] = max(dp[j][0], dp[j-1][1] - prices[i]);
                }
            }
        }
        return dp[k-1][1];
    }
};