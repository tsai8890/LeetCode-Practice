#include <cmath>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int id;
    double cost;
    
    Node(int id, double cost) {
        this->id = id;
        this->cost = cost;
    }
    
    Node() {
        
    }
};

class compareNode {
public:
    bool operator()(Node& node1, Node& node2) {
        return node1.cost >= node2.cost;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for (auto& prob: succProb) {
            prob = -log(prob);
        }
        
        vector<vector<pair<int,double>>> G(n);
        for (int i = 0; i < edges.size(); i ++) {
            G[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            G[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        
        priority_queue<Node, vector<Node>, compareNode> pq;
        vector<int> visited(n, false);
        pq.push(Node(start, 0));
        Node curNode;
        while (!pq.empty()) {
            curNode = pq.top();
            pq.pop();
            if (!visited[curNode.id]) {
                visited[curNode.id] = true;
                if (curNode.id == end) {
                    return exp(-curNode.cost);
                }
                for (auto& edge: G[curNode.id]) {
                    if (!visited[edge.first]) {
                        pq.push(Node(edge.first, edge.second+curNode.cost));
                    }
                }
            }
        }
        return 0;
    }
};