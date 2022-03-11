/*
    Title: 701. Insert into a Binary Search Tree
    Time Complexity: O(N)
    Algorithm: 
        1. Recursion

    Date: 01/13/2022 07:44				
    Time: 84ms  -- beat 82.44%
    Memory: 56.8 MB  -- beat 80.82%
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* added = new TreeNode(val);
            return added;
        }
        else {
            if (val < root->val) {
                root->left = insertIntoBST(root->left, val);
            }
            else {
                root->right = insertIntoBST(root->right, val);
            }
            return root;
        }
    }
};