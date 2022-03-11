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
        Title: 101. Symmetric Tree
        Time Complexity: O(N)

        Algorithm:
            1. BFS

        Note:
            1. 用BFS排出binary tree的唯一node序列字串，
               即可比對兩個binary tree是否一模一樣。
            
            2. 這題要求root的左右必須要鏡像對稱，可以透過BFS的方向來
               控制，root左邊的BFS都先push left再right，
               root右邊的BFS都先push right再left，當左右兩邊的BFS
               字串相同，即為鏡像對稱。

        Date: 12/20/2021 00:29		
        Time: 0 ms  -- beat 100.00%
        Memory: 16.9 MB  -- beat 7.29%
    */
public:
    bool isSymmetric(TreeNode* root) {
        string res1 = bfs(root->left, 0);
        string res2 = bfs(root->right, 1);
        return (res1 == res2);
    }
    
    string bfs(TreeNode* root, int dir) {
        string res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            
            if (top == nullptr) {
                res += "^ ";
                continue;
            } 
            else {
                res += to_string(top->val) + " ";
                if (dir == 0) {
                    q.push(top->left);
                    q.push(top->right);
                } 
                else {
                    q.push(top->right);
                    q.push(top->left);
                }
            }
        }
        return res;
    }
};