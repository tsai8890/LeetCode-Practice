#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Solution {
    /*
        Title: 224. Basic Calculator I
        Time Complexity: O(n)
        Algorithm:
            1. Stack

        Note:
            1. Calculator系列題組，全部都可以用III的架構寫
                i.   224. Basic Calculator I
                ii.  227. Basic Calculator II
                iii. 772. Basic Calculator III

        Date: 12/26/2021 01:40						
        Time: 8 ms  -- beat 85.24%
        Memory: 8.5 MB  -- beat 33.13%
    */
public:
    int calculate(string s) {
        string tmp;
        for (char c: s) {
            if (c != ' ') {
                tmp += c;
            }
        }
        s = tmp;
        
        int curPos = 0;
        return calculate(s,curPos);
    }
    
    int calculate(string& s, int& curPos) {
        vector<int> st;
        long long int curNum = 0;
        int sign = 1;
        
        while (curPos < s.length() && s[curPos] != ')') {
            if (isdigit(s[curPos])) {
                curNum = curNum*10 + s[curPos]-'0';
            
            } else if (s[curPos] == '+' || s[curPos] == '-') {
                st.push_back(sign * curNum);
                sign = (s[curPos] == '+') ? 1 : -1;
                curNum = 0;
            
            } else if (s[curPos] == '(') {
                curPos += 1;
                curNum = calculate(s, curPos);
            }
            
            curPos += 1;
        }
        st.push_back(sign * curNum);
        
        long long int result = 0;
        for (auto num: st) {
            result += num;            
        }
        return result;
    }
};