#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

struct node {
    int parent;
    int height;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int,int>>> edges;
        for (int i = 0; i < n-1; i ++) {
            for (int j = i+1; j < n; j ++) {
                int diff = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back(make_pair(diff, make_pair(i, j)));
            }
        }
        sort(edges.begin(), edges.end(), less<pair<int, pair<int,int>>>());
        
        vector<node> djs(n);
        for (int i = 0; i < n; i ++) {
            djs[i].parent = i;
            djs[i].height = 1;
        }
        
        int mstSum = 0;
        int totalNodes = 1;
        for (auto& edge: edges) {
            int dis = edge.first;
            int from = edge.second.first, to = edge.second.second;
            if (Union(djs, from, to)) {
                mstSum += dis;
                totalNodes += 1;
            }
            if (totalNodes == n) {
                break;
            }
        }
        return mstSum;
    }
    
    int dis(vector<vector<int>>& points, int i, int j) {
        return abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
    }
    
    int find(vector<node>& djs, int i) {
        if (djs[i].parent != i) {
            djs[i].parent = find(djs, djs[i].parent);
        }
        return djs[i].parent;
    }
    
    bool Union(vector<node>& djs, int i, int j) {
        int set_i = find(djs, i);
        int set_j = find(djs, j);
        if (set_i == set_j) return false;
        
        if (djs[set_i].height >= djs[set_j].height) {
            djs[set_j].parent = set_i;
            if (djs[set_i].height == djs[set_j].height) {
                djs[set_i].height ++;
            }
        }
        else {
            djs[set_i].parent = set_j;
        }
        return true;
    }
};