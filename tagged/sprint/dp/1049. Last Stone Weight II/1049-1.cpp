#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto& stone: stones) {
            sum += stone;
        }
        
        int n = stones.size();
        int m = sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else {
                    if (j >= stones[i-1]) {
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i-1]] + stones[i-1]);
                    }
                    else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        return sum - 2*dp[n][m];
    }
};