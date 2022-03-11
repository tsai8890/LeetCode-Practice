#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 42. Trapping Rain Water
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Algorithm: 
        1. Brutal Force
    
    Note:
        1. 解題關鍵：
           給定index i，
           在i的位置上能盛的水量 = max(0, min(left_max, right_max) - height[i])
           left_max = max(height[j] where j < i)
           right_max = max(height[j] where i < j < n)   

    Date: ______
    Time: Time Limit Exceeded
    Memory: ______
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int height_size = height.size();
        int total_trap = 0;
        int left_max, right_max;

        for (int i = 1; i < height_size-1; i ++) {
            left_max = -1;
            for (int j = 0; j < i; j ++) {
                left_max = max(left_max, height[j]);
            }

            right_max = -1;
            for (int j = i+1; j < height_size; j ++) {
                right_max = max(right_max, height[j]);
            }

            int min_height = (left_max < right_max) ? left_max : right_max;
            total_trap += max(0, min_height - height[i]);
        }
        return total_trap;
    }
};