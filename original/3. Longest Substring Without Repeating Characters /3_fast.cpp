#include <vector>
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
            1. It uses vector instead of unordered_set, which is
               much faster than the latter.

        Date: 12/09/2021 11:47	
        Time: 3ms  -- beat 97.27%
        Memory: 7.6 MB  -- beat 82.90%
    */
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int s_len = s.length();
        int left = 0, right = 0;
        vector<int> table(128, 0);
        
        while (right < s_len) {
            if (table[s[right]] == 0) 
                table[s[right++]] = 1;
            else
                table[s[left++]] -= 1;
            
            max_len = max(max_len, right - left);
            
            if (s.length() - left <= max_len) 
                break;
        }
        return max_len;
    }
};