#include <stack>
#include <utility>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (char ch: s) {
            if (st.empty() || st.top().first != ch) {
                st.push(make_pair(ch, 1));
            }
            else {
                pair<char, int> p = st.top();
                st.pop();
                if (p.second + 1 < k) {
                    st.push(make_pair(p.first, p.second+1));
                }
            }
        }
        
        string res;
        pair<char, int> curPair;
        while (!st.empty()) {
            curPair = st.top();
            for (int i = 0; i < curPair.second; i ++) {
                res.push_back(curPair.first);
            }
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};