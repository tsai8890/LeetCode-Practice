using namespace std;
    /*
        Title: 476. Number Complement
        Time Complexity: 
            1. O(logn)

        Algorithm:
            1. None

        Note:
            1. 複習bit operation

        Date: 12/28/2021 00:22				
        Time: 0 ms  -- beat 100.00%
        Memory: 5.8 MB  -- beat 96.51%
    */
class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int cur_bit = 0;
        
        while (num > 0) {
            result += (1 - (num & 1)) << cur_bit;
            num = num >> 1;
            cur_bit += 1;
        }
        return result;
    }
};