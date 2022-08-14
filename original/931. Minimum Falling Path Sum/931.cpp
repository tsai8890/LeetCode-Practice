#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    Title: 931. Minimum Falling Path Sum
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
        - 如果只記前一列，可以縮減到O(n)

    Algorithm:
        1. Dynamic Programming

    Note: 
        1. dp[i]: 掉落到該點的最小路徑的sum
           轉移方程：
                dp[i][j] = matrix[i][j];
                
                if (i != 0) {
                    if (j == 0) {
                        dp[i][j] += min(dp[i-1][j], dp[i-1][j+1]);
                    }
                    else if (j == n-1) {
                        dp[i][j] += min(dp[i-1][j], dp[i-1][j-1]);
                    }
                    else {
                        dp[i][j] += min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
                    }
                }

    Date: 02/02/2022 17:10								
    Time: 16 ms  -- beat 62.70%
    Memory: 10.3 MB  -- beat 35.82%
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        int minSum = INT_MAX;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                dp[i][j] = matrix[i][j];
                
                if (i != 0) {
                    if (j == 0) {
                        dp[i][j] += min(dp[i-1][j], dp[i-1][j+1]);
                    }
                    else if (j == n-1) {
                        dp[i][j] += min(dp[i-1][j], dp[i-1][j-1]);
                    }
                    else {
                        dp[i][j] += min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
                    }
                }
                
                if (i == n-1) {
                    minSum = min(minSum, dp[i][j]);
                }
            }
        }
        return minSum;
    }
};