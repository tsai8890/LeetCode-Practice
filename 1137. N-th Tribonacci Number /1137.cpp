#include <vector>
using namespace std;

class Solution {
    /*
        Title: 1137. N-th Tribonacci Number
        Time Complexity: O(N)
        Note:
            1. Dynamic Programming
            2. fib[i] = fib[i-1] + fib[i-2] + fib[i-3]           
        
        Date: 12/07/2021 00:31	
        Time: 0 ms  -- beat 100.00%
        Memory: 6 MB  -- beat 26.27%
    */
public:
    int tribonacci(int n) {
        vector<int> tri = {0, 1, 1};
        
        if (n < 3)
            return tri[n];
        else {
            for (int i = 3; i <= n; i ++) {
                tri.push_back(tri[i-1] + tri[i-2] + tri[i-3]);
            }
            return tri[n];
        }
    }
};