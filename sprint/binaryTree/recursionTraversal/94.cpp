#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);   
        return res;
    }

    void traversal(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left, res);
        res.push_back(root->val);
        traversal(root->right, res);
    }
};

int main(void) {
    TreeNode* t = new TreeNode();
}