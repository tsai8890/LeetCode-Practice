#include <vector>
using namespace std;

/*
    Title: 304. Range Sum Query 2D - Immutable
    Time Complexity: 
        - Initialization: O(mxn)
        - sumRegion(): O(1)
        
    Space Complexity: O(mxn)

    Algorithm:
        1. Dynamic Programming

    Note: 
        1. 和LeetCode 1314. Matrix Block Sum 幾乎一樣，prefix_sum[i][j]是記
           matrix[0..i, 0..j]的元素總和，也就是二維的前綴和。

    Date: 02/04/2022 13:46									
    Time: 372 ms  -- beat 90.34%
    Memory: 148.1 MB  -- beat 48.53%
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        prefix_sum = vector<vector<int>>(m, vector<int>(n));
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == 0 && j == 0) {
                    prefix_sum[i][j] = matrix[i][j];
                }
                else if (i == 0 && j != 0) {
                    prefix_sum[i][j] = matrix[i][j] + prefix_sum[i][j-1];
                }
                else if (i != 0 && j == 0) {
                    prefix_sum[i][j] = matrix[i][j] + prefix_sum[i-1][j];
                }
                else {
                    prefix_sum[i][j] = matrix[i][j] + prefix_sum[i-1][j]
                                     + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
            return prefix_sum[row2][col2];
        }
        else if (row1 == 0 && col1 != 0) {
            return prefix_sum[row2][col2] - prefix_sum[row2][col1-1];
        }
        else if (row1 != 0 && col1 == 0) {
            return prefix_sum[row2][col2] - prefix_sum[row1-1][col2];
        }
        else {
            return prefix_sum[row2][col2] - prefix_sum[row2][col1-1]
                 - prefix_sum[row1-1][col2] + prefix_sum[row1-1][col1-1]; 
        }
    }

private:
    int m, n;
    vector<vector<int>> prefix_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */