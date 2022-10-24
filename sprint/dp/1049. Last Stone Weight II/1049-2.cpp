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
        vector<int> dp(m+1);
        
        for (int i = 0; i <= n; i ++) {
            for (int j = m; j >= 0; j --) {
                if (i == 0 || j == 0) {
                    dp[j] = 0;
                }
                else {
                    if (j >= stones[i-1]) {
                        dp[j] = max(dp[j], dp[j-stones[i-1]] + stones[i-1]);
                    }
                    else {
                        dp[j] = dp[j];
                    }
                }
            }
        }
        return sum - 2*dp[m];
    }
};