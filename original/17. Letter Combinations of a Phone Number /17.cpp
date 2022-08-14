#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, string> dict = {
    {'2', "abc"}, 
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"}, 
    {'9', "wxyz"}
};

class Solution {
    /*
        Title: 17. Letter Combinations of a Phone Number
        Time Complexity: O(3^4)
        Algorithm: 
            1. Recursion
                        
        Date: 12/03/2021 14:16	
        Time: 0 ms  -- beat 100.00%
        Memory: 6.5 MB  -- beat 86.83%
    */
public:
    void recursion(vector<string>& res, string S, string digits) {
        if (S.length() == digits.length()) {
            res.push_back(S);
            return;
        }
        
        string cur_set = dict[digits[S.length()]];
        for (int i = 0; i < cur_set.size(); i ++) {
            recursion(res, S + cur_set[i], digits);
        }
    }
        
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0)
            return res;
        
        recursion(res, "", digits);
        return res;
    }
};