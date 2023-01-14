#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), m = popped.size();
        stack<int> st;
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            if (st.empty() || st.top() != popped[j]) {
                st.push(pushed[i++]);
            }
            else {
                st.pop();
                j++;
            }
        }
        
        if (j == m) {
            return true;
        }
        else {
            while (j < m && !st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            return (j == m);
        }
    }
};