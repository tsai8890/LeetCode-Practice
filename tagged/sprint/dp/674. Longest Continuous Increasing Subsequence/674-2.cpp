#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int curMax = 1;
        
        int longest = 1;
        for (int i = 1; i < n; i ++) {
            curMax = (nums[i] > nums[i-1]) ? curMax+1 : 1;
            longest = max(longest, curMax);
        }
        return longest;
    }
};