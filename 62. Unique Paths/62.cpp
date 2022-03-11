#include <vector>
using namespace std;

/*
    Title: 62. Unique Paths
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
    Algorithm: 
        1. Dynamic Programming

    Date: 02/05/2022 17:12				
    Time: 0 ms  -- beat 100.00%
    Memory: 6.6 MB  -- beat 24.09%
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != 0 || j != 0) {
                    if (i != 0) {
                        dp[i][j] += dp[i-1][j];
                    }
                    if (j != 0) {
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }
        return dp.back().back();
    }
};