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

#include <utility>
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
    void helper(TreeNode* root, int d, int& maxDepth, int& leftMost) {
        if (!root->left && !root->right) {
            if (d > maxDepth) {
                maxDepth = d;
                leftMost = root->val;
            }
        }
        else {
            if (root->left) {
                helper(root->left, d+1, maxDepth, leftMost);
            }
            if (root->right) {
                helper(root->right, d+1, maxDepth, leftMost);
            }
        }
    }
    
    int findBottomLeftValue(TreeNode* root) {
        int d = 0, maxDepth = -1;
        int leftMost;
        helper(root, d, maxDepth, leftMost); 
        return leftMost;         
    }
};