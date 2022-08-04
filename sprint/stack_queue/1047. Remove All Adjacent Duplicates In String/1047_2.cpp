#include <string>
#include <stack>
using namespace std;

class Solution {
public: 
    string removeDuplicates(string s) {
        string res;
        for (char ch: s) {
            if (res.empty() || res.back() != ch) {
                res.push_back(ch);
            }
            else {
                res.pop_back();
            }
        }
        return res;
    }
};