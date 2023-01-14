/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) {
            return root;
        }
        
        TreeNode* leftRes = nullptr;
        TreeNode* rightRes = nullptr;
        if (root->left) {
            leftRes = lowestCommonAncestor(root->left, p, q);
        }
        if (root->right) {
            rightRes = lowestCommonAncestor(root->right, p, q);
        }
        
        if (leftRes && rightRes) {
            return root;
        }
        return (rightRes == nullptr) ? leftRes : rightRes;
    }
};