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
 
class Solution {
public:
    void invert(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invert(root->left);
        invert(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};