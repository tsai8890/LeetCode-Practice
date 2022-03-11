#include <vector>
#include <string>
using namespace std;

class Solution {
    /*
    Title: 22. Generate Parentheses
    Time Complexity: O(4^N)
    Algorithm: 
        1. Brutal Force(Recursion)
        2. Pruning
            i. Keep the current S valid, so there is no need
               to check its validness when S.length() == 2xn.
            
            ii. Save a few time wasting on recursing for the 
                invalid S.
    
    Date: 12/03/2021 13:49			
    Time: 0 ms  -- beat 100.00%
    Memory: 13.5 MB  -- beat 69.94%
    */
public:
    void recursion(vector<string>& ans, string S, int l, int r, int n) {
        if (S.length() == 2 * n) {
            ans.push_back(S);
            return; 
        } 
        
        if (l < n)
            recursion(ans, S + "(", l+1, r, n);
        
        if (l > r) 
            recursion(ans, S + ")", l, r+1, n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recursion(ans, "", 0, 0, n);
        return ans;
    }
};