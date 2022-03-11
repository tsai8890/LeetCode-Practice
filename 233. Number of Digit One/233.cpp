using namespace std;

/*
    Title: 233. Number of Digit One
    Time Complexity: 
        1. O(logn)

    Algorithm:
        1. Mathematical method

    Note:
        1. 數學題
        2. k從0開始，
           若第k位數 == 0:
              第k位數1的出現次數 = (n % 10^(k+1)) * 10^k 

           若第k位數 == 1:
              第k位數1的出現次數 = ((n % 10^(k+1)) * 10^k) + (n % 10^k) + 1

           若第k位數 > 1:
              第k位數1的出現次數 = ((n % 10^(k+1)) * 10^k) + 10^k
           
    Date: 12/28/2021 15:10							
    Time: 0 ms  -- beat 100.00%
    Memory: 5.8 MB  -- beat 81.82%
*/

class Solution {
public:
    int countDigitOne(int n) {
        long long int base_10 = 1;
        long long int high_10 = 10;
        int result = 0;
        
        while (base_10 <= n) {
            result += (n / high_10) * base_10; 
            
            if ((n % high_10) / base_10 > 1) {
                result += base_10;
            
            } else if ((n % high_10) / base_10 == 1) {
                result += n % base_10 + 1;
            }
            
            base_10 *= 10;
            high_10 *= 10;
        }
        return result;
    }
};