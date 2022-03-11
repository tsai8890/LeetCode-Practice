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
    /*
        Title: 366. Find Leaves of Binary Tree
        Time Complexity:
            1. O(N^2)

        Algorithm: 
            1. DFS with backtracing

        Note:
            1. 這題是常用的二元樹操作(insert、remove)，
               都是使用類似的方法(root->left = dfs(root->left))，
               但是這題還有更優解，是O(N)

        Date: 12/16/2021 16:59					
        Time: 0ms  -- beat 100.00%
        Memory: 8.4 MB  -- beat 79.55%
    */
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        result.clear();
        while (root != nullptr) {
            vector<int> cur_removed;
            result.push_back(cur_removed);
            root = dfs(root);
        }
        return result;
    }
    
    TreeNode* dfs(TreeNode* root) {
        if (root -> left == nullptr && root -> right == nullptr) {
            result[result.size() - 1].push_back(root -> val);
            return nullptr;
        } else {
            if (root -> left)
                root -> left = dfs(root -> left);
            if (root -> right)
                root -> right = dfs(root -> right);
        }
        return root;
    }
    
private:
    vector<vector<int>> result;
};