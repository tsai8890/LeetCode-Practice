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
        if (root == nullptr) {
            return 0;
        }    
            
        int withRoot = root->val;
        if (root->left) {
            withRoot += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            withRoot += rob(root->right->left) + rob(root->right->right);
        }
        int withoutRoot = rob(root->left) + rob(root->right);
        return max(withRoot, withoutRoot);
    }
};