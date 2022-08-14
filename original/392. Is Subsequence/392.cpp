#include <iostream>
#include <string>
using namespace std;

/*
    Title: 392. Is Subsequence
    Time Complexity: O(n)
    Space Complexity: O(1)-extra space

    Algorithm: 
        1. Brute Force + Greedy
        
    Date: 03/26/2022 22:21					
    Time: 0 ms  -- beat 100.00%
    Memory: 6.4 MB  -- beat 25.06%
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0)
            return true;
        
        int ptr = 0;
        for (int i = 0; i < t.length(); i ++) {
            if (s[ptr] == t[i]) {
                ptr += 1;
                if (ptr == s.length()) {
                    return true;
                }
            }
        }
        return false;
    }
};