#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 322. Coin Change
    Time Complexity: O(n x amount)
    Space Complexity: O(amount)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. 很常見的手法，但是不容易想到
        2. 原本的DP是建立n x amount的二維DP陣列，但是這個解法只使用amount-size的
           一維陣列，時間複雜度是一樣的，但是少了很多存取記憶體的時間
        3. 每次寫到二維/三維dp時，可以試著想一下有沒有辦法只使用一維/二維(時間複雜度有可能一樣)
        
    Date: 04/12/2022 06:27								
    Time: 84 ms  -- beat 78.91%
    Memory: 14.4 MB  -- beat 67.70%
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int MAX = 10001;
        int n = coins.size();
        vector<int> dp(amount+1, MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i ++) {
            for (int j = 0; j < n; j ++) {
                if (coins[j] <= i) {
                    int temp = dp[i-coins[j]];
                    if (temp < dp[i]) {
                        dp[i] = temp + 1;
                    }
                }
            }
        }
        
        if (dp[amount] == MAX) {
            return -1;
        }
        else { 
            return dp[amount];
        }
    }
};