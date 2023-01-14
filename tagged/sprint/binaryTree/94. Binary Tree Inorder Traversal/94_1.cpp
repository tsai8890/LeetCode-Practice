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

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);   
        return res;
    }

    void traversal(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);
    }
};

int main(void) {
    TreeNode* t = new TreeNode();
}