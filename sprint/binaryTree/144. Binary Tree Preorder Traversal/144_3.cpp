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
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if (!root) {
            return vector<int>();
        }        
        st.push(root);
        
        vector<int> result;
        while (!st.empty()) {
            TreeNode* mid = st.top();
            st.pop();
            result.push_back(mid->val);
            if (mid->right) { st.push(mid->right); }
            if (mid->left) { st.push(mid->left); }
        }
        return result;
    }
};