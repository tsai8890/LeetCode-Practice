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

#include <climits>

class Solution {
public: 
    int helper(TreeNode* root) {
        if (!root->left && !root->right) {
            return 1;
        }
        
        int minVal = INT_MAX;
        if (root->left) {
            minVal = min(minVal, 1 + helper(root->left));
        }
        if (root->right) {
            minVal = min(minVal, 1 + helper(root->right));
        }
        return minVal;
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return helper(root);
    }
};