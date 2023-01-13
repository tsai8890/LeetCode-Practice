#include <vector>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) {
            return -1;
        }
        
        vector<vector<int>> graph(n, vector<int>());
        for (auto conn: connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        
        int needConn = -1;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                dfs(graph, visited, i);
                needConn += 1;
            }
        }
        return needConn;
    }
    
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int neighbor: graph[i]) {
            if (!visited[neighbor]) {
                dfs(graph, visited, neighbor);
            }
        }
    }
};