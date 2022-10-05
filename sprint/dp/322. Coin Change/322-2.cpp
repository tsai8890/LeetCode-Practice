#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        const int MAX = 1000000;
        
        for (int i = 0; i <= n; i ++) {
            for (int j = 1; j <= amount; j ++) {
                if (i == 0) {
                    dp[j] = MAX;
                }
                else {
                    if (j >= coins[i-1]) {
                        dp[j] = min(dp[j], 1+dp[j-coins[i-1]]);
                    }
                }
            }
        }
        return (dp[amount] == MAX) ? -1 : dp[amount];
    }
};