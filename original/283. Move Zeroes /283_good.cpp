#include <vector>
using namespace std;

class Solution {
    /*
        Title: 283. Move Zeroes
        Time Complexity: O(N)
        Note:
            1. Two Pointer(More efficient)       
            2. nums[i] ... nums[j]: 維護連續的0
               nums[0] ... nums[j]: 保證正確

        Date: 12/07/2021 10:37		
        Time: 12 ms  -- beat 99.11%
        Memory: 19.4 MB  -- beat 12.59%
    */
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        int temp;
        
        while (j < nums.size()) {
            if (nums[j] != 0) {
                if (i != j) {
                    temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
                i += 1;
                j += 1;
                
            } else {
                j += 1;
            }
        }
    }
};