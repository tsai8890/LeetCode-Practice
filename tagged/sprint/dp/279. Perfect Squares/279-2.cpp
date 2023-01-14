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
        vector<int> dp(n+1, 0);
        for (int i = 0; i <= maxRoot; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (j != 0) {
                    if (i == 0) {
                        dp[j] = MAX;
                    }
                    else {
                        if (j >= i*i) {
                            dp[j] = min(dp[j], 1+dp[j-i*i]);
                        }
                    }
                }
            }
        }
        return dp[n];
    }
};