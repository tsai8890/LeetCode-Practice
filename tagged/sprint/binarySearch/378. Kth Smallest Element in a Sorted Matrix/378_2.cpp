#include <queue>
using namespace std;

#define vt vector

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // [val, rowId, colId]
        priority_queue<vt<int>, vt<vt<int>>, greater<vt<int>>> pq;
        
        int n = matrix.size();
        int maxRows = min(k, n);
        for (int i = 0; i < maxRows; i ++) {
            pq.push(vt<int>{matrix[i][0], i, 0});
        }

        int cnt = 0;
        while (cnt < k-1) {
            vt<int> top = pq.top();
            pq.pop();
            cnt ++;
            if (top[2] != n-1) {
                pq.push(vt<int>{matrix[top[1]][top[2]+1], top[1], top[2]+1});
            }
        }
        return pq.top().front();
    }
};