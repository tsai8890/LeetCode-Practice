#include <vector>
using namespace std;

class Solution {
    /*
        Title: 509. Fibonacci Number
        Time Complexity: O(N)
        Note:
            1. Dynamic Programming
            2. fib[i] = fib[i-1] + fib[i-2]            
        
        Date: 12/07/2021 00:28	
        Time: 0 ms  -- beat 100.00%
        Memory: 6.1 MB  -- beat 19.10%
    */
public:
    int fib(int n) {
        vector<int> fib = {0, 1};
        
        if (n < 2)
            return fib[n];
        else {
            for (int i = 2; i <= n; i ++) {
                fib.push_back(fib[i-1] + fib[i-2]);
            }
            return fib[n];
        }
    }
};