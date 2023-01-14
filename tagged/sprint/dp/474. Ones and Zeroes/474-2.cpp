#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
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
            
            for (int j = m; j >= 0; j --) {
                for (int k = n; k >= 0; k --) {
                    if (i == 0) {
                        dp[j][k] = 0;
                    }
                    else {
                        if (zeros <= j && ones <= k) {
                            dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones] + 1);
                        }
                    }
                }
            }
        }
        return dp[m][n];
    }
};