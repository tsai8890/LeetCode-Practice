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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else {
            if (!root->left || !root->right) {
                return (root->left) ? root->left : root->right;
            }
            else {
                TreeNode* tmp = root->left->right;
                root->left->right = root->right;
                
                TreeNode* curPtr = root->right;
                while (curPtr->left) {
                    curPtr = curPtr->left;
                }
                curPtr->left = tmp;
                return root->left;
            }
        }
    }
};