#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

struct Edge {
    int dst;
    int cost;
    Edge(int dst, int cost) {
        this->dst = dst;
        this->cost = cost;
    }
};

class compareEdge {
public:
    bool operator()(Edge& edge1, Edge& edge2) {
        return edge1.cost >= edge2.cost;
    }
};

class Solution {
public:
    int dis(vector<vector<int>>& points, int i, int j) {
        return abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        priority_queue<Edge, vector<Edge>, compareEdge> pq;

        visited[0] = true;
        for (int i = 0; i < n; i ++) {
            if (i != 0 && !visited[i]) {
                pq.push(Edge(i, dis(points, 0, i)));
            }
        }

        int mstSum = 0;
        int totalNodes = 1;
        while (!pq.empty()) {
            Edge edge = pq.top();
            pq.pop();
            if (!visited[edge.dst]) {
                visited[edge.dst] = true;
                mstSum += edge.cost;
                totalNodes += 1;
                for (int i = 0; i < n; i ++) {
                    if (i != edge.dst && !visited[i]) {
                        pq.push(Edge(i, dis(points, edge.dst, i)));
                    }
                }
            }
            if (totalNodes == n) {
                break;
            }
        }
        return mstSum;
    }
};