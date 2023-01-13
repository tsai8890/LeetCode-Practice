#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int dp[n][2];
        dp[0][0] = 1;
        dp[0][1] = 1;
        
        int maxLen = 1;
        for (int i = 1; i < n; i ++) {
            dp[i][0] = 1;
            dp[i][1] = 1;
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j]) {
                    dp[i][0] = max(dp[i][0], dp[j][1]+1);
                }
                else if (nums[i] < nums[j]) {
                    dp[i][1] = max(dp[i][1], dp[j][0]+1);
                }
            }
            maxLen = max(maxLen, max(dp[i][0], dp[i][1]));
        }
        return maxLen;
    }
};