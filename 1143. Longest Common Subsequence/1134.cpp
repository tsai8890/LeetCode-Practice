#include <vector>
#include <string>
using namespace std;

/*
    Title: 1143. Longest Common Subsequence
    Time Complexity: O(nxm)
    Space Complexity: O(nxm)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. 經典DP題，longest XX XX系列的題目，針對text1[0..i], text1[0..j]，
           只需考慮LCS出現的四種情況(包含/不包含 text1[i]/text2[j])

           Transition:
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i-1][j-1] + 1
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

        2. 這題的邊界情況，可以透過dp row/col都多開一格來解決，這樣可以讓
           程式碼更簡潔
        
        3. 因為題目因為題目限制n, m <= 1000，所以可以用short int存，減少空間使用。
        
    Date: 03/27/2022 14:27						
    Time: 30 ms  -- beat 48.92%
    Memory: 9.9 MB  -- beat 92.55%
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        short n = text1.length(), m = text2.length();
        vector<vector<short>> dp(n+1, vector<short>(m+1, 0));
        
        for (short i = 0; i < n; i ++) {
            for (short j = 0; j < m; j ++) {
                if (text1[i] == text2[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                }
                else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);   
                }
            }
        }
        return (int)dp[n][m];
    }
};