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

#define Path vector<int>

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
    void path(TreeNode* root, Path& curPath, int targetSum, vector<Path>& res) {
        curPath.push_back(root->val);
        targetSum -= root->val;
        if (!root->left && !root->right) {
            if (targetSum == 0) {
                res.push_back(curPath);
            }   
        }
        else {
            if (root->left) path(root->left, curPath, targetSum, res);
            if (root->right) path(root->right, curPath, targetSum, res);
        }
        curPath.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<Path> res;
        if (!root) {
            return res;
        }
        Path curPath;
        path(root, curPath, targetSum, res);
        return res;
    }
};