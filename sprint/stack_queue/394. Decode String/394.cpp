#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res;
        for (char ch: s) {
            if (ch != ']') {
                res.push_back(ch);
            }
            else {
                string token = "";
                while (res.back() != '[') {
                    token += res.back();
                    res.pop_back();
                }
                reverse(token.begin(), token.end());
                res.pop_back();
                
                string numStr;
                while (!res.empty() && isdigit(res.back())) {
                    numStr += res.back();
                    res.pop_back();
                }
                reverse(numStr.begin(), numStr.end());
                
                int num = stoi(numStr);
                for (int i = 0; i < num; i ++) {
                    res += token;
                }
            }
        }
        return res;
    }
};