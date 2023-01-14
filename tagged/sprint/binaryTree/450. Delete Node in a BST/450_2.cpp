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
        TreeNode* cur = root;
        TreeNode* parent = nullptr;
        TreeNode* retRoot = root;

        while (cur) {
            if (cur->val != key) {
                parent = cur;
                cur = (key < cur->val) ? cur->left : cur->right;
            }
            else {
                if (!cur->left || !cur->right) {
                    if (!parent) {
                        retRoot = (cur->left) ? cur->left : cur->right;
                    }
                    else {
                        if (key < parent->val) {
                            parent->left = (cur->left) ? cur->left : cur->right;
                        }
                        else {
                            parent->right = (cur->left) ? cur->left : cur->right;
                        }
                    }
                }
                else {
                    TreeNode* curLR = cur->left->right;
                    TreeNode* curRL = cur->right;
                    while (curRL->left) {
                        curRL = curRL->left;
                    }
                    curRL->left = curLR;
                    cur->left->right = cur->right;

                    if (!parent) {
                        retRoot = cur->left;
                    }
                    else {
                        if (key < parent->val) {
                            parent->left = cur->left;
                        }
                        else {
                            parent->right = cur->left;
                        }
                    }
                }
                break;
            }
        }
        return retRoot;
    }
};