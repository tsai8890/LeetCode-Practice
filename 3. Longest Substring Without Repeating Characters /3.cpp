#include <unordered_set>
#include <string>
using namespace std;

class Solution {
    /*
        Title: 3. Longest Substring Without Repeating Characters
        Time Complexity: O(N)
        Algorithm: 
            1. Sliding Window
            2. Add Pruning
                i. When s.length() - left <= max_len, the 
                   result(max_len) will never be changed.
                   Therefore, it can break out of the loop.
        Note:
            1. It uses unordered_set, which is quite slow.
               3_fast.cpp is a better version which uses vector. 

        Date: 12/09/2021 11:37		
        Time: 28ms  -- beat 37.72%
        Memory: 10.6 MB  -- beat 30.88%
    */
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int left = 0, right = 0;
        int s_len = s.length();
        unordered_set <char> table;
                
        while (right < s_len) {
            if (table.count(s[right]) == 0) 
                table.insert(s[right++]);
            else 
                table.erase(s[left++]);
            
            max_len = max(max_len, right - left);
            
            if (s.length() - left <= max_len) 
                break;
        }
        return max_len;
    }
};