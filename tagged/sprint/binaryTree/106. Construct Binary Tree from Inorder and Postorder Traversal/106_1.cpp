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
#include <utility>
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
    TreeNode* build(vector<int>& inorder, vector<int> postorder,
                    pair<int, int> inRange, pair<int, int> postRange) {
        int in_begin = inRange.first, in_end = inRange.second;
        int post_begin = postRange.first, post_end = postRange.second;
        if (in_begin > in_end) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[post_end]);
        int i;
        for (i = in_begin; i <= in_end; i++) {
            if (inorder[i] == postorder[post_end]) {
                break;
            }
        }
        
        int leftNodes = i - in_begin;
        root->left = build(inorder, postorder,
                           make_pair(in_begin, i-1),
                           make_pair(post_begin, post_begin+leftNodes-1));
        
        root->right = build(inorder, postorder,
                            make_pair(i+1, in_end),
                            make_pair(post_begin+leftNodes, post_end-1));
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, postorder, make_pair(0, n-1), make_pair(0, n-1));
    }
};