#include <algorithm>
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
    /*
        Title: 104. Maximum Depth of Binary Tree
        Time Complexity: O(N)

        Algorithm:
            1. DFS

        Date: 12/20/2021 17:20		
        Time: 0 ms  -- beat 100.00%
        Memory: 18.9 MB  -- beat 14.29%
    */
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
    
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int left_h = dfs(root->left);
        int right_h = dfs(root->right);
        return max(left_h, right_h) + 1;
    }
};