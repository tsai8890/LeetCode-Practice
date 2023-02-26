#include <vector>
using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> pos(m+1);
        for (int i = 1; i <= m; i ++) {
            pos[i] = i-1;
        }

        int qSize = queries.size();
        vector<int> res(qSize);
        for (int i = 0; i < qSize; i ++) {
            res[i] = pos[queries[i]];
            for (int j = 1; j <= m; j ++) {
                if (pos[j] < pos[queries[i]]) {
                    pos[j] ++;
                }
            }
            pos[queries[i]] = 0;
        }
        return res;
    }
};