#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch: s) {
            if (ch != 'c') {
                st.push(ch);
            }
            else {
                if (st.size() < 2) {
                    return false;
                } 
                else {
                    char second = st.top();
                    st.pop();
                    char first = st.top();
                    st.pop();
                    if (first != 'a' || second != 'b') {
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};