# Shortest Path Algorithm
## 常見的 shortest path algorithm
<img src="./overall.img">
<br>

## Floyd-Warshall Algorithm
### Template
```C++
#include <vector>
using namespace std;

vector<vector<int>> floyd(int n, vector<vector<int>>& edges) {
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
}
```
