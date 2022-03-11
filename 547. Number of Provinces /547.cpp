#include <vector>
using namespace std;

class Solution {
    /*
        Title: 547. Number of Provinces
        Time Complexity: O(n^2)
        Algorithm: 
            1. DFS
        
        Date: 12/24/2021 23:14								
        Time: 24 ms  -- beat 59.90%
        Memory: 14.6 MB  -- beat 15.80%
    */
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> graph(isConnected.size(), vector<int>());
        vector<int> visited(isConnected.size(), 0);
        
        for (int i = 0; i < isConnected.size(); i ++) {
            for (int j = 0; j < isConnected[i].size(); j ++) {
                if (isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                }
            }
        }
        
        int components = 0;
        for (int i = 0; i < graph.size(); i ++) {
            if (visited[i] == 0) {
                dfs(graph, i, visited);
                components += 1;
            }
        }
        return components;
    }
    
    void dfs(vector<vector<int>>& graph, int id, vector<int>& visited) {
        visited[id] = 1;
        for (int i = 0; i < graph[id].size(); i ++) {
            if (visited[graph[id][i]] == 0) {
                dfs(graph, graph[id][i], visited);
            }
        } 
    }
};