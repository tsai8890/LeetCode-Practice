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
    int helper(TreeNode* root, int dir) {
        if (!root->left && !root->right) {
            return (dir == -1) ? root->val : 0;
        }
        int sum = 0;
        if (root->left) sum += helper(root->left, -1);
        if (root->right) sum += helper(root->right, 1);
        return sum;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return helper(root, 0);
    }
};