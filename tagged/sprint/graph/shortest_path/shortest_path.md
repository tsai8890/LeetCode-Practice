# Shortest Path Algorithm
## 常見的 shortest path algorithm
<html>
<body>
    <table style="text-align: center">
        <thead>
            <tr>
                <th>演算法</th>
                <th>應用場景</th>
                <th>限制條件</th>
                <th>時間複雜度</th>
                <th>空間複雜度</th>
            </tr>
        </thead>
        <tbody style="text-align: center">
            <tr>
                <td>Dijkstra's Algorithm</td>
                <td>Single Source Shortest Path</td>
                <td>無負邊</td>
                <td>O((V+E)logE)</td>
                <td>O(E)</td>
            </tr>
            <tr>
                <td>Bellman-Ford Algorithm</td>
                <td>Single Source Shortest Path</td>
                <td>無負環(可以檢查出來)</td>
                <td>O(VE)</td>
                <td>O(V)</td>
            </tr>
            <tr>
                <td>Floyd Warshall's Algorithm</td>
                <td>Multiple Source Shortest Path</td>
                <td>無負環</td>
                <td>O(V^3)</td>
                <td>O(V^2)</td>
            </tr>
        </tbody>
    </table>
</body>
</html>

<br>

## 常見的縮寫
- SSSP: Single-Source Shortest Path
- MSSP: Multiple-Source Shortest Path

<br>

## Fundamentals
1. Path Relaxation Property
2. Convergence Property

> Reference
> [Fundamentals](http://alrightchiu.github.io/SecondRound/shortest-pathintrojian-jie.html)

<br>

## Dijkstra's Algorithm
### Feature
1. 是最快的 SSSP 演算法
2. 限制條件是「圖上沒有負邊」
3. 可以紀錄 parent 來回溯路徑

<br>

## Bellman-Ford Algorithm
### Feature
1. 是一個 SSSP 演算法
2. 時間複雜度稍差一點，但是也有 O(VE)
3. 非常 robust，基本上沒有限制條件
4. 可以檢查負環
4. 可以紀錄 parent 來回溯路徑

### 核心概念
- 迴圈跑 |V-1| 次，每次都把所有 edge relax 一次。
    對任何一條路徑來說，因為圖上沒有環，所以最多只會由 |V-1| 個 edge 組成。
    我們把 |V-1| x |E| 的所有 relaxation 攤開來看，會發現任何一條路徑
    的所有 edge，一定有被按照「起點至終點」的順序 relax 一次。
    而根據 Path Relaxation Property，我們可以知道每條路徑都會是最短路徑

- 檢查負環
    - 前面有提到，若整張圖沒有負環(即代表從 starting vertex 至圖上任何一點
      一定有 shortest path/不通)，而事實上 path-relaxation property 也
      是運用到這點才能證明出來。
      
      所以，"如果經過 |V-1| 次迴圈，還有邊可以被 relax，那就說明整張圖有出現負環。"
    
    - 因此，檢查方法就是再跑一個 |E| 次的迴圈，檢查每條邊是否還可以被 relax，
      如果有任何一條邊可以被 relax，代表有負環。

### Template
```C++
// Undirected Graph Version
vector<int> bellman_ford(int n, vector<vector<int>>& edges, int start) {
    vector<int> dis(n, 10000000);
    dis[start] = 0;
    for (int i = 0; i < n-1; i ++) {
        for (auto& edge: edges) {
            if (dis[edge[0]] + edge[2] < dis[edge[1]]) {
                dis[edge[1]] = dis[edge[0]] + edge[2];
            }
            if (dis[edge[1]] + edge[2] < dis[edge[0]]) {
                dis[edge[0]] = dis[edge[1]] + edge[2];
            }
        }
    }

    // Detect Negative Cycles
    bool negCycle = false;
    for (auto& edge: edges) {
        if (dis[edge[0]] + edge[2] < dis[edge[1]]) {
            negCycle = true;
        }
        if (dis[edge[1]] + edge[2] < dis[edge[0]]) {
            negCycle = true;
        }
    }

    return dis;
}

// Directed Graph Version
vector<int> bellman_ford(int n, vector<vector<int>>& edges, int start) {
    vector<int> dis(n, 10000000);
    dis[start] = 0;
    for (int i = 0; i < n-1; i ++) {
        for (auto& edge: edges) {
            if (dis[edge[0]] + edge[2] < dis[edge[1]]) {
                dis[edge[1]] = dis[edge[0]] + edge[2];
            }
        }
    }

    // Detect Negative Cycles
    bool negCycle = false;
    for (auto& edge: edges) {
        if (dis[edge[0]] + edge[2] < dis[edge[1]]) {
            negCycle = true;
        }
    }

    return dis;
}
```

<br>

## Floyd-Warshall Algorithm
### Feature
1. 是一個 MSSP 演算法
2. 限制條件是「沒有負環」
3. 無法得到最短路徑，只能得到最短距離

### Template
```C++
#include <vector>
using namespace std;

vector<vector<int>> floyd(int n, vector<vector<int>>& edges) {
    vector<vector<int>> G(n, vector<int>(n, 1000000));
    
    // Undirected Graph
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

<br>

## Reference
> [Shortest-Path Fundamental](http://alrightchiu.github.io/SecondRound/shortest-pathintrojian-jie.html)
> [Floyd-Warshall](https://yuihuang.com/floyd-warshall-algorithm/)
> [Bellman-Ford](http://alrightchiu.github.io/SecondRound/single-source-shortest-pathbellman-ford-algorithm.html#bf)
> [Dijkstra's](http://alrightchiu.github.io/SecondRound/single-source-shortest-pathdijkstras-algorithm.html)
