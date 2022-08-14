#include <vector>
using namespace std;

/*
    Title: 42. Trapping Rain Water
    Time Complexity: O(N)
    Space Complexity: O(N)

    Algorithm: 
        1. Monotonic Stack
    
    Note:
        1. 技巧： 
            存進stack的可以是index(免去同時需要存height跟position的問題)，
            因為要height可以用height[index]，而index直接就是position了。

    Date: 01/29/2022 18:32	
    Time: 8 ms  -- beat 84.67%
    Memory: 15.8 MB  -- beat 62.62%
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int height_size = height.size();
        
        vector<int> st;
        st.push_back(0);
        
        int total_trap = 0;
        int current = 1;
        while (current < height.size()) {
            while (height[current] > height[st.back()]) {
                int mid = st.back();
                st.pop_back();
                if (st.empty())
                    break;
                
                int min_h = (height[st.back()] < height[current]) 
                             ? height[st.back()] : height[current];
                total_trap += (current - st.back() - 1) * (min_h - height[mid]);
            }
            st.push_back(current);
            current += 1;
        }
        return total_trap;
    }
};