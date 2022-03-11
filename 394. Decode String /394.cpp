#include <cctype>
#include <string>
using namespace std;

class Solution {
    /*
        Title: 394. Decode String
        Time Complexity:
            1. O(|decoded result| + |encoded string|)

        Algorithm: 
            1. Recursion

        Note:
            1. 這是stack的題目，但是基本上只要能用stack，就能用recursion。
               相較於stack，recursion好寫一點，也比較簡潔。

        Date: 12/16/2021 15:37					
        Time: 0ms  -- beat 100.00%
        Memory: 6.5 MB  -- beat 77.25%
    */
public:
    string decodeString(string s) {
        int index = 0;
        return decodeString(s, index);
    }
    
    string decodeString(string s, int& index) {
        string result;
        string times_str;
        while (index < s.length() && s[index] != ']') {
            if (isalpha(s[index])) {
                result += s[index];
            
            } else if (isdigit(s[index])) {
                times_str += s[index];
            
            } else if (s[index] == '[') {
                int times = stoi(times_str);
                times_str.clear();
                index += 1;
                
                string sub_string = decodeString(s, index);
                while (times > 0) { 
                    result += sub_string;
                    times -= 1;
                }
            }
            index += 1;
        }
        return result;
    }
};