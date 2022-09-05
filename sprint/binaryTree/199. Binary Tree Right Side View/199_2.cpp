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
        if (root == nullptr) {
            return vector<int>();
        }
        
        vector<vector<int>> levelOrder;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode*, int> top = q.front();
            q.pop();
            if (top.second >= levelOrder.size()) {
                levelOrder.push_back(vector<int>());
            }
            levelOrder[top.second].push_back(top.first->val);
            
            if (top.first->left) {
                q.push(make_pair(top.first->left, top.second+1));
            }
            if (top.first->right) {
                q.push(make_pair(top.first->right, top.second+1));
            }
        }
        
        vector<int> res;
        for (auto level: levelOrder) {
            res.push_back(level.back());
        }
        return res;
    }
};