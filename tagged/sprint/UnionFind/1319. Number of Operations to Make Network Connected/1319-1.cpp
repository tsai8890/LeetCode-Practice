#include <vector>
#include <unordered_set>
using namespace std;

struct node {
    int parent;
    int height;
};

class Solution {
public:
    int find(vector<node>& djs, int i) {
        if (djs[i].parent != i) {
            djs[i].parent = find(djs, djs[i].parent);
        }
        return djs[i].parent;
    }
    
    void Union(vector<node>& djs, int i, int j) {
        int set_i = find(djs, i);
        int set_j = find(djs, j);
        if (set_i == set_j) return;
        
        if (djs[set_i].height >= djs[set_j].height) {
            djs[set_j].parent = set_i;
            if (djs[set_i].height == djs[set_j].height) {
                djs[set_i].height += 1;
            }
        }
        else {
            djs[set_i].parent = set_j;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) {
            return -1;
        }
        
        vector<vector<int>> graph(n, vector<int>());
        for (auto conn: connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        
        vector<node> djs(n);
        for (int i = 0; i < n; i ++) {
            djs[i].parent = i;
            djs[i].height = 1;
        }
        
        for (int i = 0; i < n; i ++) {
            for (int neighbor: graph[i]) {
                Union(djs, i, neighbor);
            }
        }
        
        unordered_set<int> groups;
        for (int i = 0; i < n; i ++) {
            groups.insert(find(djs, i));
        }
        return groups.size()-1;
    }
};