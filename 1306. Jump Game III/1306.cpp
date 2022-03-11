#include <vector>
using namespace std;
    /*
        Title: 1306. Jump Game III
        Time Complexity: 
            1. O(n)

        Algorithm:
            1. DFS

        Date: 12/27/2021 23:59							
        Time: 40 ms  -- beat 75.75%
        Memory: 35.2 MB  -- beat 32.81%
    */
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), 0);
        return dfs(arr, start, visited);
    }
    
    bool dfs(vector<int>& arr, int id, vector<int>& visited) {
        visited[id] = 1;
        if (arr[id] == 0) {
            return true;
        }
        
        bool result = false;
        if (0 <= id+arr[id] && id+arr[id] < arr.size() && !visited[id+arr[id]]) {
            result = result || dfs(arr, id+arr[id], visited);
        }
        if (0 <= id-arr[id] && id-arr[id] < arr.size() && !visited[id-arr[id]]) {
            result = result || dfs(arr, id-arr[id], visited);
        }
        return result;
    }
};