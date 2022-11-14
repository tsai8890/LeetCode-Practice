#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int right = 0;
        
        for (int i = 0; i <= right; i ++) {
            right = max(right, i+nums[i]);
            if (right >= n-1) {
                break;
            }
        }
        return (right >= n-1);
    }
};