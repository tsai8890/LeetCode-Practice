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
        for (int j = 1; j <= n; j ++) {
            dp[j] = MAX;
        }
        
        for (int i = 1; i <= maxRoot; i ++) {
            int k = i*i;
            for (int j = k; j <= n; j ++) {
                dp[j] = min(dp[j], 1+dp[j-k]);
            }
        }
        return dp[n];
    }
};