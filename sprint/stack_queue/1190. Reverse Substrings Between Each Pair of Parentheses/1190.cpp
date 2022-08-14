#include <stack>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        int n = s.length();
        
        int i = 0;
        string segment = "";
        while (i < n) {
            if (s[i] != '(' && s[i] != ')') {
                segment += s[i];
            }
            else {
                if (!segment.empty()) {
                    st.push(segment);
                    segment.clear();
                }
                
                if (s[i] == '(') {
                    st.push("(");
                }   
                else if (s[i] == ')') {
                    string total = "";
                    while (!st.empty() && st.top() != "(") {
                        total = st.top() + total;
                        st.pop();
                    }
                    st.pop();
                    reverse(total.begin(), total.end());
                    st.push(total);
                }
            }
            i += 1;
        }
        st.push(segment);
        
        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};