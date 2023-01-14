#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(2, vector<int>(m+1));
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0 || j == 0) {
                    dp[1][j] = (i == 0) ? j : i;
                }
                else {
                    dp[1][j] = min(min(dp[1][j-1], dp[0][j]), dp[0][j-1]) + 1;
                    if (word1[i-1] == word2[j-1]) {
                        dp[1][j] = min(dp[1][j], dp[0][j-1]);
                    }
                }
            }
            dp[0].swap(dp[1]);
        }
        return dp[0][m];
    }
};