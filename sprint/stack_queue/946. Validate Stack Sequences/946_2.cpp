#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;

        int i = 0, j = 0;
        while (i < n && j < n) {
            if (st.empty() || st.top() != popped[j]) {
                st.push(pushed[i++]);
            }
            else {
                st.pop();
                j++;
            }
        }
        
        while (!st.empty() && st.top() == popped[j]) {
            st.pop();
            j += 1;
        }
        return (j == m);
    }
};