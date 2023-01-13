#include <stack>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int nAdds = 0;
        for (char ch: s) {
            if (ch == '(') {
                st.push(ch);
            }
            else {
                if (st.empty()) {
                    nAdds += 1;
                }
                else {
                    st.pop();
                }
            }
        }
        
        nAdds += st.size();
        return nAdds;
    }
};