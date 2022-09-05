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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode*, int> top = q.front();
            q.pop();
            if (top.second >= res.size()) {
                res.push_back(vector<int>());
            }
            res[top.second].push_back(top.first->val);
            
            if (top.first->left) {
                q.push(make_pair(top.first->left, top.second+1));
            }
            if (top.first->right) {
                q.push(make_pair(top.first->right, top.second+1));
            }
        }
        return res;
    }
};