#include <vector>
using namespace std;

class Solution {
    /*
        Title: 35. Search Insert Position
        Time Complexity: O(log(N))
        Algorithm: 
            1. Binary Search
        
        Note:
            1. Check the border condition carefully(if insertion needed)

        Date: 12/06/2021 23:15	
        Time: 0 ms  -- beat 100.00%
        Memory: 9.8 MB  -- beat 22.79%
    */
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        
        while (left <= right) {
            mid = (left + right) / 2;
            
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;    
            } else {
                return mid;
            }
        }
        return left;
    }
};