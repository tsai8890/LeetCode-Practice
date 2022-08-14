class Solution {
public:
    void dfs(int i, int& count, vector<vector<int>>& G, vector<bool>& visited, vector<bool>& limited) 
    {
        if (!visited[i] && !limited[i]) {
            visited[i] = true;
            count += 1;
            for (int& j: G[i]) {
                if (!visited[j] && !limited[j]) {
                    dfs(j, count, G, visited, limited);
                }
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> G(n+1, vector<int>());
        for (auto edge: edges) {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        
        int count = 0;
        vector<bool> visited(n+1, false);
        vector<bool> limited(n+1, false);
        for (int i: restricted) {
            limited[i] = true;
        }
        dfs(0, count, G, visited, limited);
        return count;
    }
};