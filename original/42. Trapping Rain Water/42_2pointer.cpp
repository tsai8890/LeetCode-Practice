#include <vector>
using namespace std;

/*
    Title: 42. Trapping Rain Water
    Time Complexity: O(N)
    Space Complexity: O(1)

    Algorithm: 
        1. Two Pointer
    
    Note:
        1. 如果left pointer的高度比right pointer小，則移動left pointer。
           反之，則移動right pointer。
        
        2. two pointer萬能啊，以後碰到水柱的題目，可以想到two pointer。

    Date: 01/29/2022 18:32	
    Time: 7 ms  -- beat 86.96%
    Memory: 15.6 MB  -- beat 97.33%
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int height_size = height.size();
        
        int total_trap = 0;
        int left = 0, right = height_size - 1;
        int left_max = height[0], right_max = height.back();
        
        while (left < right - 1) {
            if (left_max < right_max) {
                if (height[left+1] > left_max) {
                    left_max = height[left+1];
                }
                else {
                    total_trap += left_max - height[left+1];
                }
                left += 1;
            } 
            else {
                if (height[right-1] >= right_max) {
                    right_max = height[right-1];
                }
                else {
                    total_trap += right_max - height[right-1];
                }
                right -= 1;
            }
        }
        return total_trap;
    }
};