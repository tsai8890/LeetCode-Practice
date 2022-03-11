#include <vector>
using namespace std;

class Solution {
    /*
        Title: 1462. Course Schedule IV
        Time Complexity: O(n^3)
        Algorithm:
            1. Dynamic Programming 
            2. DFS
        
        Note:
            1. DP常常會在意想不到的地方用到...
            
        Date: 12/25/2021 19:11						
        Time: 176 ms  -- beat 83.16%
        Memory: 61.8 MB  -- beat 72.41%
    */
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto& edge: prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        vector<vector<int>> dp(numCourses,vector<int>(numCourses,-1));
        vector<int> visited(numCourses, 0);
        vector<bool> answer;
        for (auto& query: queries) {
            answer.push_back(dfs(graph, query[0], query[1], visited, dp));
        }
        return answer;
    }
    
    bool dfs(vector<vector<int>>& graph, int vertex_id, 
                            int& target, vector<int>& visited, vector<vector<int>>& dp) {
        if (dp[vertex_id][target] != -1) {
            return (dp[vertex_id][target] == 1);
        }
        
        bool found = false;
        if (vertex_id == target) {
            found = true;
        } else {
            visited[vertex_id] = 1;
            for (auto neighbor: graph[vertex_id]) {
                if (visited[neighbor] == 0 && dfs(graph, neighbor, target, visited, dp)) {
                    found = true;
                    break;
                }
            }
            visited[vertex_id] = 0;
        }
        
        dp[vertex_id][target] = found;
        return found;
    }
};