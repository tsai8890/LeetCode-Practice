# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        arr = []
        if root == None:
            return arr
        
        else:
            if root.left:
                arr += self.inorderTraversal(root.left)    
            
            arr.append(root.val)
            
            if root.right:
                arr += self.inorderTraversal(root.right)
            
            return arr
            