#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 343. Integer Break
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. 手法和LeetCode 518, 322 Coin Change系列題目完全一樣
        
        2. dp[i][j]: amount為j時，可以切的數字在[1..i]中，最大的product
            Transition:
                if j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-i]*i)
                    // 需要判斷 i >= 2 or j >= i

        3. 重要關鍵：
            i. 因為這題要求必須拆成至少兩個數(k>=2)相乘，所以如果直接用上述方法解，
               當 (n/2)x(n/2) <= n時，也就是n=2或3時，上述解法會找到錯的答案(也就是不切)，
               因此需要特判 "n==2 or n==3" 的special case
        
    Date: 04/19/2022 21:48								
    Time: 0 ms  -- beat 100.00%    
    Memory: 6.7 MB  -- beat 6.54% 
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        
        if (n == 2) {
            return 1;
        }
        else if (n == 3) {
            return 2;
        }
        else {
            vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
            for (int i = 1; i <= n; i ++) {
                for (int j = 0; j <= n; j ++) {
                    if (j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = -1;
                        if (j >= i) {
                            dp[i][j] = max(dp[i][j], dp[i][j-i] * i);
                        } 
                        
                        if (i >= 2) {
                            dp[i][j] = max(dp[i][j], dp[i-1][j]);
                        }
                    }
                }
            }
            return dp[n][n];
        }
    }
};