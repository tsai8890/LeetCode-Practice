#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int find(vector<pair<int, int>>& dsjSet, int i) {
        if (dsjSet[i].first == i) {
            return i;
        }
        dsjSet[i].first = find(dsjSet, dsjSet[i].first);
        return dsjSet[i].first;
    }
    
    bool Union(vector<pair<int, int>>& dsjSet, int i, int j) {
        int set_i = find(dsjSet, i);
        int set_j = find(dsjSet, j);
        if (set_i == set_j) {
            return false;
        }
        
        if (dsjSet[set_i].second > dsjSet[set_j].second) {
            dsjSet[set_j].first = set_i;
        }
        else if (dsjSet[set_i].second == dsjSet[set_j].second) {
            dsjSet[set_j].first = set_i;
            dsjSet[set_i].second += 1;
        }
        else {
            dsjSet[set_i].first = set_j;
        }
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<pair<int, int>> dsjSet(1001);
        for (int i = 0; i < 1001; i ++) {
            dsjSet[i].first = i;
            dsjSet[i].second = 1;
        }
        
        for (int i = 0; i < edges.size(); i ++) {
            if (!Union(dsjSet, edges[i][0], edges[i][1])) {
                return edges[i];
            }
        }
        return vector<int>();
    }
};