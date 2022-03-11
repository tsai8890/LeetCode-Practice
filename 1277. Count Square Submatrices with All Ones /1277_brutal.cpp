#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    /*
        Title: 1277. Count Square Submatrices with All Ones
        Time Complexity:
            1. O(N^3xM)

        Algorithm: 
            1. Brutal Force

        Submission: TLE
    */
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int small = min(m, n);
        
        int count = 0;
        for (int i = 1; i <= small; i ++) {
            for (int j = 0; j <= m - i; j ++) {
                for (int k = 0; k <= n - i; k ++) {
                    int flag = 1;
                    for (int row = j; row < j + i; row ++) {
                        for (int col = k; col < k + i; col ++) {
                            if (matrix[row][col] == 0) {
                                flag = 0;
                                break;
                            }
                        }
                    }
                    
                    if (flag) 
                        count += 1;
                }
            }
        }
        
        return count;
    }
};