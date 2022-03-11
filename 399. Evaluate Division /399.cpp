#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    /*
        Title: 399. Evaluate Division
        Time Complexity: O(n^2)
        Algorithm: 
            1. DFS
        
        Note:
            1. Use unordered map to map each node's string name
               to its node id.
        
        Date: 12/24/2021 22:51							
        Time: 0 ms  -- beat 100.00%
        Memory: 8.3 MB  -- beat 58.91%
    */
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> node_id;
        int node_count = 0;
        for (auto equation: equations) {
            if (node_id.count(equation[0]) == 0) {
                node_id[equation[0]] = node_count++;
            }
            if (node_id.count(equation[1]) == 0) {
                node_id[equation[1]] = node_count++;
            }
        }
        
        vector<vector<pair<int,double>>> graph(node_count, vector<pair<int,double>>());
        for (int i = 0; i < equations.size(); i ++) {
            auto equation = equations[i];
            int id1 = node_id[equation[0]];
            int id2 = node_id[equation[1]];
            graph[id1].push_back(make_pair(id2, values[i]));
            graph[id2].push_back(make_pair(id1, 1 / values[i]));
        }
        
        vector<int> visited(node_count, 0);
        vector<double> queries_result;
        double result;
        
        for (int i = 0; i < queries.size(); i ++) {
            result = -1;
            string start = queries[i][0];
            string target = queries[i][1];
            if (node_id.count(start) == 1 && node_id.count(target) == 1) {
                dfs(graph, visited, node_id[start], node_id[target], 1, result);
            } 
            queries_result.push_back(result);
        }
        return queries_result;
    }
    
    void dfs(vector<vector<pair<int,double>>>& graph, vector<int>& visited, 
                                int id, int target, double product, double& result) {
        if (id == target) {
            result = product;
            return;
        }
        
        visited[id] = 1;
        for (int i = 0; i < graph[id].size(); i ++) {
            pair<int,double> edge = graph[id][i];
            if (visited[edge.first] == 0)
                dfs(graph, visited, edge.first, target, product * edge.second, result);
        }
        visited[id] = 0;
    }
};