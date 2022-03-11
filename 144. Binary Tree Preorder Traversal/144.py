# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
        Title: 144. Binary Tree Preorder Traversal
        Time Complexity: O(N)
        Algorithm: 
            1. Preorder traversal of tree
        
        Date: 07/14/2021 00:21	
        Time: 32 ms  -- beat 61.57%
        Memory: 14.2 MB  -- beat 44.73%
    """
    
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if root == None:
            return []
        else:
            arr = []
            arr.append(root.val)
            
            if root.left:
                arr += self.preorderTraversal(root.left)
                
            if root.right:
                arr += self.preorderTraversal(root.right)
            
            return arr
        