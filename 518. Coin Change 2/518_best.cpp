#include <vector>
using namespace std;

/*
    Title: 518. Coin Change 2
    Time Complexity: O(n x amount)
    Space Complexity: O(amount)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. 很猛的手法，類背包問題都可以這樣降低時間複雜度
            
        2.  dp[i]: amount為i時，總共的組合數
            i.   for i in [0..n-1]:
                     計算以coins[i]為結尾的所有組合
                     更新dp[1]..dp[amount]
            ii.  base case: dp[0] = 1
            iii. 很巧妙，值得一記

        3. 原本的DP是建立n x amount的二維DP陣列，但是這個解法只使用amount-size的
           一維陣列，時間複雜度是一樣的，但是少了很多存取記憶體的時間
        
        4. 每次寫到二維/三維dp時，可以試著想一下有沒有辦法只使用一維/二維(時間複雜度有可能一樣)
        
    Date: 04/14/2022 09:18								
    Time: 15 ms  -- beat 78.04%    
    Memory: 7.2 MB  -- beat 86.69% 
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < n; i ++) {
            for (int j = coins[i]; j <= amount; j ++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};