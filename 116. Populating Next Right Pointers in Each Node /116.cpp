class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


#include <deque>
using namespace std;

class Solution {
    /*
        Title: 116. Populating Next Right Pointers in Each Node
        Time Complexity: O(N)
        Algorithm: 
            1. BFS

        Date: 12/14/2021 12:08		
        Time: 12ms  -- beat 98.50%
        Memory: 17.3 MB  -- beat 19.53%
    */
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        
        Node* head = root;
        deque<Node*> q;
        q.push_back(root);
        q.push_back(nullptr);
        
        while (!q.empty()) {
            if (q[0] == nullptr) {
                q.pop_front();
                continue;
            }
            
            Node* cur = q[0];
            q.pop_front();
            cur -> next = q[0];
            
            if (cur -> left)
                q.push_back(cur -> left);
            if (cur -> right)
                q.push_back(cur -> right);
            
            if (q[0] == nullptr) {
                q.push_back(nullptr);
            }
        }
        return head;
    }
};