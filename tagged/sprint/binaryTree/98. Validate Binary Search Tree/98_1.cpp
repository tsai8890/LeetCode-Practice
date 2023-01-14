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
    bool valid(TreeNode* root, long long& last) {
        if (root->left && !valid(root->left, last)) {
            return false;
        }
        
        if (root->val <= last) {
            return false;
        }
        last = root->val;
        
        if (root->right && !valid(root->right, last)) {
            return false;
        }
        
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        long long last = LONG_MIN;
        return valid(root, last);
    }
};