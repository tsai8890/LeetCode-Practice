#include <algorithm>
using namespace std;

class Solution {
    /*
        Title: 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
        Time Complexity:
            1. O(nlogn)

        Algorithm: 
            1. Brutal Force

        Date: 12/17/2021 17:55						
        Time: 92ms  -- beat 56.42%
        Memory: 35.3 MB  -- beat 49.55%
    */
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        } else {
            sort(nums.begin(), nums.end());
            int most_far = nums.back() - nums.front();
            
            int max_decrease = 0;
            for (int i = 0; i <= 3; i ++) {
                int decrease = nums[i] - nums[0];
                decrease += nums.back() - nums[nums.size() - 1 - (3-i)]; 
                max_decrease = max(max_decrease, decrease);
            }
            return most_far - max_decrease;
        }
    }
};