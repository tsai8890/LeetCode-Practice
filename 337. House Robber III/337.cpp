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

#include <unordered_map>
using namespace std;

/*
    Title: 337. House Robber III
    Time Complexity: O(n)
    Space Complexity: O(n)-extra space

    Algorithm: 
        1. Top-Down DP (Divide & Conquer + Memorization)
        
    Note:
        1. 馬上可以想到Divide & Conquer，但是會TLE。Worst case是當整棵樹變成一條linked-list時，
           T(n) = T(n-1) + T(n-2) + O(1)，T(n)是exponential等級。

           因此，要加速Divide & Conquer，就可以使用DP啦，而這題因為有指標，使用top-down DP比較好實作，
           加上memo字典就可以了。

           使用top-down DP後，時間複雜度變成「子問題個數x子問題cost」= O(n) x O(1) = O(n)

    Date: 05/07/2022 13:03											
    Time: 11 ms  -- beat 93.30%    
    Memory: 25.5 MB  -- beat 32.02% 
*/

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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        return helper(root, memo);
    }
    
    int helper(TreeNode* root, unordered_map<TreeNode*, int>& memo) {
        if (root == nullptr) {
            return 0;
        }
        else if (memo.find(root) != memo.end()) {
            return memo[root];
        }
        else {
            int not_chosen = helper(root->left, memo) + helper(root->right, memo);
            
            int chosen = root->val;
            if (root->left) {
                chosen += helper(root->left->left, memo);
                chosen += helper(root->left->right, memo);
            }
            if (root->right) {
                chosen += helper(root->right->left, memo);
                chosen += helper(root->right->right, memo);
            }
            
            memo[root] = max(not_chosen, chosen);
            return memo[root];
        }
    }
};