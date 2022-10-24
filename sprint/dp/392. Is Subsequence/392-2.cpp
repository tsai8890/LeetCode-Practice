#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0) {
            return true;
        }
        
        int n = s.length(), m = t.length();
        bool dp[n+1][m+1];

        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0) {
                    dp[i][j] = true;
                }
                else if (j == 0) {
                    dp[i][j] = false;
                }
                else {
                    if (s[i-1] == t[j-1]) {
                        dp[i][j] = dp[i-1][j-1];    
                    }
                    else {
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        return dp[n][m];
    }
};