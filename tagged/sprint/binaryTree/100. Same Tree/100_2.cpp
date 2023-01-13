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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        deque<TreeNode*> dq;
        int left_num = 1, right_num = 1;
        dq.push_back(p);
        dq.push_back(q);

        while (!dq.empty()) {
            if (left_num != right_num) {
                return false;
            }

            for (int i = 0; i < left_num; i ++) {
                if (!dq[i] || !dq[i+left_num]) {
                    if (!(!dq[i] && !dq[i+left_num])) {
                        return false;
                    }
                }
                else if (dq[i]->val != dq[i+left_num]->val) {
                    return false;
                }
            }

            int n = left_num + right_num;
            int new_left_num = 0, new_right_num = 0;
            for (int i = 0; i < n; i ++) {
                TreeNode* front = dq.front();
                dq.pop_front();
                if (front != nullptr) {
                    dq.push_back(front->left);
                    dq.push_back(front->right);
                    if (i < left_num) {
                        new_left_num += 2;
                    }
                    else {
                        new_right_num += 2;
                    }
                }
            }
            left_num = new_left_num;
            right_num = new_right_num;
        }
        return true;
    }
};