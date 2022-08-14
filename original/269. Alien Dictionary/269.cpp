#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Title: 269. Alien Dictionary
    Time Complexity: 
        1. O(n)

    Algorithm:
        1. Topological Sort
        2. DFS

    Note:
        1. 只要先確定好character之間的關係，建好圖，
           剩下的做DFS得到topological ordering即可

        2. 若有word_1, word_2, ... word_n 依序共n個word，
           只需要根據 [word_i, word_i+1] for i = 1 to n-1 
           即可找出所有規則。

    Date: 12/28/2021 02:00					
    Time: 0 ms  -- beat 100.00%
    Memory: 9.4 MB  -- beat 80.18%
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,vector<char>> graph;
        
        for (int i = 0; i < words.size(); i ++) {
            for (int j = 0; j < words[i].size(); j ++) {
                char from = words[i][j];
                if (graph.count(from) == 0) {
                    vector<char> added;
                    graph[from] = added;
                }
            }
        }
        
        for (int i = 0; i < words.size() - 1; i ++) {
            int j = 0;
            while (j < words[i].size() && j < words[i+1].size()) {
                if (words[i][j] == words[i+1][j])
                    j += 1;
                else 
                    break;
            }
            
            if (j < words[i].size() && j == words[i+1].size()) {
                return "";
                
            } else if (j == words[i].size() && j < words[i+1].size()) {
                continue;
            
            } else if (j == words[i].size() && j == words[i+1].size()) {
                continue;
                
            } else {
                char from = words[i][j], to = words[i+1][j];
                graph[from].push_back(to);
            }
        }
        
        vector<int> color(26, 0);
        vector<char> result;
        bool valid = true;
        
        for (auto item : graph) {
            char ch = item.first;
            if (color[ch - 'a'] == 0) {
                dfs(graph, ch, color, result, valid);
            }
        }
        
        if (!valid) {
            return "";
        } else {
            string res;
            while (!result.empty()) {
                res += result.back();
                result.pop_back();
            }
            return res;
        }
    }
    
    void dfs(unordered_map<char,vector<char>>& graph, char cur, 
                                vector<int>& color, vector<char>& result, bool& valid) {
        color[cur - 'a'] = 1;
        for (auto next : graph[cur]) {
            if (color[next - 'a'] == 0) {
                dfs(graph, next, color, result, valid);
                
            } else if (color[next - 'a'] == 1) {
                valid = false;
            }
        }
        
        color[cur - 'a'] = 2;
        result.push_back(cur);
    }
};