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
    pair<int, int> helper(TreeNode* root) {
        if (!root->left && !root->right) {
            return make_pair(root->val, 1);
        }

        int lv, rv;
        int lh = 0, rh = 0;
        if (root->left) {
            pair<int, int> left = helper(root->left);
            lv = left.first;
            lh = left.second;
        }
        if (root->right) {
            pair<int, int> right = helper(root->right);
            rv = right.first;
            rh = right.second;
        }
        return (lh >= rh) ? make_pair(lv, lh+1) : make_pair(rv, rh+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        return helper(root).first;            
    }
};