#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
    Title: 926. Flip String to Monotone Increasing
    Time Complexity: O(2xn)
    Space Complexity: O(2xn)-extra space

    Algorithm: 
        1. Dynamic Programming (Bottom-Up)
        
    Note:
        1. 典型的 bottom-up DP 題目

        2. Dynamic Programming:
            dp[i][j]: 將s[0..i] 變成 monotone，且s[i]最後是j的最小cost
            j in {0, 1}

            DP Transition
                i.      dp[0][0] = s[i] - '0';
                ii.     dp[0][1] = '1' - s[i];
                iii.    dp[i][j] = dp[i-1][0] + s[i] - '0', if j = 0
                        dp[i][j] = min(dp[i-1][0], dp[i-1][1]) + '1' - s[i], if i = 1
        
    Date: 06/03/2022 00:31															    			
    Time: 269 ms  -- beat 5.02%
    Memory: 78.7 MB  -- beat 5.09%
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        dp[0][0] = s[0] - '0';
        dp[0][1] = '1' - s[0];
        for (int i = 1; i < n; i ++) {
            dp[i][0] = dp[i-1][0] + (s[i] - '0');
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + ('1' - s[i]);
        }
        return min(dp[n-1][0], dp[n-1][1]);
    }
};