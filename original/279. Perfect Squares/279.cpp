#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 279. Perfect Squares
    Time Complexity: O(n^2)
    Space Complexity: O(n)-extra space

    Algorithm: 
        1. Dynamic Programming
        
    Note:
        1. dp[i]: amount為i時，最小的組合長度
            i.   for i in [1..sqrt(n)]:
                     計算以i^2為結尾的所有組合
                     更新dp[1]..dp[n]
            ii.  base case: dp[0] = 0
            iii. 很巧妙，值得一記

        2. 和LeetCode 518./322./343.優化方式一樣，從二維dp變成一維dp

        3. DP實作時很關鍵的兩個點，想好基本上就結束了
            i.  Transition Function
            ii. Base Case
        
    Date: 04/20/2022 10:52									
    Time: 197 ms  -- beat 58.60%
    Memory: 9 MB  -- beat 72.67%
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 10001);
        dp[0] = 0;
        
        for (int i = 1; i*i <= n; i ++) {
            for (int j = i*i; j <= n; j ++) {
                int temp = i*i;
                dp[j] = min(dp[j], dp[j-temp] + 1);
            }
        }
        return dp[n];
    }
};