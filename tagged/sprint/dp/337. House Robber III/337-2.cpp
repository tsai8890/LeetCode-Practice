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

#include <unordered_map>
using namespace std;

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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return helper(root, dp);
    }
    
    int helper(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if (root == nullptr) {
            return 0;
        }    
        
        if (dp.find(root) != dp.end()) {
            return dp[root];
        }
            
        int withRoot = root->val;
        if (root->left) {
            withRoot += helper(root->left->left, dp) + helper(root->left->right, dp);
        }
        if (root->right) {
            withRoot += helper(root->right->left, dp) + helper(root->right->right, dp);
        }
        int withoutRoot = helper(root->left, dp) + helper(root->right, dp);
        
        dp[root] = max(withRoot, withoutRoot);
        return dp[root];
    }
};