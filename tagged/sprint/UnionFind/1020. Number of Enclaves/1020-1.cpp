#include <vector>
using namespace std;

struct node {
    int parent;
    int height;
    bool valid;
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
            djs[set_i].valid = djs[set_i].valid && djs[set_j].valid;
            if (djs[set_i].height == djs[set_j].height) {
                djs[set_i].height += 1;
            }
        }
        else {
            djs[set_j].parent=set_i;
            djs[set_i].valid = djs[set_i].valid && djs[set_j].valid;
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        vector<node> djs(n*m);
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 1) {
                    int id = i*m + j;
                    djs[id].parent = id;
                    djs[id].height = 1;
                    djs[id].valid = !(i == 0 || i == n-1 || j == 0 || j == m-1);
                    if (i > 0 && grid[i-1][j] == 1) {
                        Union(djs, id, (i-1)*m + j);
                    }
                    if (j > 0 && grid[i][j-1] == 1) {
                        Union(djs, id, i*m + j-1);
                    }
                }
            }
        }
        
        int total = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 1) {
                    if (djs[find(djs, i*m + j)].valid) {
                        total += 1;   
                    }
                }
            }
        }
        return total;
    }
};