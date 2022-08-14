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
        1. 很猛的手法，類背包問題都可以這樣降低時間複雜度
            
        2.  dp[i]: amount為i時，總共的組合數
            i.   for i in [0..n-1]
                     計算以coins[i]為結尾的所有組合
                     更新dp[1]..dp[amount]
            ii.  base case: dp[0] = 1
            iii. 很巧妙，值得一記

        3. 原本的DP是建立n x amount的二維DP陣列，但是這個解法只使用amount-size的
           一維陣列，時間複雜度是一樣的，但是少了很多存取記憶體的時間
        
        4. 每次寫到二維/三維dp時，可以試著想一下有沒有辦法只使用一維/二維(時間複雜度有可能一樣)
        
    Date: 04/14/2022 09:54									
    Time: 79 ms  -- beat 81.90%    
    Memory: 14.5 MB  -- beat 53.28% 
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int MAX = 100001;
        vector<int> dp(amount+1, MAX);
        dp[0] = 0;
        
        for (int i = 0; i < n; i ++) {
            for (int j = coins[i]; j <= amount; j ++) {
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
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