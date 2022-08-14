#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 322. Coin Change
    Time Complexity: O(n x amount)
    Space Complexity: O(n x amount)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. knapsack problem(無限背包問題)的變形
        2. DP
            i.   dp[i][j]: 目前可使用coins[0..i]，剩餘amount=j時，最少數量的組合
            ii.  Transition:
                a. dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]])
                b. 需要特判 if (coins[i] <= j) 以及 if (i == 0)

            iii. Base Case:
                a. dp[i][0] = 0
                b. dp[i][j] = MAX if no solution

        3. DP實作時很關鍵的兩個點，想好基本上就結束了
            i.  Transition Function
            ii. Base Case
        
    Date: 04/12/2022 06:03								
    Time: 212 ms  -- beat 15.58%
    Memory: 45.1 MB  -- beat 19.34%
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int MAX = 100000;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1));
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j <= amount; j ++) {
                if (j == 0) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = MAX;
                    if (coins[i] <= j && dp[i][j-coins[i]] != MAX) {
                        dp[i][j] = dp[i][j-coins[i]] + 1;
                    }
                    if (i != 0 && dp[i-1][j] != MAX) {
                        dp[i][j] = min(dp[i][j], dp[i-1][j]);
                    }
                }
            }
        }
        
        if (dp[n-1][amount] == MAX) {
            return -1;
        }
        else { 
            return dp[n-1][amount];
        }
    }
};