#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    /*
        Title: 189. Rotate Array
        Time Complexity: O(N)
        Note:
            1. It uses the rules of rotating arrays,
               and it's very efficient.            
        
        Date: 12/07/2021 00:09	
        Time: 24 ms  -- beat 89.33%
        Memory: 25 MB  -- beat 45.16%
    */
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};