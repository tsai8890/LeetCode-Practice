#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp, false);
    }
    
    int helper(int n, vector<int>& dp, bool valid) {
        if (valid && (1 <= n && n <= 3)) {
            return n;
        }
        
        if (dp[n] != -1) {
            return dp[n];
        }
        
        int maxVal = 0;
        for (int i = 1; i <= n-1; i ++) {
            maxVal = max(maxVal, i*helper(n-i, dp, true));
        }
        dp[n] = maxVal;
        return dp[n];
    }
};