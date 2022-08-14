#include <vector>
using namespace std;

/*
    Title: 96. Unique Binary Search Trees
    Time Complexity: O(n)
    Space Complexity: O(n)

    Algorithm:
        1. Dynamic Programming

    Note: 
        1.  dp[i]: 由i個unique元素所能形成的unique BST個數
            轉移方程：
                dp[0] = 1;    
                dp[i] = sum(dp[j] * dp[i-j-1]) for j in [0..i-1]

    Date: 01/31/2022 16:08						
    Time: 0 ms  -- beat 100.00%
    Memory: 6.2 MB  -- beat 11.39%
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j <= i-1; j ++) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp.back();
    }
};