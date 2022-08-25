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
#include <climits>
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
    void mode(TreeNode* root, int& curNum, int& curCnt, int& maxCnt, vector<int>& modes) {
        if (root->left) {
            mode(root->left, curNum, curCnt, maxCnt, modes);
        }
        
        curCnt = (curNum == root->val) ? curCnt+1 : 1;
        curNum = root->val;
        if (curCnt == maxCnt) {
            modes.push_back(curNum);
        }
        else if (curCnt > maxCnt) {
            modes.clear();
            maxCnt = curCnt;
            modes.push_back(curNum);
        }
        
        if (root->right) {
            mode(root->right, curNum, curCnt, maxCnt, modes);
        }
    }
    
    vector<int> findMode(TreeNode* root) {
        int curNum = INT_MIN, curCnt = 0;
        int maxCnt = 0;
        vector<int> modes;
        mode(root, curNum, curCnt, maxCnt, modes);
        return modes;
    }
};