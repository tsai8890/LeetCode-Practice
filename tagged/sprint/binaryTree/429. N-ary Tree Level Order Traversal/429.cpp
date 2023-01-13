/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            res.push_back(vector<int>());
            for (int i = 0; i < n; i++) {
                Node* front = q.front();
                q.pop();
                res.back().push_back(front->val);
                for (auto& child: front->children) {
                    q.push(child);
                }
            }
        }
        return res;
    }
};