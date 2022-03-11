#include <queue>
#include <utility>
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
        Title: 102. Binary Tree Level Order Traversal
        Time Complexity: O(N)

        Algorithm:
            1. BFS

        Note:
            1. 放入BFS的queue時，要多紀錄一個level的資訊，
               這樣才知道要放到result的對應的vector裏

        Date: 12/20/2021 15:53		
        Time: 0 ms  -- beat 100.00%
        Memory: 12.3 MB  -- beat 96.26%
    */
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return vector<vector<int>>();
        
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> result;
        q.push(make_pair(root, 0));
        
        while (!q.empty()) {
            TreeNode* top_node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if (result.size() <= level) {
                result.push_back(vector<int>());
            }
            result[level].push_back(top_node->val);
            
            if (top_node->left) {
                q.push(make_pair(top_node->left, level+1));                
            }
            if (top_node->right) {
                q.push(make_pair(top_node->right, level+1));
            }
        }
        return result;
    }
};