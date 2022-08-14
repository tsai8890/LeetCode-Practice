#include <vector>
using namespace std;

    /*
        Title: 684. Redundant Connection
        Time Complexity: 
            1. O(n * alpha(n)), where alpha(n) <= 4

        Algorithm:
            1. Disjoint Set

        Note:
            1. Disjoint Set實作很容易，而且複雜度很低，一定要記！
            2. 在實作union by rank(height) & path compression下，
               每次操作可以達到O(1)的複雜度。
                
        Date: 12/27/2021 00:21							
        Time: 0 ms  -- beat 100.00%
        Memory: 9.7 MB  -- beat 20.78%
    */

class DJS {
public:
    vector<int> djs;
    vector<int> rank;
    
    DJS(int n) {
        for (int i = 0; i < n; i ++) {
            this -> djs.push_back(i);
            this -> rank.push_back(0);
        }
    }
    
    int find(int i) {
        if (djs[i] == i) {
            return i;
        } else {
            djs[i] = find(djs[i]);
            return djs[i];
        }
    }
    
    bool Union(int i, int j) {
        int set_i = find(i);
        int set_j = find(j);
        
        if (set_i == set_j) {
            return false;
        } else {
            if (rank[set_i] == rank[set_j]) {
                djs[set_i] = set_j;  
                rank[set_j] += 1;
                
            } else if (rank[set_i] < rank[set_j]) {
                djs[set_i] = set_j;  
                
            } else {
                djs[set_j] = set_i;  
            }
            return true;
        }
    }
};

class Solution {

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DJS dj_set(1001);
        for (int i = 0; i < edges.size(); i ++) {
            if (!dj_set.Union(edges[i][0], edges[i][1])) {
                return edges[i];
            }
        }
        return vector<int>();
    }
};