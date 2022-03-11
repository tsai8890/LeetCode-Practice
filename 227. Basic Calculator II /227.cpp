#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Solution {
    /*
        Title: 227. Basic Calculator II
        Time Complexity: O(n)
        Algorithm:
            1. Stack

        Note:
            1. Calculator系列題組，全部都可以用III的架構寫
                i.   224. Basic Calculator I
                ii.  227. Basic Calculator II
                iii. 777. Basic Calculator III
                
        Date: 12/26/2021 02:06							
        Time: 4 ms  -- beat 98.87%
        Memory: 9.5 MB  -- beat 10.07%
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
        char last_op = '+';
        int sign = 1; 
        
        while (curPos < s.length() && s[curPos] != ')') {
            if (s[curPos] == '(') {
                curPos += 1;
                curNum = calculate(s, curPos);
            
            } else if (isdigit(s[curPos])) {
                curNum = curNum*10 + s[curPos]-'0';
            
            } else if (s[curPos] == '+' || s[curPos] == '-' || s[curPos] == '*' || s[curPos] == '/') {
                if (last_op == '+' || last_op == '-') {
                    st.push_back(sign * curNum);
                
                } else {
                    long long int top = st.back();
                    st.pop_back();

                    if (last_op == '*') {
                        st.push_back(top * curNum);
                    } else {
                        st.push_back(top / curNum);
                    }
                }

                last_op = s[curPos];
                sign = (s[curPos] != '-') ? 1 : -1;
                curNum = 0;
            }
            
            curPos += 1;
        }

        if (last_op == '+' || last_op == '-') {
            st.push_back(sign * curNum);
        
        } else {
            long long int top = st.back();
            st.pop_back();

            if (last_op == '*') {
                st.push_back(top * curNum);
            } else {
                st.push_back(top / curNum);
            }
        }
        
        long long int result = 0;
        for (auto num: st) {
            result += num;            
        }
        return result;
    }
};