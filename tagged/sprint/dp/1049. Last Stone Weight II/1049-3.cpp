#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto& stone: stones) {
            sum += stone;
        }
        
        int n = stones.size();
        int m = sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return sum - 2*helper(n, m, stones, dp);
    }

    int helper(int i, int j, vector<int>& stones, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (j >= stones[i-1]) {
            dp[i][j] = max(helper(i-1, j, stones, dp), 
                           helper(i-1, j-stones[i-1], stones, dp)+stones[i-1]);
        }
        else {
            dp[i][j] = helper(i-1, j, stones, dp);
        }
        return dp[i][j];
    }
};