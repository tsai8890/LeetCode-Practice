#include <vector>
#include <string>
using namespace std;

/*
    Title: 97. Interleaving String
    Time Complexity: O(len(s1)xlen(s2))
    Space Complexity: O(len(s1)xlen(s2))-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. 很經典的DP題目，和Edit Distance有異曲同工之妙

        2. dp[i][j]: s3[0..i+j-1] 是否是 「s1[0..i-1]和s2[0..j-1]的interleaving」
            Transition Function:
                dp[i][j] = false;
                if (i > 0 && s1[i-1] == s3[i+j-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j]
                }
                if (j > 0 && s2[j-1] == s3[i+j-1]) {
                    dp[i][j] = dp[i][j] || dp[i][j-1]
                }
                
            Base Case:
                dp[0][0] = true 
                
    Date: 04/23/2022 00:21										
    Time: 4 ms  -- beat 72.46%    
    Memory: 6.6 MB  -- beat 70.22% 
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if (n + m != s3.length()) {
            return false;
        }
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                else {
                    dp[i][j] = false;
                    if (i > 0 && s1[i-1] == s3[i+j-1]) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                    if (j > 0 && s2[j-1] == s3[i+j-1]) {
                        dp[i][j] = dp[i][j] || dp[i][j-1];
                    }
                }
            }
        }
        return dp[n][m];
    }
};