#include <vector>
using namespace std;

class Solution {
    /*
        Title: 70. Climbing Stairs
        Time Complexity: O(N)
        Note:
            1. Dynamic Programming
            2. dp[i] = dp[i-1] + dp[i-2]      
        
        Date: 12/07/2021 10:57	
        Time: 0 ms  -- beat 100.00%
        Memory: 6 MB  -- beat 52.66%
    */
public:
    int climbStairs(int n) {
        vector<int> dp = {1, 1};
        for (int i = 2; i <= n; i ++) {
            dp.push_back(dp[i-1] + dp[i-2]);
        }
        return dp[n];
    }
};