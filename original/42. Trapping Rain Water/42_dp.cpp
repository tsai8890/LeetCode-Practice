#include <vector>
#include <algorithm>
using namespace std;

/*
    Title: 42. Trapping Rain Water
    Time Complexity: O(N)
    Space Complexity: O(N)

    Algorithm: 
        1. Dynamic Programming
    
    Note:
        1. 解題關鍵：
           給定index i，
           在i的位置上能盛的水量 = max(0, min(left_max, right_max) - height[i])
           left_max = max(height[j] where j < i)
           right_max = max(height[j] where i < j < n)   
        
        2. 這題可以達到線性複雜度的關鍵，在於要以O(1)-time取得left_max跟right_max。
           因此，可以使用DP，將left_max做成一個前綴陣列，right_max做成一個後綴陣列。
           即 left_max[i] = max(height[k] where 0 <= k <= i)
              right_max[i] = max(height[k] where i <= k < n)

    Date: 01/29/2022 15:52	
    Time: 7 ms  -- beat 86.96%
    Memory: 16 MB  -- beat 31.29%
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int height_size = height.size();
        vector<int> left_max(height.size());
        vector<int> right_max(height.size());
        
        left_max[0] = height[0];
        for (int i = 1; i < height_size; i ++) {
            left_max[i] = max(left_max[i-1], height[i]);
        }
        
        right_max[height_size-1] = height.back();
        for (int i = height_size-2; i >= 0; i --) {
            right_max[i] = max(right_max[i+1], height[i]);
        }
        
        int total_trap = 0;
        for (int i = 1; i < height_size-1; i ++) {
            int min_height = (left_max[i-1] < right_max[i+1]) ? left_max[i-1] : right_max[i+1];
            total_trap += max(0, min_height - height[i]);
        }
        return total_trap;
    }
};