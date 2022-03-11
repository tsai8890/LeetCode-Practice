#include <string>
#include <cctype>
using namespace std;

class Solution {
    /*
        Title: 227. Basic Calculator II
        Time Complexity: O(n)
        Algorithm:
            1. Naive method
        Note:
            1. 邏輯是對的，但是有更優雅的寫法。

        Date: 12/25/2021 23:31						
        Time: 3 ms  -- beat 99.31%
        Memory: 8.2 MB  -- beat 63.93%
    */
public:
    int calculate(string s) {
        string tmp;
        for (auto c : s) {
            if (c != ' ') {
                tmp += c;
            }
        }
        s = tmp;
        
        long long int result = 0;
        long long int cur_num = 0;
        char last_sign = '+';
        int i = 0;

        while (i < s.length()) {
            if (isdigit(s[i])) {
                cur_num = cur_num * 10 + s[i] - '0';
                i += 1;
            
            } else if (s[i] == '+' || s[i] == '-') {
                if (last_sign == '+') 
                    result += cur_num;
                else 
                    result -= cur_num;

                cur_num = 0;
                last_sign = s[i];
                i += 1;
                
            } else if (s[i] == '*' || s[i] == '/') {
                do {
                    char last_product_sign = s[i];
                    long long int next_num = 0;
                    i = i + 1;
                    while (i < s.length() && isdigit(s[i])) {
                        next_num = next_num * 10 + s[i] - '0';
                        i = i + 1;
                    }
                    
                    if (last_product_sign == '*') {
                        cur_num = cur_num * next_num;
                    } else {
                        cur_num = cur_num / next_num;
                    }
                } while (i < s.length() && (s[i] == '*' || s[i] == '/'));
            }
        }
        
        if (last_sign == '+') 
            result += cur_num;
        else 
            result -= cur_num;
        
        return result;
    }
};