/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    string bfs(TreeNode* p) {
        if (!p) {
            return "";
        }
        
        queue<TreeNode*> q;
        q.push(p);
        string res = "";
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (!front) {
                res += "* ";
            }
            else {
                q.push(front->left);
                q.push(front->right);
                res += to_string(front->val) + " ";
            }
        }
        return res;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string left_str = bfs(p);
        string right_str = bfs(q);
        return (left_str == right_str);
    }
};