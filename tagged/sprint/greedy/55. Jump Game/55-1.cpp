#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool dp[n];
        dp[n-1] = true;
        
        int closest_pos = n-1;
        for (int i = n-2; i >= 0; i --) {
            if (i + nums[i] >= closest_pos) {
                dp[i] = true;
                closest_pos = i;
            }
            else {
                dp[i] = false;
            }
        }
        return dp[0];
    }
};