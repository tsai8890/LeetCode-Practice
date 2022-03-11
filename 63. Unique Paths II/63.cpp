#include <vector>
using namespace std;

/*
    Title: 63. Unique Paths II
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
    Algorithm: 
        1. Dynamic Programming

    Date: 01/13/2022 08:01			
    Time: 0ms  -- beat 100.00%
    Memory: 7.8 MB  -- beat 37.72%
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = 1;
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (obstacleGrid[i][j] == 0) {
                    if (i >= 1) {
                        dp[i][j] += dp[i-1][j];
                    }
                    if (j >= 1) {
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};