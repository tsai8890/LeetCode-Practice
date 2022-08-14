#include <vector>
using namespace std;

/*
    Title: 95. Unique Binary Search Trees II
    Time Complexity: O(n x (n! + C(n)))
    Space Complexity: O(4^n / sqrt(n))-extra space

    Algorithm: 
        1. Divide and Conquer
        
    Note:
        1. helper(start, end): return the vector of all possible
           BSTs consisting of {start..end}

        2. Count of BST(n) = Catalan Number(n).
           Catalan Number(n) = (2n!) / {n! x (n+1)!}
                             ~= 4^n / (n^(3/2) x sqrt(pi))

        3. Time Complexity Analysis: 
            C(n) = Catalan Number(n)
            T(n) = T(1) + T(n-2) + T(2) + T(n-3) + ... + T(n-2) + T(1) + theta(n) + C(n)
            
            Consider with no C(n), T(n) = O(n x n!)
            After adding C(n), there are two cases (In fact, I don't know), 
                If C(n) = theta(C(1)+C(n-2) + C(2)+C(n-3) + C(3)+C(n-4) + ... + C(n-2)+C(1)),
                   then T(n) = O(n x n! + n x C(n))
                
                Otherwise, it C(n) = little omega(C(1)+C(n-2) + C(2)+C(n-3) + C(3)+C(n-4) + ... + C(n-2)+C(1)),
                   then T(n) = O(n x n! + C(n)) 

            As a result, we can say that T(n) = O(n x (n! + C(n))), 
            even if there could be a tighter bound.

    Date: 04/22/2022 15:28									
    Time: 15 ms  -- beat 88.72%    
    Memory: 16.2 MB  -- beat 41.62% 
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
    vector<TreeNode*> helper(int start, int end) {
        if (start > end) {
            return vector<TreeNode*>{nullptr};
        }
        
        vector<TreeNode*> res;
        for (int i = start; i <= end; i ++) {
            vector<TreeNode*> left = helper(start, i-1);
            vector<TreeNode*> right = helper(i+1, end);
            for (auto left_child: left) {
                for (auto right_child: right) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = left_child;
                    root -> right = right_child;
                    res.push_back(root);   
                }
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};