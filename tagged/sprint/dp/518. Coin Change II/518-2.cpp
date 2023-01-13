#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= amount; j ++) {
                if (j == 0) {
                    dp[j] = 1;
                }
                else if (i == 0) {
                    dp[j] = 0;
                }
                else if (j >= coins[i-1]) {
                    dp[j] += dp[j-coins[i-1]];
                }
            }
        }
        return dp[amount];
    }
};