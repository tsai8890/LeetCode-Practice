#include <utility>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int id;
    int cost;
    
    Node(int id, int cost) {
        this -> id = id;
        this -> cost = cost;
    }

    Node() {
        
    }
};

class CompareNode {
public:
    bool operator()(Node& node1, Node& node2) {
        return node1.cost >= node2.cost;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for (auto& time: times) {
            graph[time[0]].push_back(make_pair(time[1], time[2]));
        }
        
        priority_queue<Node, vector<Node>, CompareNode> pq;    
        vector<bool> visited(n+1, false);
        pq.push(Node(k, 0));
        
        int maxTime = 0;
        int count = 0;
        Node node;
        while (!pq.empty()) {
            node = pq.top();
            pq.pop();
            if (!visited[node.id]) {
                count += 1;
                visited[node.id] = true;
                maxTime = node.cost;
                for (auto& edge: graph[node.id]) {
                    Node insertNode(edge.first, edge.second+node.cost);
                    pq.push(insertNode);
                }
            }
        }
        return (count == n) ? maxTime : -1; 
    }
};