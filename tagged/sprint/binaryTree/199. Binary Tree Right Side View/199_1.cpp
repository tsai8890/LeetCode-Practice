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
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* top;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i ++) {
                top = q.front();
                q.pop();
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
                if (i == n-1) res.push_back(top->val);
            }
        }
        return res;
    }
};