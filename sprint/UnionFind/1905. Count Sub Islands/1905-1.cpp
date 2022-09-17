#include <vector>
#include <unordered_set>
using namespace std;

struct node {
    int parent;
    int height;
    bool valid;
};

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1.front().size();
        vector<node> djs(n*m);
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid2[i][j] == 1) {
                    int id = i*m + j;
                    djs[id].parent = id;
                    djs[id].height = 1;
                    djs[id].valid = (grid1[i][j] == 1);
                    
                    if (i > 0 && grid2[i-1][j] == 1) {
                        Union(djs, id, (i-1)*m + j);
                    }
                    if (j > 0 && grid2[i][j-1] == 1) {
                        Union(djs, id, i*m + j-1);
                    }
                }
            }
        }
        
        unordered_set<int> set;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                int setId = find(djs, i*m + j);
                if (djs[setId].valid) {
                    set.insert(setId);
                }
            }
        }
        return set.size();
    }
    
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
            djs[set_i].parent = set_j;
            djs[set_j].valid = djs[set_i].valid && djs[set_j].valid;
        }
    }
};