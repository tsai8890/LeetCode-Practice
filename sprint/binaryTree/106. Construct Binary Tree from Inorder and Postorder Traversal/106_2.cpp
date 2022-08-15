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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int in_begin, int in_end,
                    int post_begin, int post_end,
                    unordered_map<int, int>& pos) {
        
        if (in_begin > in_end) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[post_end]);
        int mid = pos[postorder[post_end]];
        int leftNodes = mid - in_begin;
        
        root->left = build(inorder, postorder,
                           in_begin, mid-1,
                           post_begin, post_begin+leftNodes-1,
                           pos);
        root->right = build(inorder, postorder,
                            mid+1, in_end,
                            post_begin+leftNodes, post_end-1,
                            pos);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, n-1, 0, n-1, pos);
    }
};