#include <vector>
using namespace std;

/*
    Title: 119. Pascal's Triangle II
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
        - 如果只記前一列，可以縮減到O(n)

    Algorithm:
        1. Dynamic Programming

    Note: 
        1. 帕斯卡三角形，穩的啦

    Date: 02/01/2022 23:35							
    Time: 0 ms  -- beat 100.00%
    Memory: 6.7 MB  -- beat 18.36%
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle(rowIndex+1, vector<int>());
        triangle[0].push_back(1);
        
        for (int i = 1; i <= rowIndex; i ++) {
            for (int j = 0; j <= i; j ++) {
                if (j == 0 || j == i) {
                    triangle[i].push_back(1);
                }
                else {
                    triangle[i].push_back(triangle[i-1][j-1]+triangle[i-1][j]); 
                }
            }
        }
        return triangle.back();
    }
};