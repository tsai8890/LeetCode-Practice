#include <vector>
#include <algorithm>
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
        Title: 1110. Delete Nodes And Return Forest
        Time Complexity:
            1. O(N*log(1000))

        Algorithm: 
            1. DFS with backtracing
            2. Binary search

        Date: 12/16/2021 22:49					
        Time: 8ms  -- beat 99.96%
        Memory: 25.2 MB  -- beat 78.31%
    */
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        sort(to_delete.begin(), to_delete.end());   
        vector<TreeNode*> result;
        
        if (binary_search(to_delete, root -> val) == -1)
            result.push_back(root);
        dfs(root, to_delete, result);
        return result;
    }
    
    TreeNode* dfs(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& result) {
        if (root -> left) 
            root -> left = dfs(root -> left, to_delete, result);
        if (root -> right) 
            root -> right = dfs(root -> right, to_delete, result);
        
        int find_result = binary_search(to_delete, root -> val);
        if (find_result == -1) {
            return root;
        } else {
            if (root -> left)
                result.push_back(root -> left);
            if (root -> right)
                result.push_back(root -> right);
            return nullptr;
        }
    }
    
    int binary_search(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target < arr[mid]) {
                right = mid - 1;
            } else if (target > arr[mid]) {
                left = mid + 1;
            } else {
                return mid;                
            }
        }
        return -1;        
    }
};