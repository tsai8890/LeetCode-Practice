#include <string>
using namespace std;

class Solution {
    /*
        Title: 557. Reverse Words in a String III
        Time Complexity: O(N)
        Note:
            1. Two Pointer
            2. Mirroring Reverse

        Date: 12/07/2021 11:50		
        Time: 12 ms  -- beat 93.72%
        Memory: 10.2 MB  -- beat 39.60%
    */
public:
    string reverseWords(string s) {
        string res = s;
        int i = 0, j = 0;
        
        while (j < s.length()) {
            if (s[j] != ' ') {
                j += 1;
            } else {
                reverse(res, i, j-1);
                i = j + 1;
                j = j + 1;
            }
        }
        reverse(res, i, j-1);
        return res;
    }
    
    void reverse(string& s, int i, int j) {
        int left = i, right = j;
        char temp;
        
        while (left < right) {
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            left += 1;
            right -= 1;
        }
    }
};