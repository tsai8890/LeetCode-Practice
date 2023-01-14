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
    bool isIdentical(TreeNode* p, TreeNode* q) {
        if (!p || !q) {
            return (!p && !q);
        }
        
        if (p->val != q->val) {
            return false;
        }
        else {
            bool left = isIdentical(p->left, q->left);
            bool right = isIdentical(p->right, q->right);
            return left && right;
        }
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool curRes = isIdentical(root, subRoot);
        if (!root || curRes) {
            return curRes;
        }
        else {
            bool left = isSubtree(root->left, subRoot);
            bool right = isSubtree(root->right, subRoot);
            return left || right;
        }
    }
};