#include <vector>
#include <stack>
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
        Title: 103. Binary Tree Zigzag Level Order Traversal
        Time Complexity: O(N)

        Algorithm:
            1. BFS

        Note:
            1. 使用兩個stack，一個紀錄正向的node排序，一個紀錄反向的node排序。
            2. 若當前stack[dir]為空，則dir=1-dir，切換到另一個方向的stack。

        Date: 12/20/2021 16:42		
        Time: 0 ms  -- beat 100.00%
        Memory: 12.1 MB  -- beat 76.49%
    */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return vector<vector<int>>();

        stack<pair<int,TreeNode*>> st[2];
        vector<vector<int>> result;
        int dir = 0;
        
        st[0].push(make_pair(0, root));
        
        while (!(st[0].empty() && st[1].empty())) {
            if (st[dir].empty())
                dir = 1 - dir;
            
            auto top = st[dir].top();
            int level = top.first;
            TreeNode* top_node = top.second;
            st[dir].pop();
            
            if (level >= result.size()) {
                result.push_back(vector<int>());
            }
            result[level].push_back(top_node->val);
            
            if (dir == 0) {
                if (top_node->left) {
                    st[1-dir].push(make_pair(level+1, top_node->left));
                }
                if (top_node->right) {
                    st[1-dir].push(make_pair(level+1, top_node->right));
                }
            } else {
                if (top_node->right) {
                    st[1-dir].push(make_pair(level+1, top_node->right));
                }
                if (top_node->left) {
                    st[1-dir].push(make_pair(level+1, top_node->left));
                }
            }
        }
        return result;
    }
};