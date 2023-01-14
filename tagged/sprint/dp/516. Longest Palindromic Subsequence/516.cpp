#include <string>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n][n];
        
        for (int i = n-1; i >= 0; i --) {
            for (int j = i; j < n; j ++) {
                if (j == i) {
                    dp[i][j] = 1;
                }
                else {
                    if (s[i] == s[j]) {
                        dp[i][j] = 2 + ((j == i+1) ? 0 : dp[i+1][j-1]);
                    }
                    else {
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};