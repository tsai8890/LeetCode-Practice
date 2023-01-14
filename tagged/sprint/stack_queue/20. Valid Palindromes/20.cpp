#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch: s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {
                if (st.empty()) {
                    return false;
                }

                char left = st.top();
                if (   (left == '(' && ch == ')') 
                    || (left == '[' && ch == ']')
                    || (left == '{' && ch == '}')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};