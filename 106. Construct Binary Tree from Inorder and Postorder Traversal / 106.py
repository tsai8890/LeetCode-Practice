# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
        Title: 106. Construct Binary Tree from Inorder and Postorder Traversal
        Time Complexity: O(N)
        Algorithm: 
            1. Divide & Conquer
            2. Use a table to allow O(1)-time searching 
        
        Date: 07/16/2021 17:38		
        Time: 48 ms -- beat 98.31%
        Memory: 18.3 MB  -- beat 93.58%
    """

    def dfs(self, pos_i, in_i, in_j) -> TreeNode:
        if in_i == in_j:
            return TreeNode(self.inorder[in_j])
        
        root = TreeNode(self.postorder[pos_i])
        mid = self.table[root.val]
        
        if mid < in_j:
            root.right = self.dfs(pos_i-1, mid+1, in_j)
            pos_i -= (in_j - mid)
            
        if in_i < mid:
            root.left = self.dfs(pos_i-1, in_i, mid-1)
        
        return root
            
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        self.inorder = inorder
        self.postorder = postorder
        self.table = {}
        for i, num in enumerate(inorder):
            self.table[num] = i
        
        return self.dfs(len(inorder)-1, 0, len(inorder)-1)
        