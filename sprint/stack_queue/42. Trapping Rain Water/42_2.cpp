#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int n = height.size(), totalTrap = 0;
        int left = 0, right = n-1;
        int left_h = height[0], right_h = height[n-1];
        
        while (left < right - 1) {
            if (left_h < right_h) {
                if (height[left+1] >= left_h) {
                    left_h = height[left+1];
                }
                else {
                    totalTrap += left_h - height[left+1];                    
                }
                left += 1;
            }   
            else {
                if (height[right-1] >= right_h) {
                    right_h = height[right-1];
                }
                else {
                    totalTrap += right_h - height[right-1];                    
                }
                right -= 1;
            }
        }
        return totalTrap;
    }
};