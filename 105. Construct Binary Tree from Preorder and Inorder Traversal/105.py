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
        
        Date: 07/16/2021 16:58	
        Time: 348 ms -- beat 11.81%
        Memory: 19.1 MB  -- beat 64.39%
    """
    def dfs(self, preorder, inorder, pre_i, in_i, in_j) -> TreeNode:
        if pre_i == len(preorder) - 1:
            return TreeNode(preorder[pre_i])
        
        root = TreeNode(preorder[pre_i])
        for i in range(in_i, in_j+1):
            if inorder[i] == root.val:
                mid = i
                break
        
        if in_i < mid:
            root.left = self.dfs(preorder, inorder, pre_i+1, in_i, mid-1)
            pre_i += (mid - in_i)
        
        if mid < in_j:
            root.right = self.dfs(preorder, inorder, pre_i+1, mid+1, in_j)
        
        return root
        
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        return self.dfs(preorder, inorder, 0, 0, len(inorder)-1)
    
    