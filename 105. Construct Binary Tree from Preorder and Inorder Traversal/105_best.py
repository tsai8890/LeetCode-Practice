# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    """
        Title: 105. Construct Binary Tree from Preorder and Inorder Traversal
        Time Complexity: O(N)
        Algorithm: 
            1. Divide & Conquer
            2. Use a table to allow O(1)-time searching 
        
        Date: 07/16/2021 17:17		
        Time: 52 ms -- beat 96.20%
        Memory: 18.5 MB  -- beat 90.82%
    """
    def dfs(self, preorder, inorder, pre_i, in_i, in_j) -> TreeNode:
        if pre_i == len(preorder) - 1:
            return TreeNode(preorder[pre_i])
        
        root = TreeNode(preorder[pre_i])
        mid = self.table[root.val]
        
        if in_i < mid:
            root.left = self.dfs(preorder, inorder, pre_i+1, in_i, mid-1)
            pre_i += (mid - in_i)
        
        if mid < in_j:
            root.right = self.dfs(preorder, inorder, pre_i+1, mid+1, in_j)
        
        return root
        
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        self.table = {}
        for i, num in enumerate(inorder):
            self.table[num] = i
            
        return self.dfs(preorder, inorder, 0, 0, len(inorder)-1)
    
    