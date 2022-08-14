#include <vector>
using namespace std;

/*
    Title: 84. Largest Rectangle in Histogram
    Time Complexity: O(n)
    Algorithm:
        1. Monotonic stack

    Note:
        1. 維護一個單調遞增的stack(top最大)，當下一個histogram小於stack的top時，
           不斷地把stack.top pop出來，每pop出來一個就計算相應的矩形面積，直到stack的top
           小於等於下一個histogram，再把下一個histogram push進去。
            
    Date: 01/05/2022 21:55						
    Time: 284 ms  -- beat 7.91%
    Memory: 126.9 MB  -- beat 5.17%
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<vector<int>> st;
        vector<int> based = {0, -1};
        st.push_back(based);
        
        int width = 0;
        int max_area = 0;
        for (int i = 0; i < heights.size(); i ++) {
            if (heights[i] >= st.back()[0]) {
                vector<int> added = {heights[i], i};
                st.push_back(added);
            }
            else {
                width = 0;
                while (heights[i] < st.back()[0]) {
                    width += st.back()[1] - st[st.size()-2][1];
                    max_area = max(max_area, st.back()[0] * width);
                    st.pop_back();
                }
                vector<int> added = {heights[i], i};
                st.push_back(added);
            }
        }
        
        width = 0;
        while (st.size() > 1) {
            width += st.back()[1] - st[st.size()-2][1];
            max_area = max(max_area, width*st.back()[0]);
            st.pop_back();
        }
        
        return max_area;
    }
};