using namespace std;

/*
    Title: 1009. Complement of Base 10 Integer
    Time Complexity: 
        1. O(logn)

    Algorithm:
        1. None

    Note:
        1. 複習bit operation

    Date: 12/28/2021 00:35				
    Time: 0 ms  -- beat 100.00%
    Memory: 5.9 MB  -- beat 75.27%
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        
        int result = 0;
        int cur_bit = 0;
        
        while (n > 0) {
            result += (1 - n&1) << cur_bit;
            n = n >> 1;
            cur_bit += 1;
        }
        return result;
    }
};