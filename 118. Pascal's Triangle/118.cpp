#include <vector>
using namespace std;

/*
    Title: 118. Pascal's Triangle
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)

    Algorithm:
        1. Dynamic Programming

    Note: 
        1. 帕斯卡三角形，穩的

    Date: 02/01/2022 23:24							
    Time: 0 ms  -- beat 100.00%
    Memory: 6.6 MB  -- beat 33.54%
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows, vector<int>());
        triangle[0].push_back(1);
        
        for (int i = 1; i < numRows; i ++) {
            for (int j = 0; j <= i; j ++) {
                if (j == 0 || j == i) {
                    triangle[i].push_back(1);
                }
                else {
                    triangle[i].push_back(triangle[i-1][j-1]+triangle[i-1][j]); 
                }
            }
        }
        return triangle;
    }
};