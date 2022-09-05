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

#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& result) {
        if (root->left) {
            inOrder(root->left, result);
        }
        result.push_back(root->val);
        if (root->right) {
            inOrder(root->right, result);
        }
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        int minDiff = INT_MAX;
        for (int i = 1; i < res.size(); i ++) {
            minDiff = min(minDiff, abs(res[i]-res[i-1]));
        }
        return minDiff;
    }
};