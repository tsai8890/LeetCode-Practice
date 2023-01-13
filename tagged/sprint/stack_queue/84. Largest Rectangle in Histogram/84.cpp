#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<long long> st;
        long long maxRect = 0;
        
        for (int i = 0; i < n; i ++) {
            if (st.empty() || heights[st.top()] <= heights[i]) {
                st.push(i);
            }
            else {
                int rightMost = st.top();
                while (!st.empty() && heights[st.top()] > heights[i]) {
                    int cur = st.top();
                    st.pop();
                    
                    long long curRect;
                    if (st.empty()) {
                        curRect = heights[cur] * (rightMost + 1);
                    }
                    else {
                        curRect = heights[cur] * (rightMost - st.top()); 
                    }
                    maxRect = max(maxRect, curRect);
                }
            }
            st.push(i);
        }
        
        int rightMost = st.top();
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            
            long long curRect;
            if (st.empty()) {
                curRect = heights[cur] * (rightMost + 1);
            }
            else {
                curRect = heights[cur] * (rightMost - st.top());
            }
            maxRect = max(maxRect, curRect);
        }
        return maxRect;
    }
};