
using namespace std;

class Solution {
    /*
        Title: 231. Power of Two
        Time Complexity: O(logn)

        Algorithm:
            1. Nothing

        Date: 12/21/2021 10:43		
        Time: 0 ms  -- beat 100.00%
        Memory: 5.7 MB  -- beat 88.36%
    */
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        
        while (n > 1) {
            if (n % 2 == 0) {
                n = n / 2;
            }
            else {
                return false;
            }
        }
        return true;
    }
};