#include <vector>
using namespace std;

/* 
    類似掃描線法，一維跟二維都可以使用，值得一記
    O(N^2 + |queries|)
*/

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n+1, vector<int>(n+1, 0));
        for (int i = 0; i < queries.size(); i ++) {
            res[queries[i][0]][queries[i][1]] ++;
            res[queries[i][2]+1][queries[i][1]] --;
            res[queries[i][0]][queries[i][3]+1] --;
            res[queries[i][2]+1][queries[i][3]+1] ++;
        }
        
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i) res[i][j] += res[i-1][j];
                if (j) res[i][j] += res[i][j-1];
                if (i && j) res[i][j] -= res[i-1][j-1];
                ans[i][j] = res[i][j];
            }
        }
        return ans;
    }
};