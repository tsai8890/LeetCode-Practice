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
        
        3. DP array 中其實只會用到 2 rows x 6 columns 的空間，所以可以透過這個部分
           來減少整體的 memory 使用量，而使用 vectorA.swap(vectorB) 可以用 O(1)-time
           來交換兩個 vector，並不會增加時間複雜度

    Date: 05/31/2022 16:07												    			
    Time: 0 ms  -- beat 100.00%
    Memory: 6 MB  -- beat 53.74%
*/

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(2, vector<int>(6, 0));
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= 5; j ++) {
                if (i == 1) {
                    dp[1][j] = j;
                }
                else {
                    dp[1][j] = 0;
                    for (int k = 1; k <= j; k ++) {
                        dp[1][j] += dp[0][k];
                    }
                }
            }
            dp[0].swap(dp[1]);
        }
        return dp[0][5];
    }
};