#include <vector>
using namespace std;

#define TRUE 1
#define FALSE -1
#define NOT_TRIED -2

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& num: nums) {
            sum += num;
        }
        
        if (sum % 2 != 0) {
            return false;
        }
        
        int n = nums.size();
        int m = sum / 2;
        vector<vector<int>> dp(n+1, vector<int>(m+1, NOT_TRIED));
        return helper(n, m, nums, dp);
    }

    bool helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (j == 0) {
            return true;
        }
        if (i == 0 && j != 0) {
            return false;
        }

        if (dp[i][j] != NOT_TRIED) {
            return (dp[i][j] == TRUE);
        }
        
        bool result = helper(i-1, j, nums, dp);
        if (j >= nums[i-1]) {
            result = result || helper(i-1, j-nums[i-1], nums, dp);
        }
        dp[i][j] = result ? TRUE : FALSE;
        return result;
    }
};