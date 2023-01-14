#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int n = height.size(), totalTrap = 0;
        
        for (int i = 0; i < n; i ++) {
            int mid, left;
            while (!st.empty() && height[st.top()] <= height[i]) {
                mid = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                left = st.top();
                totalTrap += (min(height[left], height[i]) - height[mid]) * (i - left - 1);
            }
            st.push(i);
        }
        return totalTrap;
    }
};