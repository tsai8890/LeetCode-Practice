#include <vector>
using namespace std;

struct node {
    int parent;
    int height;
    int area;
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<node> djs(n*m);
        
        int maxArea = 1;
        bool hasOne = false;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 1) {
                    if (!hasOne) {
                        hasOne = true;
                    }
                    int id = i*m + j;
                    djs[id].parent = id;
                    djs[id].height = 1;
                    djs[id].area = 1;
                    
                    if (i > 0 && grid[i-1][j] == 1) {
                        Union(djs, id, (i-1)*m + j, maxArea);
                    }
                    if (j > 0 && grid[i][j-1] == 1) {
                        Union(djs, id, i*m + j-1, maxArea);
                    }
                }
            }
        }
        return (hasOne) ? maxArea : 0;
    }
    
    int find(vector<node>& djs, int i) {
        if (djs[i].parent != i) {
            djs[i].parent = find(djs, djs[i].parent);
        }
        return djs[i].parent;
    }
    
    void Union(vector<node>& djs, int i, int j, int& maxArea) {
        int set_i = find(djs, i);
        int set_j = find(djs, j);
        if (set_i == set_j) return;
        
        if (djs[set_i].height >= djs[set_j].height) {
            djs[set_j].parent = set_i;
            djs[set_i].area += djs[set_j].area;
            if (djs[set_i].height == djs[set_j].height) {
                djs[set_i].height += 1;
            }
            maxArea = max(maxArea, djs[set_i].area);
        }
        else {
            djs[set_i].parent = set_j;
            djs[set_j].area += djs[set_i].area;
            maxArea = max(maxArea, djs[set_j].area);
        }
    }
};