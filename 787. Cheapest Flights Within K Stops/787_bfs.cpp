#include <vector>
#include <queue>
using namespace std;

#define NOT_TRIED_YET -1

/*
    Title: 787. Cheapest Flights Within K Stops
    Time Complexity: O(Kx(V+E))
    Space Complexity: O(V+E)-extra space

    Algorithm: 
        1. Breadth-First Search
        
    Note:
        1. 這種「限制k步內，計算最短路徑」的題目，也可以用階層式的BFS來做，
           效率會比top-down DP來得好(時間複雜度一樣，但是recursion會多花一點時間call stack)，
           可以記一下，實作上也比較容易。

    Date: 05/11/2022 20:32											
    Time: 28 ms  -- beat 85.47%
    Memory: 15.4 MB  -- beat 31.64%
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> edges(n, vector<vector<int>>());
        for (int i = 0; i < flights.size(); i ++) {
            int from = flights[i][0];
            int to = flights[i][1];
            int price = flights[i][2];
            vector<int> add_edge = {to, price};
            edges[from].push_back(add_edge);
        }
        
        vector<int> memo(n, NOT_TRIED_YET);
        memo[src] = 0;
        
        queue<vector<int>> bfsq;
        bfsq.push(vector<int>{src, 0});
        
        int i = 0;
        while (i <= k && !bfsq.empty()) {
            int n = bfsq.size();
            for (int j = 0; j < n; j ++) {
                vector<int> top = bfsq.front();
                int curNode = top[0];
                int curCost = top[1];
                bfsq.pop();
                
                for (int l = 0; l < edges[curNode].size(); l ++) {
                    int nextNode = edges[curNode][l][0];
                    int edgeCost = edges[curNode][l][1];
                    if (memo[nextNode] == NOT_TRIED_YET || curCost + edgeCost < memo[nextNode]) {
                        memo[nextNode] = curCost + edgeCost;
                        bfsq.push(vector<int>{nextNode, memo[nextNode]});
                    }
                }
            }
            i += 1;
        }
        
        return memo[dst];
    }
};