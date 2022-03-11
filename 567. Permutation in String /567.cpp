#include <string>
#include <vector>

using namespace std;

class Solution {
    /*
        Title: 567. Permutation in String
        Time Complexity: O(N)
        Algorithm: 
            1. Sliding Window
            
        Note:
            1. Initialize 'table' with s1's all characters.
            2. Update the status of the window into 'table'.
            3. Use 'remain' to determine whether the window is valid.
                i. 'remain' = sum of all the positive values in 'table'.
                ii. 'remain' == 0   : valid
                     otherwise,     : invalid

        Date: 12/09/2021 12:26			
        Time: 6ms  -- beat 81.95%
        Memory: 7.1 MB  -- beat 98.48%
    */
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length())
            return false;
        
        vector<int> table(26, 0);
        for (int i = 0; i < s1.length(); i ++) {
            table[s1[i] - 'a'] += 1;
        }
        
        int remain = s1.length();
        for (int i = 0; i < s1.length(); i ++) {
            if (table[s2[i] - 'a'] > 0) 
                remain -= 1;
            table[s2[i] - 'a'] -= 1;
        }
        if (remain == 0)
            return true;
        
        for (int i = s1.length(); i < s2.length(); i ++) {
            int remove = i - s1.length();
            if (table[s2[remove] - 'a'] >= 0) {
                remain += 1;
            }
            table[s2[remove] - 'a'] += 1;
            
            if (table[s2[i] - 'a'] > 0) {
                remain -= 1;
            }
            table[s2[i] - 'a'] -= 1;
            
            if (remain == 0)
                return true;
        }
        return false;
    }
};