#include <vector>
using namespace std;

/*
    Title: 518. Coin Change 2
    Time Complexity: O(n x amount)
    Space Complexity: O(n x amount)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. knapsack problem(無限背包問題)的變形
        2. DP
            i.   dp[i][j]: 目前可使用coins[0..i]，剩餘amount=j時，可產生的組合數量
            ii.  Transition:
                a. dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]]
                b. 需要特判 if (coins[i] <= j) 以及 if (i > 0)

            iii. Base Case:
                a. dp[i][0] = 1

        3. DP實作時很關鍵的兩個點，想好基本上就結束了
            i.  Transition Function
            ii. Base Case
        
    Date: 04/13/2022 15:28								
    Time: 65 ms  -- beat 22.45%
    Memory: 18.4 MB  -- beat 37.35%
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1));
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <= amount; j ++) {
                if (j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = 0;
                    if (coins[i] <= j) {
                        dp[i][j] += dp[i][j-coins[i]];
                    }
                    if (i > 0) {
                        dp[i][j] += dp[i-1][j];
                    }
                }
            }
        }
        return dp[n-1][amount];
    }
};