#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
    /*
        Title: 1345. Jump Game IV
        Time Complexity: 
            1. O(n)

        Algorithm:
            1. DFS

        Date: 12/28/2021 00:05						
        Time: 236 ms  -- beat 39.09%
        Memory: 70.2 MB  -- beat 49.26%
    */
class Solution {
public:
   int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> groups;
        unordered_map<int, int> group_visited;
        
        for (int i = 0; i < arr.size(); i ++) {
            if (groups.count(arr[i]) == 0) {
                vector<int> added;
                groups[arr[i]] = added;
                group_visited[arr[i]] = 0;
            }
            groups[arr[i]].push_back(i);
        }
        
        vector<int> steps(arr.size(), -1);
        queue<int> q;
        q.push(0);
        steps[0] = 0;
        
        while (!q.empty()) {
            int top = q.front();
            int cur_steps = steps[top] + 1;
            q.pop();
            
            if (top-1 >= 0 && steps[top-1] == -1) {
                steps[top-1] = cur_steps;
                q.push(top-1);
            }
            
            if (top+1 < arr.size() && steps[top+1] == -1) {
                steps[top+1] = cur_steps;
                q.push(top+1);
            }
            
            if (group_visited[arr[top]] == 0) {
                for (int i = 0; i < groups[arr[top]].size(); i ++) {
                    if (steps[groups[arr[top]][i]] == -1) {
                        steps[groups[arr[top]][i]] = cur_steps;
                        q.push(groups[arr[top]][i]);
                    }
                }
                group_visited[arr[top]] = 1;
            }
        }
        return steps.back();
    }
};