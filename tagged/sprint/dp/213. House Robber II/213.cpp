#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int includeFirst = nums[0] + maxRob(nums, 2, n-2);
        int withoutFirst = maxRob(nums, 1, n-1);
        return max(includeFirst, withoutFirst);
    }
    
    int maxRob(vector<int>& nums, int start, int end) {
        if (start >= nums.size() || start > end) {
            return 0;
        }
        
        int n = end - start + 1;
        vector<int> dp(n);
        dp[0] = nums[start];
        for (int i = 1; i < n; i ++) {
            if (i == 1) {
                dp[i] = max(nums[start], nums[start+1]);
            }          
            else {
                dp[i] = max(dp[i-1], nums[start+i]+dp[i-2]);
            }
        }
        return dp[n-1];
    }
};