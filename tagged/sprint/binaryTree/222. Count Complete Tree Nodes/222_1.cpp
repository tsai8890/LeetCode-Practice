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

#include <queue>
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
    int getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        else {
            return 1 + getHeight(root->left);
        }
    }

    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left_h = getHeight(root->left);
        int right_h = getHeight(root->right);
        if (left_h == right_h) {
            return (1 << left_h) + countNodes(root->right); 
        }
        else {
            return (1 << right_h) + countNodes(root->left);
        }
    }
};