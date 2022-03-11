#include <vector>
using namespace std;

/*
    Title: 96. Unique Binary Search Trees
    Time Complexity: O(n)
    Space Complexity: O(n)

    Algorithm:
        1. Dynamic Programming

    Note: 
        1. 這是稍微優化的版本，利用static宣告，將之前算完的結果儲存起來，
           這樣下次就可以不用重複算，可以讓總體執行速度更快。

    Date: 01/31/2022 16:03						
    Time: 0 ms  -- beat 100.00%
    Memory: 6.1 MB  -- beat 36.11%
*/

class Solution {
public:
    int numTrees(int n) {
        static vector<int> dp(20, 0);
        static int last = 0;
        
        if (dp[n] == 0) {
            dp[0] = 1;
            for (int i = last+1; i <= n; i ++) {
                for (int j = 0; j <= i-1; j ++) {
                    dp[i] += dp[j] * dp[i-j-1];
                }
            }
            last = n;
        }
        return dp[n];
    }
};