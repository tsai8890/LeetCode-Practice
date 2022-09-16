#include <vector>
#include <unordered_set>
using namespace std;

struct node {
    int parent;
    int height;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<node> djs(n);
        for (int i = 0; i < n; i ++) {
            djs[i].parent = i;
            djs[i].height = 1;
        }

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (isConnected[i][j] == 1) {
                    Union(djs, i, j);
                }
            }
        }

        unordered_set<int> set;
        for (int i = 0; i < n; i ++) {
            set.insert(find(djs, i));
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
            if (djs[set_i].height == djs[set_j].height) {
                djs[set_i].height++;
            }
        }
        else {
            djs[set_i].parent = set_j;
        }
    }
};