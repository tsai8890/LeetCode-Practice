#include <vector>
using namespace std;

/*
    Title: 1641. Count Sorted Vowel Strings
    Time Complexity: O(15xn)
    Space Complexity: O(5xn)-extra space

    Algorithm: 
        1. Dynamic Programming (Bottom-Up)
        
    Note:
        1. 典型的 bottom-up DP 題目

        2. Dynamic Programming:
            dp[i][j]: 目標長度為 i，可以使用 j 個字母時，所有可能字串的個數

            DP Transition
                dp[i][j] = j,  if i == 1
                dp[i][j] = sum(dp[i-1][k] for k in [1, j]),  otherwise
        
    Date: 05/31/2022 15:39												    			
    Time: 0 ms  -- beat 100.00%
    Memory: 6.5 MB  -- beat 8.0%
*/

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(6, 0));
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= 5; j ++) {
                if (i == 1) {
                    dp[i][j] = j;
                }
                else {
                    for (int k = 1; k <= j; k ++) {
                        dp[i][j] += dp[i-1][k];
                    }
                }
            }
        }
        return dp[n][5];
    }
};