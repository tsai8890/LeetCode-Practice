#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    /*
        Title: 11. Container With Most Water
        Time Complexity: O(N)
        Algorithm: 
            1. Two Pointer(Left & Right)
                        
        Date: 12/08/2021 02:11	
        Time: 80 ms  -- beat 81.57%
        Memory: 58.9 MB  -- beat 79.59%
    */
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            int left_h = height[left];
            int right_h = height[right];
            int volume = min(left_h, right_h) * (right - left);
            
            max_water = max(max_water, volume);
            
            if (left_h < right_h) {
                while (left < right && height[left] <= left_h)  
                    left = left + 1;
            } else {
                while (left < right && height[right] <= right_h)  
                    right = right - 1;
            }
        }
        return max_water;
    }
};