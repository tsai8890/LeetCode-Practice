#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

/*
    Title: 1584. Min Cost to Connect All Points
    Time Complexity: 
        1. O(n^2 x log(n))

    Algorithm:
        1. Kruthkal Algorithm,
           to find Minimum Spanning Tree

    Date: 01/03/2022 18:52										
    Time: 164 ms  -- beat 84.60%
    Memory: 58.3 MB  -- beat 60.92%
*/

struct edge {
    int from, to;
    int weight;
    
    edge(int from, int to, int weight) {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

bool operator<(edge e1, edge e2) {
    return e1.weight > e2.weight;
}

class disjoint_set {
public:
    disjoint_set(int n) {
        for (int i = 0; i < n; i ++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        else {
            parent[i] = find(parent[i]);
            return parent[i];
        }
    }
    
    bool Union(int i, int j) {
        int par1 = find(i);
        int par2 = find(j);
        
        if (par1 == par2) {
            return false;
        } 
        else {
            if (rank[par1] > rank[par2]) {
                parent[par2] = par1;
            } 
            else if (rank[par1] == rank[par2]) {
                parent[par2] = par1;
                rank[par1] += 1;
            }
            else {
                parent[par1] = par2;
            }
            return true;
        }
    }
    
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<edge> pq;
        for (int i = 0; i < points.size()-1; i ++) {
            for (int j = i+1; j < points.size(); j ++) {
                edge added(i, j, dist(points[i], points[j]));
                pq.push(added);
            }
        }
        
        disjoint_set dj_set(points.size());
        int edge_cnt = 0;
        int total_cost = 0;
        
        while (!pq.empty() && edge_cnt < points.size()-1) {
            auto cur_edge = pq.top();
            pq.pop();
            if (dj_set.Union(cur_edge.from, cur_edge.to)) {
                total_cost += cur_edge.weight;
                edge_cnt += 1;
            } 
        }
        return total_cost;
    }
    
    static long long int dist(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
};