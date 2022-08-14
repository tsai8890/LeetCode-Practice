class Solution {
public:
    bool ans(int i, int n, vector<int>& nums, unordered_map<int, bool>& dp) {
        if (i == n) {
            return true;
        }
        else if (dp.find(i) != dp.end()) {
            return dp[i];
        }
        else {
            bool result = false;
            if (i <= n-2 && nums[i] == nums[i+1]) {
                result = result || ans(i+2, n, nums, dp);
            }
            if (i <= n-3 && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
                result = result || ans(i+3, n, nums, dp);
            }
            if (i <= n-3 && nums[i]+1 == nums[i+1] && nums[i+1]+1 == nums[i+2]) {
                result = result || ans(i+3, n, nums, dp);
            }
            dp[i] = result;
            return result;
        }
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> dp;
        return ans(0, n, nums, dp);
    }
};