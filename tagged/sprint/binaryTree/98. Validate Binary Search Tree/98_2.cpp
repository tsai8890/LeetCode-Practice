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
    void traversal(TreeNode* root, vector<int>& res) {
        if (root->left) traversal(root->left, res);
        res.push_back(root->val);
        if (root->right) traversal(root->right, res);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        traversal(root, nums);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i-1]) {
                return false;
            }
        }
        return true;
    }
};