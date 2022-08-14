#include <string>
#include <queue>
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
        Title: 100. Same Tree
        Time Complexity: O(N)

        Algorithm:
            1. BFS

        Note:
            1. 用BFS排出binary tree的唯一node序列字串，
               即可比對兩個binary tree是否一模一樣。

        Date: 12/20/2021 00:11		
        Time: 0 ms  -- beat 100.00%
        Memory: 10.1 MB  -- beat 43.93%
    */
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string res1 = bfs(p);
        string res2 = bfs(q);
        return (res1 == res2);
    }
    
    string bfs(TreeNode* root) {
        string res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            
            if (top == nullptr) {
                res += " ^";
                continue;
            } else{
                res += " " + to_string(top->val);
                q.push(top->left);
                q.push(top->right);
            }
        }
        return res;
    }
};