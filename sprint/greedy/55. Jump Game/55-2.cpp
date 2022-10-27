#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool result = true;
        
        int closest_pos = n-1;
        for (int i = n-2; i >= 0; i --) {
            if (i + nums[i] >= closest_pos) {
                result = true;
                closest_pos = i;
            }
            else {
                result = false;
            }
        }
        return result;
    }
};