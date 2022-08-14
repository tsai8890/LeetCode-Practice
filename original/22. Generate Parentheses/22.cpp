#include <vector>
#include <string>
using namespace std;

class Solution {
    /*
    Title: 22. Generate Parentheses
    Time Complexity: O(2xNx2^(2N))
    Algorithm: 
        1. Brutal Force(Recursion)
    
    Date: 12/03/2021 13:23		
    Time: 60 ms  -- beat 5.21%
    Memory: 60 MB  -- beat 5.03%
    */
public:
    bool valid(string S) {
        int bal = 0;
        for (int i = 0; i < S.length(); i ++) {
            if (S[i] == '(') 
                bal += 1;
            else if (S[i] == ')')
                bal -= 1;
            
            if (bal < 0)
                return false;
        }
        return (bal == 0);
    }
    
    void recursion(vector<string>& ans, string S, int n) {
        if (S.length() == 2 * n) {
            if (valid(S)) 
                ans.push_back(S);
            return; 
        } 
        recursion(ans, S + "(", n);
        recursion(ans, S + ")", n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recursion(ans, "", n);
        return ans;
    }
};