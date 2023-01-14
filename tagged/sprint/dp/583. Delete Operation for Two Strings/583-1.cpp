#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = (i == 0) ? j : i;
                }
                else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                    if (word1[i-1] == word2[j-1]) {
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                    }
                }
            }
        }
        return dp[n][m];
    }
};