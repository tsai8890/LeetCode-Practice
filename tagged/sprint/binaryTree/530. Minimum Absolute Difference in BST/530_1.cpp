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
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minDiff(TreeNode* root, int& last) {
        int min_diff = INT_MAX;
        if (root->left) {
            min_diff = min(min_diff, minDiff(root->left, last));
        }
        
        min_diff = min(min_diff, abs(root->val-last));
        last = root->val;
        
        if (root->right) {
            min_diff = min(min_diff, minDiff(root->right, last));
        }
        
        return min_diff;
    }
    
    int getMinimumDifference(TreeNode* root) {
        int last = INT_MIN / 100;
        return minDiff(root, last);
    }
};