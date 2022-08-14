#include <vector>
#include <string>
using namespace std;

/*
    Title: 97. Interleaving String
    Time Complexity: O(len(s1)xlen(s2))
    Space Complexity: O(len(s2))-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. 很經典的DP題目，和Edit Distance有異曲同工之妙

        2. 和2D DP array的解法完全一樣，只是利用了原本transition function
           的特性，dp[i][j] = dp[i-1][j] || dp[i][j-1]，也就是說其實我們
           只需要O(len(s2))-size DP array即可完成。

            當i=a, j=b，
            dp[k] = dp[i][k] if k < b
                  = dp[i-1][k] if k >= b

        3. 很猛啦，該記了

    Date: 04/23/2022 00:49											
    Time: 0 ms  -- beat 100.00%    
    Memory: 6.3 MB  -- beat 77.32% 
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if (n + m != s3.length()) {
            return false;
        }
        
        vector<bool> dp(m+1, false);
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                }
                else {
                    bool res = false;
                    if (i > 0 && s1[i-1] == s3[i+j-1]) {
                        res = res || dp[j];
                    }
                    if (j > 0 && s2[j-1] == s3[i+j-1]) {
                        res = res || dp[j-1];
                    }
                    dp[j] = res;
                }
            }
        }
        return dp[m];
    }
};