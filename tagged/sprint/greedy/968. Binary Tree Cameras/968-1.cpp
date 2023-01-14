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
#include <unordered_map>
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
    int minCameraCover(TreeNode* root) {
        unordered_map<TreeNode*, vector<int>> dp;
        vector<int> res = helper(root, dp);
        return min(res[0], res[2]);
    }
    
    vector<int> helper(TreeNode* root, unordered_map<TreeNode*, vector<int>>& dp) {
        // res includes three cases
        //      res[0]: camera placed
        //      res[1]: no camera but covered
        //      res[2]: no camera nor covered 

        if (!root) {
            return vector<int>{0, 0, INT_MAX};
        }
        
        if (dp.find(root) != dp.end()) {
            return dp[root];
        }
        
        vector<int> l_res = helper(root->left, dp);
        vector<int> r_res = helper(root->right, dp);
        dp[root] = vector<int>{
            1 + min(l_res[0], l_res[1]) + min(r_res[0], r_res[1]),
            min(l_res[0], l_res[2]) + min(r_res[0], r_res[2]),
            INT_MAX
        };
        
        if (root->left) {
            dp[root][2] = l_res[0] + min(r_res[0], r_res[2]);
        }
        if (root->right) {
            dp[root][2] = min(dp[root][2], r_res[0] + min(l_res[0], l_res[2]));
        }
        
        return dp[root];
    }
};