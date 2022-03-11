#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
    Title: 5. Longest Palindromic Substring
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)

    Algorithm: 
        1. Dynamic Programming
            
    Note:   
        1. dp[i][j]: s[i..j]是否為palindromic substring
        2. 轉移方程：
                if (i == j)
                    dp[i][j] = true

                else if (i + 1 == j])
                    dp[i][j] = (s[i] == s[j])
                
                else 
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1])

        3. 加速、省空間技巧： 因為只有true/false，用bool值存即可

    Date: 02/10/2022 00:24							
    Time: 820 ms  -- beat 11.61%
    Memory: 55.9 MB  -- beat 26.88%
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        int maxStart = 0, maxLen = 1;
        for (int j = 0; j < n; j ++) {
            for (int i = j; i >= 0; i --) {
                if (i == j) {
                    dp[i][j] = true;
                }
                else if (i + 1 == j) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                
                if (dp[i][j] && j-i+1 > maxLen) {
                    maxStart = i;
                    maxLen = j-i+1;
                }
            }
        }
        return s.substr(maxStart, maxLen);
    }
};