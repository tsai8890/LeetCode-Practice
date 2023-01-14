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
    void inOrder(TreeNode* root, vector<int>& res) {
        if (root->left) inOrder(root->left, res);
        res.push_back(root->val);
        if (root->right) inOrder(root->right, res);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> inOrderRes;
        inOrder(root, inOrderRes);
        
        vector<int> res;
        int curNum; 
        int curCnt = 0, maxCnt = 0;
        for (int& num: inOrderRes) {
            curCnt = (num == curNum) ? curCnt+1 : 1;
            curNum = num;
            if (curCnt >= maxCnt) {
                if (curCnt > maxCnt) {
                    res.clear();
                    maxCnt = curCnt;
                }
                res.push_back(curNum);
            }
        }
        return res;
    }
};