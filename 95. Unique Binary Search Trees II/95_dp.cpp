#include <vector>
using namespace std;

/*
    Title: 95. Unique Binary Search Trees II
    Time Complexity: O(4^n / (n^(3/2)))
    Space Complexity: O(4^n x sqrt(n))-extra space

    Algorithm: 
        1. Divide and Conquer
        
    Note:
        1. helper(start, end): return the vector of all possible
           BSTs consisting of {start..end}

        2. Count of BST(n) = Catalan Number(n).
           Catalan Number(n) = (2n!) / {n! x (n+1)!}
                             ~= 4^n / (n^(3/2) x sqrt(pi))

           And the complexity of this solution is dominated by
           the count of BST(n), which is O(4^n)
        
        3. 利用memo[i][j]來儲存使用{i..j}所有可能產生的BST，雖然時間複雜度一樣，但是卻少算了很多東西。
           相反地，空間複雜度會高一些，因為使用了O(nxn)-size的dp array。

        4. 實作有點麻煩，要想一下喔～

    Date: 04/22/2022 17:04									
    Time: 11 ms  -- beat 97.88%    
    Memory: 12.1 MB  -- beat 98.98% 
*/

// Definition for a binary tree node.
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
    vector<TreeNode*> helper(int start, int end, 
                             vector<vector<vector<TreeNode*>>>& memo) {
        if (start > end) {
            return vector<TreeNode*>{nullptr};
        }
        
        if (memo[start][end].size() != 0) {
            return memo[start][end];
        }
        
        memo[start][end] = vector<TreeNode*>();
        for (int i = start; i <= end; i ++) {
            vector<TreeNode*> left = helper(start, i-1, memo);
            vector<TreeNode*> right = helper(i+1, end, memo);
            
            for (auto left_child: left) {
                for (auto right_child: right) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = left_child;
                    root -> right = right_child;
                    memo[start][end].push_back(root);   
                }
            }
        }
        return memo[start][end];
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector< vector <vector <TreeNode*> > > memo(
            n+1, vector< vector<TreeNode*> >(n+1, vector<TreeNode*>()));
        return helper(1, n, memo);
    }
};