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
    int convert(TreeNode* root, int bias) {
        int oldRootVal = root->val;
        int rightSum = 0;
        if (root->right) {
            rightSum = convert(root->right, bias);
        }            
        root->val += rightSum + bias;
        
        int leftSum = 0;
        if (root->left) {
            leftSum = convert(root->left, oldRootVal+rightSum+bias);
        }
        return leftSum + oldRootVal + rightSum;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if (!root) {
            return root;
        }
        convert(root, 0);
        return root;
    }
};