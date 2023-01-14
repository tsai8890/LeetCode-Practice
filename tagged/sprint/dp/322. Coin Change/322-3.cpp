#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        const int MAX = 1000000;
        
        for (int j = 1; j <= amount; j ++) {
            dp[j] = MAX;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = coins[i-1]; j <= amount; j ++) {
                dp[j] = min(dp[j], 1+dp[j-coins[i-1]]);
            }
        }
        return (dp[amount] == MAX) ? -1 : dp[amount];
    }
};