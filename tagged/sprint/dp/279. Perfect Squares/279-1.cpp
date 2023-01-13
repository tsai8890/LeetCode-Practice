#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int maxRoot = 1;
        while (maxRoot * maxRoot <= n) {
            maxRoot++;
        }
        maxRoot--;
        
        const int MAX = 100005;
        vector<vector<int>> dp(maxRoot+1, vector<int>(n+1, 0));
        for (int i = 0; i <= maxRoot; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (j != 0) {
                    if (i == 0) {
                        dp[i][j] = MAX;
                    }
                    else {
                        dp[i][j] = dp[i-1][j];
                        if (j >= i*i) {
                            dp[i][j] = min(dp[i][j], 1+dp[i][j-i*i]);
                        }
                    }
                }
            }
        }
        return dp[maxRoot][n];
    }
};