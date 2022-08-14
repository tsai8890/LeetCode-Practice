#include <vector>
using namespace std;

/*
    Title: 34. Find First and Last Position of Element in Sorted Array
    Time Complexity: 
        1. O(logn)

    Algorithm:
        1. Binary Search

    Date: 01/01/2022 21:40										
    Time: 3 ms  -- beat 96.26%
    Memory: 13.6 MB  -- beat 83.78%
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(binary_search(nums, target, 0));
        result.push_back(binary_search(nums, target, 1));
        return result;
    }
    
    int binary_search(vector<int>& nums, int target, int type) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (target < nums[mid]) {
                right = mid - 1;
            } 
            else if (target > nums[mid]) {
                left = mid + 1;
            }
            else if (target == nums[mid]) {
                if (type == 0) {
                    if (mid == 0 || nums[mid-1] != target) {
                        return mid;
                    } else {
                        right = mid - 1;
                    }
                } 
                else {
                    if (mid == nums.size()-1 || nums[mid+1] != target) {
                        return mid;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }
        
        return -1;
    }
};