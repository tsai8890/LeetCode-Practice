#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = {1};
        
        int longest = 1;
        for (int i = 1; i < n; i ++) {
            dp.push_back((nums[i] > nums[i-1]) ? dp[i-1]+1 : 1);
            longest = max(longest, dp[i]);
        }
        return longest;
    }
};