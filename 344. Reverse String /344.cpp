#include <vector>
using namespace std;

class Solution {
    /*
        Title: 344. Reverse String
        Time Complexity: O(N)
        Note:
            1. Two Pointer
            2. Mirroring Reverse

        Date: 12/07/2021 11:39	
        Time: 12 ms  -- beat 99.15%
        Memory: 23.3 MB  -- beat 40.05%
    */
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
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