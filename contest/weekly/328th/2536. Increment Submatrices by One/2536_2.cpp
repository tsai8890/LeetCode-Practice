#include <vector>
using namespace std;

/* 
    比較直觀，但複雜度較差的寫法，也是掃描線法
    O(N^2 + N*|queries|)
*/

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < queries.size(); i ++) {
            for (int j = queries[i][0]; j <= queries[i][2]; j ++) {
                res[j][queries[i][1]] ++;
                if (queries[i][3] < n-1) {
                    res[j][queries[i][3]+1] --;
                }
            }
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 1; j < n; j ++) {
                res[i][j] += res[i][j-1];
            }
        }
        return res;
    }
};