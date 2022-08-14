#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
    Title: 72. Edit Distance
    Time Complexity: O(nxm)
    Space Complexity: O(nxm)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. 看起來很DP的題目，但是細節要想清楚
        2. DP Details
            i.  dp[i+1][j+1]: word1[0..i] & word2[0..j] 的 minimum edit distance
            
            ii. Transition
                a. dp[i+1][j+1] = dp[i][j], if word1[i] == word2[j]
                b. dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j], dp[i][j]), otherwise

            iii.需要知道的東西
                a. dp[i+1][j+1]:
                    在word1[i]右邊能做的操作，只有delete, insert, replace三種。
                    而這三種分別對應到dp[i][j+1]+1, dp[i+1][j]+1, dp[i][j]+1
                    BTW
                        - insert的話，insert word2[j]在word1[i]的右邊一定是最佳解
                            - 這是可以證明的
                        - replace的話，insert word2[j]在word1[i]的右邊一定是最佳解
                            - 這是可以證明的

                b. 如果word1[i] == word2[j], 最佳解一定是word1[0..i-1] & word2[0..j-1]的edit distance
                    - 這是可以證明的

            iv. 這題的邊界情況，一樣可以透過dp row/col都多開一格來解決，
                i.   dp[0][j] = j (從空字串到word2[0..j-1]的minimum edit distance)
                ii.  dp[i][0] = i (從word1[0..i-1]到空字串的minimum edit distance)

        3. 因為題目因為題目限制n, m <= 500，所以可以用short int存，減少空間使用。
        
    Date: 03/29/2022 19:46							
    Time: 14 ms  -- beat 67.43%
    Memory: 9 MB  -- beat 37.30%
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0) {
                    dp[i][j] = j;
                }
                else if (j == 0) {
                    dp[i][j] = i;
                }
                else {
                    if (word1[i-1] == word2[j-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    }   
                    else {
                        dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                    }
                }
            }
        }
        return dp[n][m];
    }
};