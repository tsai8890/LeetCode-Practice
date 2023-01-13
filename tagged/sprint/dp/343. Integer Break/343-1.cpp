#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        dp[1] = 1;
        for (int i = 2; i <= n; i ++) {
            for (int j = 1; j <= i-1; j ++) {
                if (i-j <= 3) {
                    dp[i] = max(dp[i], j * (i-j));
                }
                else {
                    dp[i] = max(dp[i], j * dp[i-j]);
                }
            }
        }
        return dp.back();
    }
};