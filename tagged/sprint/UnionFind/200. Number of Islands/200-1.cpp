#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int find(vector<pair<int, int>>& dsjSet, int i) {
        if (i != dsjSet[i].first) {
            dsjSet[i].first = find(dsjSet, dsjSet[i].first);
        }
        return dsjSet[i].first;
    }    
    
    bool Union(vector<pair<int, int>>& dsjSet, int i, int j) {
        int set_i = find(dsjSet, i);
        int set_j = find(dsjSet, j);
        if (set_i == set_j) {
            return false;
        }
        
        if (dsjSet[set_i].second >= dsjSet[set_j].second) {
            dsjSet[set_j].first = set_i;
            if (dsjSet[set_i].second == dsjSet[set_j].second) {
                dsjSet[set_i].second += 1;
            }
        }
        else {
            dsjSet[set_i].first = set_j;
        }
        return true;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid.front().size();
        int total = n * m;
        
        vector<pair<int, int>> dsjSet(total);
        for (int i = 0; i < total; i ++) {
            dsjSet[i].first = i;
        }
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == '0') {
                    total -= 1;
                }
                else {
                    if ((i > 0 && grid[i-1][j] == '1') || (j > 0 && grid[i][j-1] == '1')) {
                        int decrease = 1;
                        if (i > 0 && grid[i-1][j] == '1') {
                            if (Union(dsjSet, m*(i-1)+j, m*i+j)) {
                                decrease += 1;
                            }
                        }
                        if (j > 0 && grid[i][j-1] == '1') {
                            if (Union(dsjSet, m*i+j-1, m*i+j)) {
                                decrease += 1;
                            }
                        }
                        total -= (decrease-1);
                    }
                }
            }
        }
        
        return total;
    }
};