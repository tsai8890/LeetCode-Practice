#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        
        stack<int> st;
        int j;
        for (int i = 0; i < 2*n; i ++) {
            j = i % n;
            while (!st.empty() && nums[st.top()] < nums[j]) {
                if (st.top() < n) {
                    res[st.top()] = nums[j];
                }
                st.pop();
            }
            if (i < n) {
                st.push(i);
            }
        }
        return res;
    }
};