#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        const int MAX = 1000000;
        
        for (int i = 0; i <= n; i ++) {
            for (int j = 1; j <= amount; j ++) {
                if (i == 0) {
                    dp[i][j] = MAX;
                }
                else {
                    dp[i][j] = dp[i-1][j];
                    if (j >= coins[i-1]) {
                        dp[i][j] = min(dp[i][j], 1+dp[i][j-coins[i-1]]);
                    }
                }
            }
        }
        return (dp[n][amount] == MAX) ? -1 : dp[n][amount];
    }
};