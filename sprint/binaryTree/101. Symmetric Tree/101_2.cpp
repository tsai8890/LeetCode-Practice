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

#include <string>
#include <deque>
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        deque<TreeNode*> deq;
        deq.push_back(root);
        while (!deq.empty()) {
            int n = deq.size();
            TreeNode* front;
            for (int i = 0; i < n; i ++) {
                if (deq[i] == nullptr || deq[n-1-i] == nullptr) {
                    if (!(deq[i] == nullptr && deq[n-1-i] == nullptr)) {
                        return false;
                    }
                }
                else {
                    if (deq[i]->val != deq[n-1-i]->val) {
                        return false;
                    }
                }
            }

            for (int i = 0; i < n; i ++) {
                front = deq.front();
                deq.pop_front();
                if (front != nullptr) {
                    deq.push_back(front->left);
                    deq.push_back(front->right);
                }
            }
        }
        return true;
    }
};