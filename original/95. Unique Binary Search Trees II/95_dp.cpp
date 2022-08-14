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
           
        3. Time Complexity Analysis:
            There are n^2 subproblems, and each takes O(n)-time to pick the root node,
            which takes O(n^3)-time at the end.

            However, if we consider the time consumed on combination of the two subtrees, 
            we can find that for a sub-problem(left=a, right=b), 
            it takes C(b-a+1)-time on combination,
            where C(n) represents the Catalan Number(n). 

            We define the size of sub-problem(left=a, right=b) as (b-a+1)
            There are n sub-problems with size = 1
            There are n-1 sub-problems with size = 2
            There are n-2 sub-problems with size = 3
            ...
            ...
            There are 1 sub-problem with size = n

            As a result, 
            the time consumed on combination is nxC(1) + (n-1)xC(2) + ... + 1xC(n)
            
            nxC(1) + (n-1)xC(2) + ... + 1xC(n)
            = {(n-2)xC(1) + (n-3)xC(2) + (n-4)xC(3) + ... 1xC(n-2)}
                + 2(C(1)+C(2)+...+C(n-1)) + C(n)
            = C(n) + 2(C(1)+C(2)+...+C(n-1)) + C(n)
            <= 2xC(n) + 2{C(1)xC(n-2) + C(2)xC(n-3) + ... C(n-2)xC(1) + C(n)}
            = 2xC(n) + 2xC(n) + 2xC(n) = 6xC(n)
            
            As we can see, the total time consumed on combination is O(C(n)),
            plus the root-picking time, O(n^3)-time, the total time complexity 
            of this algorithm is O(C(n)) ~= O(4^n)

            And the complexity of this solution is dominated by
            the count of BST(n), which is O(4^n)
        
        4. 利用memo[i][j]來儲存使用{i..j}所有可能產生的BST，雖然時間複雜度一樣，但是卻少算了很多東西。
           相反地，空間複雜度會高一些，因為使用了O(nxn)-size的dp array。

        5. 實作有點麻煩，要想一下～

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