#include <vector>
using namespace std;

class Solution {
    /*
        Title: 283. Move Zeroes
        Time Complexity: O(2xN)
        Note:
            1. Two Pointer(Cheating)       
        
        Date: 12/07/2021 10:29	
        Time: 20 ms  -- beat 81.10%
        Memory: 19.4 MB  -- beat 12.59%
    */
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j ++) {
            if (nums[j] != 0) {
                nums[i++] = nums[j];
            }
        }
        for (int j = i; j < nums.size(); j ++) {
            nums[j] = 0;
        }
    }
};