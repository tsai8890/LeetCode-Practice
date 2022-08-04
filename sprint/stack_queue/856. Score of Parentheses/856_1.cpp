#include <stack>
#include <string>

#define LEFT -1

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int totalScore = 0;
        int curScore = 0;
        
        for (char ch: s) {
            if (ch == '(') {
                st.push(LEFT);
            }
            else {
                curScore = 0;
                while (!st.empty() && st.top() != LEFT) {
                    curScore += st.top();
                    st.pop();
                }
                st.pop();
                st.push(max(2*curScore, 1));
                
                if (st.size() == 1) {
                    totalScore += st.top();
                    st.pop();
                }
            }
        }
        return totalScore;
    }
};