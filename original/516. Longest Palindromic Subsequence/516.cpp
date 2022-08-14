#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
    Title: 516. Longest Palindromic Subsequence
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)

    Algorithm: 
        1. Dynamic Programming
            
    Note:   
        1. dp[i][j]: s[i..j]的longest palindromic subsequence長度

        2. 轉移方程：
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2
                else 
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j])

        3. 加速、省空間技巧： 因為這題限制s.length() <= 1000，
           所以用short int(2 bytes)就可以儲存了。

    Date: 02/09/2022 19:14					
    Time: 28 ms  -- beat 73.81%
    Memory: 41.5 MB  -- beat 52.45%
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<short>> dp(n, vector<short>(n, 0));
        
        for (int j = 0; j < n; j ++) {
            for (int i = j; i >= 0; i --) {
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0].back();
    }
};