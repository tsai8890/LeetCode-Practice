#include <vector>
#include <queue>
using namespace std;

class Solution {
    /*
        Title: 310. Minimum Height Trees
        Time Complexity: O(|V| + |E|)
        Algorithm: 
            1. Leaves-Removing with BFS
        
        Note:
            1. "Find the root constructing the minimum height tree"
               => "Find the middle point of the longest edge"
            
            2. Using leaves-removing with BFS, which is a much 
               more simple method than finding the longest path with DFS/BFS.
               And in the interviews, using this method is much more safe.

        Date: 12/24/2021 08:17						
        Time: 124 ms  -- beat 26.09%
        Memory: 47.3 MB  -- beat 5.24%
    */
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            vector<int> zero = {0};
            return zero;
        }
        
        vector<vector<int>> graph(n, vector<int>());
        vector<int> degree(n, 0);
        vector<int> remove_level(n, -1);
        
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]] += 1;
            degree[edge[1]] += 1;
        }
        
        queue<int> node_q;
        for (int i = 0; i < n; i ++) {
            if (degree[i] == 1) {
                node_q.push(i);
                remove_level[i] = 0;
            }
        }
        
        int max_level = 0;
        while (!node_q.empty()) {
            int leaf = node_q.front();
            node_q.pop();
            for (int i = 0; i < graph[leaf].size(); i ++) {
                if (remove_level[graph[leaf][i]] == -1) {
                    degree[graph[leaf][i]] -= 1;
                    if (degree[graph[leaf][i]] == 1) {
                        remove_level[graph[leaf][i]] = remove_level[leaf] + 1;
                        max_level = max(max_level, remove_level[graph[leaf][i]]);
                        node_q.push(graph[leaf][i]);
                    }
                } 
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; i ++) {
            if (remove_level[i] == max_level) {
                result.push_back(i);
            }
        }
        return result;        
    }
};