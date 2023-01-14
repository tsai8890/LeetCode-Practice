#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        int rightMost = 0;
        for (int i = 0; i <= rightMost; i ++) {
            int jumpPos = min(n-1, i+nums[i]);
            for (; rightMost <= jumpPos; rightMost ++) {
                if (rightMost != 0) {
                    dp[rightMost] = dp[i] + 1;
                }
            }

            if (jumpPos == n-1) {
                break;
            }
        }
        return dp[n-1];
    }
};
