#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 343. Integer Break
    Time Complexity: O(n^2)
    Space Complexity: O(n)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. 手法和LeetCode 518, 322 Coin Change系列題目完全一樣
            i. 原本需要開O(nxn)-size dp array，可以優化到只開O(n)-size，
        
        2. dp[i]: amount為i時，最大的product
            i.   for i in [1..n]:
                     計算以i為結尾的所有組合
                     更新dp[i]..dp[n]
            ii.  base case: dp[0] = 1

        3. 重要關鍵：
            i. 因為這題要求必須拆成至少兩個數(k>=2)相乘，所以如果直接用上述方法解，
               當 (n/2)x(n/2) <= n時，也就是n=2或3時，上述解法會找到錯的答案(也就是不切)，
               因此需要特判 "n==2 or n==3" 的special case

        4. 原本的DP是建立O(nxn)-size的二維DP陣列，但是這個解法只使用O(n)-size的
           一維陣列，時間複雜度是一樣的，但是少了很多存取記憶體的時間
        
        5. 每次寫到二維/三維dp時，可以試著想一下有沒有辦法只使用一維/二維(時間複雜度有可能一樣)
        
    Date: 04/19/2022 21:32								
    Time: 0 ms  -- beat 100.00%    
    Memory: 6.2 MB  -- beat 26.91% 
*/

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
            vector<int> dp(n+1, 0);
            dp[0] = 1;

            for (int i = 1; i <= n; i ++) {
                for (int j = i; j <= n; j ++) {
                    dp[j] = max(dp[j], i*dp[j-i]);
                }
            }
            return dp[n];
        }
    }
};