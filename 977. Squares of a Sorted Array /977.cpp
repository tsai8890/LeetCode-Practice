#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    /*
        Title: 977. Squares of a Sorted Array
        Time Complexity: O(N)
        Algorithm: 
            1. Two Pointers

        Date: 12/06/2021 23:46		
        Time: 16 ms  -- beat 99.67%
        Memory: 26.9 MB  -- beat 16.98%
    */
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (pow(nums[right], 2) > pow(nums[left], 2)) {
                res.push_back(pow(nums[right], 2));
                right -= 1;
            } else {
                res.push_back(pow(nums[left], 2));
                left += 1;
            }           
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};