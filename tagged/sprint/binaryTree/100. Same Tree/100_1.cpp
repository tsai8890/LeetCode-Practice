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
        else {
            if (p->val != q->val) {
                return false;
            } 
            else {
                bool left = isIdentical(p->left, q->left);
                bool right = isIdentical(p->right, q->right);
                return left && right;
            }
        }
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isIdentical(p, q);
    }
};