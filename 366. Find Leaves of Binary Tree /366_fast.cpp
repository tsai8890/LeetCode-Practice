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
            1. O(N)

        Algorithm: 
            1. DFS with backtracing

        Note:
            1. 使用backtracing來記錄當前node的高度，即可按照
               高度放入對應的vector，而且只需要跑一次DFS就可以得到所有node的高度。
            
            2. cur_h = max(left_h, right_h) + 1;

        Date: 12/16/2021 17:23					
        Time: 0ms  -- beat 100.00%
        Memory: 9.1 MB  -- beat 21.10%
    */
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        result.clear();
        dfs(root);
        return result;
    }
    
    int dfs(TreeNode* root) {
        int cur_h;

        if (root -> left == nullptr && root -> right == nullptr) {
            cur_h = 0;
        } else {
            int left_h = 0, right_h = 0;
            if (root -> left)
                left_h = dfs(root -> left);
            if (root -> right)
                right_h = dfs(root -> right);
            cur_h = max(left_h, right_h) + 1;
        }
        
        if (result.size() <= cur_h)
            result.push_back(vector<int>());
        result[cur_h].push_back(root -> val);

        return cur_h;
    }
    
private:
    vector<vector<int>> result;
};