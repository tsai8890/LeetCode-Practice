#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<vector<int>>> dp(N+1, 
                                       vector<vector<int>>(m+1, vector<int>(n+1)));
        
        for (int i = 0; i <= N; i ++) {
            int ones = 0, zeros = 0;
            if (i > 0) {
                for (char& ch: strs[i-1]) {
                    if (ch == '0') {
                        zeros++;
                    }
                    else {
                        ones++;
                    }
                }
            }
            
            for (int j = 0; j <= m; j ++) {
                for (int k = 0; k <= n; k ++) {
                    if (i == 0) {
                        dp[i][j][k] = 0;
                    }
                    else {
                        if (zeros <= j && ones <= k) {
                            dp[i][j][k] = max(dp[i-1][j][k], 
                                              dp[i-1][j-zeros][k-ones] + 1);
                        }
                        else {
                            dp[i][j][k] = dp[i-1][j][k];
                        }
                    }
                }
            }
        }
        return dp[N][m][n];
    }
};