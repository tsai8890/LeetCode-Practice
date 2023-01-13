#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        
        // dp[i][j][0]: 在第i天處於「買完第j次股票」時的最大利潤
        // dp[i][j][1]: 在第i天處於「賣完第j次股票」時的最大利潤
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(2)));
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < k; j ++) {
                if (i == 0) {
                    dp[i][j][0] = -prices[0];
                    dp[i][j][1] = 0;
                }
                else if (j == 0) {
                    dp[i][j][0] = max(dp[i-1][j][0], -prices[i]);
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] + prices[i]);
                }
                else {
                    dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1] - prices[i]);
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] + prices[i]);
                }
            }
        }
        return dp[n-1][k-1][1];
    }
};