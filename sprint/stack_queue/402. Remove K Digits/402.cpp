#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string st = "";
        for (char ch: num) {
            while (k != 0 && !st.empty() && st.back() > ch) {
                st.pop_back();
                k--;
            } 
            st.push_back(ch);
        }
        
        for (int i = 0; i < k; i ++) {
            st.pop_back();
        }
        
        int i = 0;
        while (st[i] == '0') {
            i += 1;
        }
        return (i == st.length()) ? "0" : st.substr(i, st.length() - i);
    } 
};