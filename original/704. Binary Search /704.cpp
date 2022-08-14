#include <vector>
using namespace std;

class Solution {
    /*
        Title: 704. Binary Search
        Time Complexity: O(log(N))
        Algorithm: 
            1. Binary Search
                        
        Date: 12/06/2021 22:37	
        Time: 28 ms  -- beat 96.02%
        Memory: 27.5 MB  -- beat 61.87%
    */
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            
            if (nums[mid] == target) {
                return mid;
                
            } else if (nums[mid] < target) {
                left = mid + 1;
            
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};