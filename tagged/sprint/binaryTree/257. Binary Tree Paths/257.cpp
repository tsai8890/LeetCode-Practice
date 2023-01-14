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
#include <string>
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
    void path(TreeNode* root, vector<int>& curPath, vector<string>& res) {
        curPath.push_back(root->val);
        if (!root->left && !root->right) {
            string pathStr;
            for (int i = 0; i < curPath.size(); i++) {
                pathStr += to_string(curPath[i]);
                if (i != curPath.size()-1) {
                    pathStr += "->";
                }
            }
            res.push_back(pathStr);
        }
        else {
            if (root->left) path(root->left, curPath, res);
            if (root->right) path(root->right, curPath, res);
        }
        curPath.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) {
            return res;
        }
        
        vector<int> curPath;
        path(root, curPath, res);
        return res;
    }
};