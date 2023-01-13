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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int pre_begin, int pre_end,
                    int in_begin, int in_end) {
        
        if (pre_begin > pre_end) {
            return nullptr;
        }
        
        int rootPos;
        for (rootPos = in_begin; rootPos <= in_end; rootPos ++) {
            if (inorder[rootPos] == preorder[pre_begin]) {
                break;
            }
        }
        int nLefts = rootPos - in_begin;

        TreeNode* root = new TreeNode(preorder[pre_begin]);
        root->left = build(preorder, inorder, pre_begin+1, pre_begin+nLefts,
                           in_begin, rootPos-1);
        root->right = build(preorder, inorder, pre_begin+nLefts+1, pre_end,
                            rootPos+1, in_end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return build(preorder, inorder, 0, n-1, 0, n-1);
    }
};