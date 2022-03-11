#include <vector>
using namespace std;
    /*
        Title: 55. Jump Game
        Time Complexity: 
            1. O(n)

        Algorithm:
            1. Greedy

        Date: 12/27/2021 19:15						
        Time: 52 ms  -- beat 89.62%
        Memory: 48.2 MB  -- beat 78.11%
    */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, j = 0;
        while (i <= j && j < nums.size() - 1) {
            if (i + nums[i] > j) {
                j = i + nums[i];
            }
            i += 1;
        }
        
        if (i > j)
            return false;
        else 
            return true;
    }
};