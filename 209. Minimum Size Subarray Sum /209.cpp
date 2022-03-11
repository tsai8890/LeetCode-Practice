#include <vector>
using namespace std;

class Solution {
    /*
        Title: 209. Minimum Size Subarray Sum
        Time Complexity: O(N)
        Algorithm: 
            1. Sliding Window(Two Pointer)
            2. Classical!!!
                        
        Date: 12/03/2021 02:00
        Time: 4 ms  -- beat 96.52%
        Memory: 10.6 MB  -- beat 59.26%
    */
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int min_len = 0;
        int sum = 0;

        while (true) {
            if (sum < target) {
                if (j == nums.size())
                    break;
                sum += nums[j++];
                
            } else if (sum > target) {
                if (min_len == 0)
                    min_len = (j - i);
                else
                    min_len = min(min_len, (j - i));
                sum -= nums[i++];
                
            } else {
                if (min_len == 0)
                    min_len = (j - i);
                else
                    min_len = min(min_len, (j - i));
                sum -= nums[i++];
            }     
        }
        return min_len;        
    }
};