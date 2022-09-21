#include <cmath>
#include <utility>
#include <vector>
#include <queue>

#define Node pair<double,int>
#define Edge pair<int,double>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for (auto& prob: succProb) {
            prob = -log(prob);
        }
        
        vector<vector<Edge>> G(n);
        for (int i = 0; i < edges.size(); i ++) {
            G[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            G[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        vector<int> visited(n, false);
        pq.push(make_pair(0, start));
        Node curNode;
        while (!pq.empty()) {
            curNode = pq.top();
            pq.pop();
            if (!visited[curNode.second]) {
                visited[curNode.second] = true;
                if (curNode.second == end) {
                    return exp(-curNode.first);
                }
                for (auto& edge: G[curNode.second]) {
                    if (!visited[edge.first]) {
                        pq.push(make_pair(edge.second+curNode.first, edge.first));
                    }
                }
            }
        }
        return 0;
    }
};