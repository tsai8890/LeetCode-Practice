#include <vector>
using namespace std;

class Solution {
    /*
        Title: 851. Loud and Rich

        Time Complexity: O(|V| + |E|)
        Algorithm: 
            1. DFS
        
        Date: 12/24/2021 16:35						
        Time: 108 ms  -- beat 44.58%
        Memory: 47 MB  -- beat 24.36%
    */
public:
    int dfs(int i, vector<vector<int>>& graph, vector<int>& quiet, 
                        vector<int>& visited, vector<int>& answer) {
        visited[i] = 1;
        int min_person = i;
        int cur_min_person;
        
        for (int j = 0; j < graph[i].size(); j ++) {
            if (visited[graph[i][j]] == 0) {
                cur_min_person = dfs(graph[i][j], graph, quiet, visited, answer);
                if (quiet[cur_min_person] < quiet[min_person]) {
                    min_person = cur_min_person;
                }
            } else {
                if (quiet[answer[graph[i][j]]] < quiet[min_person]) {
                    min_person = answer[graph[i][j]];
                }
            }
        }
        answer[i] = min_person;
        return min_person;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> graph(quiet.size(), vector<int>());
        for (auto edge : richer) {
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> visited(quiet.size(), 0);
        vector<int> answer(quiet.size());
        for (int i = 0; i < quiet.size(); i ++) {
            if (visited[i] == 0) {
                dfs(i, graph, quiet, visited, answer);
            }
        }
        return answer;
    }
};