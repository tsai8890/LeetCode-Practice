#include <vector>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> G(n, vector<int>(n, 1000000));
        for (auto& edge: edges) {
            G[edge[0]][edge[1]] = edge[2];
            G[edge[1]][edge[0]] = edge[2];
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                for (int k = 0; k < n; k ++) {
                    if (G[j][i] + G[i][k] < G[j][k]) {
                        G[j][k] = G[j][i] + G[i][k];
                    }
                }
            }
        }
        
        int minId = -1, minCount;
        for (int i = 0; i < n; i ++) {
            int count = 0;
            for (int j = 0; j < n; j ++) {
                if (i != j && G[i][j] <= distanceThreshold) {
                    count += 1;
                }
            }
            if (minId == -1 || count <= minCount) {
                minId = i;
                minCount = count;
            }
        }
        return minId;
    }
};