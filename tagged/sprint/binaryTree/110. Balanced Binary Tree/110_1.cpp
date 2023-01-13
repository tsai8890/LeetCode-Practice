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

#include <cmath>
#include <algorithm>
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
    int maxDepth(TreeNode* root, bool& balanced) {
        if (!root) {
            return 0;
        }
        int left_h = maxDepth(root->left, balanced);
        int right_h = maxDepth(root->right, balanced);
        if (!balanced || (abs(left_h - right_h) > 1)) {
            balanced = false;
        }
        return 1 + max(left_h, right_h);
    }
    
    bool isBalanced(TreeNode* root) {
        bool result = true;
        maxDepth(root, result);
        return result;
    }
};