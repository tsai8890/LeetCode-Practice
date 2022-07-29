#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);   
        return res;
    }

    void traversal(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left, res);
        traversal(root->right, res);
        res.push_back(root->val);
    }
};

int main(void) {
    TreeNode* t = new TreeNode();
}