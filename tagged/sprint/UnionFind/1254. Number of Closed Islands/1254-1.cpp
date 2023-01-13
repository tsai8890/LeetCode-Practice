#include <vector>
#include <unordered_map>
using namespace std;

struct node {
    int parent;
    int height;
    bool valid;
};

class Solution {
public:
    int find(vector<node>& dsj, int i) {
        if (dsj[i].parent != i) {
            dsj[i].parent = find(dsj, dsj[i].parent);
        }
        return dsj[i].parent;
    }

    void Union(vector<node>& dsj, int i, int j) {
        int set_i = find(dsj, i);
        int set_j = find(dsj, j);
        if (set_i == set_j) return;

        if (dsj[set_i].height >= dsj[set_j].height) {
            dsj[set_j].parent = set_i;
            dsj[set_i].valid = dsj[set_i].valid && dsj[set_j].valid;
            if (dsj[set_i].height == dsj[set_j].height) {
                dsj[set_i].height += 1;
            }
        }
        else {
            dsj[set_i].parent = set_j;
            dsj[set_j].valid = dsj[set_i].valid && dsj[set_j].valid;
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        vector<node> dsj(n*m);

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 0) {
                    int id = i*m + j;
                    dsj[id].parent = id;
                    dsj[id].height = 1;
                    dsj[id].valid = !(i == 0 || i == n-1 || j == 0 || j == m-1);
                    if (i > 0 && grid[i-1][j] == 0) {
                        Union(dsj, id, (i-1)*m + j);
                    }
                    if (j > 0 && grid[i][j-1] == 0) {
                        Union(dsj, id, i*m + j-1);
                    }
                }
            }
        }

        int total = 0;
        unordered_map<int, bool> stat;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 0) {
                    int id = i*m + j;
                    int setId = find(dsj, id);
                    if (dsj[setId].valid) {
                        if (stat.find(setId) == stat.end()) {
                            stat[setId] = true;
                            total += 1;
                        }
                    }
                }
            }
        }
        return total;
    }
};