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
    bool helper(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr || root2 == nullptr) {
            return (root1 == nullptr && root2 == nullptr);
        }
        if (root1->val == root2->val) {
            bool inside = helper(root1->right, root2->left); 
            bool outside = helper(root1->left, root2->right);
            return inside && outside;
        }
        else {
            return false;
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return helper(root->left, root->right);
    }
};