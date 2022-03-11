#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    /*
        Title: 133. Clone Graph
        Time Complexity: O(|V| + 2|E|)
        Algorithm: 
            1. DFS
        
        Date: 12/23/2021 03:55			
        Time: 0 ms  -- beat 100.00%
        Memory: 8.9 MB  -- beat 23.05%
    */
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        
        vector<Node*> nodes(101, nullptr);
        return dfs(node, nodes);
    }
    
    Node* dfs(Node* node, vector<Node*>& nodes) {
        if (nodes[node -> val] != nullptr)
            return nodes[node -> val];
        
        Node* ret_node = new Node(node -> val);
        nodes[node -> val] = ret_node;
        for (Node* neighbor : node -> neighbors) {
            ret_node -> neighbors.push_back(dfs(neighbor, nodes));
        }
        return ret_node;
    }
};