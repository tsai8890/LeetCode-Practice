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
    int minCameraCover(TreeNode* root) {
        int totalCam = 0;
        if (helper(root, totalCam) == State::None) {
            totalCam ++;
        }
        return totalCam;
    }

private:
    enum class State {
        None = -1,
        Covered = 0,
        Camera = 1
    };
    
    State helper(TreeNode* root, int& total) {
        if (!root->left && !root->right) {
            return State::None;
        }
        
        State l_res = (root->left == nullptr) ? State::Covered : helper(root->left, total);
        State r_res = (root->right == nullptr) ? State::Covered : helper(root->right, total);
        
        if (l_res == State::None || r_res == State::None) {
            total ++;
            return State::Camera;
        }
        else if (l_res == State::Camera || r_res == State::Camera) {
            return State::Covered;
        }
        else {
            return State::None;
        }
    }
};