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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if (!root) {
            return vector<int>();
        }        
        
        vector<int> result;
        TreeNode* cur = root;
        while (!st.empty() || cur != nullptr) {
            if (cur == nullptr) {
                cur = st.top();
                result.push_back(cur->val);
                st.pop();
                cur = cur->right;
            }
            else {
                st.push(cur);
                cur = cur->left;
            }
        } 
        return result;
    }
};