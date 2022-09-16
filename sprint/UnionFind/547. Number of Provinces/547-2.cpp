#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int total = 0;
        for (int i = 0; i < n; i ++) {
            if (visited[i] == 0) {
                dfs(isConnected, i, visited);
                total += 1;
            }
        }
        return total;
    }
    
    void dfs(vector<vector<int>>& isConnected, int i, vector<int>& visited) {
        visited[i] = 1;
        int n = isConnected.size();
        for (int j = 0; j < n; j ++) {
            if (isConnected[i][j] == 1 && visited[j] == 0) {
                dfs(isConnected, j, visited);
            }
        } 
    }
};