#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
    Title: 120. Triangle
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
        - 如果只記前一列，可以縮減到O(n)

    Algorithm:
        1. Dynamic Programming

    Note: 
        1. dp[i]: 掉落到該點的最小路徑的sum
           轉移方程：
                if (j == 0) {
                    up = dp[i-1][j];
                }
                else if (j == i) {
                    up = dp[i-1][j-1];
                }
                else {
                    up = min(dp[i-1][j-1], dp[i-1][j]);
                }
                dp[i][j] = triangle[i][j] + up;

        2. 和LeetCode 931. 一模一樣

    Date: 02/02/2022 17:31									
    Time: 7 ms  -- beat 69.34%
    Memory: 9.2 MB  -- beat 6.34%
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (n == 1) {
            return triangle[0][0];
        }
        
        vector<vector<int>> dp(n);
        dp[0].push_back(triangle[0][0]);
        
        int minSum = INT_MAX;
        int up;
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j <= i; j ++) {
                if (j == 0) {
                    up = dp[i-1][j];
                }
                else if (j == i) {
                    up = dp[i-1][j-1];
                }
                else {
                    up = min(dp[i-1][j-1], dp[i-1][j]);
                }
                dp[i].push_back(triangle[i][j] + up);
                
                if (i == n-1) {
                    minSum = min(minSum, dp[i][j]);
                }
            }
        }
        return minSum;
    }
};