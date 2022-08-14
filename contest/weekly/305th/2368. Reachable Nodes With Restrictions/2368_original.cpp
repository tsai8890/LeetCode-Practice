class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> G(n+1, vector<int>());
        for (auto edge: edges) {
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> limit(n+1, false);
        for (int i: restricted) {
            limit[i] = true;
        }
        
        if (limit[0]) {
            return 0;
        }
        
        vector<bool> visited(n+1, false);
        queue<int> q;
        int count = 0;

        q.push(0);
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (int neighbor: G[top]) {
                if (!limit[neighbor] && !visited[neighbor]) {
                    q.push(neighbor);
                }
            }
            visited[top] = true;
            count++;
        }
        return count;
    }
};