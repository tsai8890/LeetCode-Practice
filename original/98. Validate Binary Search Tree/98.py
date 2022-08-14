# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        def dfs(root: TreeNode) -> tuple:
            min_, max_ = root.val, root.val
            if root.left:
                left_bst, left_min, left_max = dfs(root.left)
                if (not left_bst) or left_max >= root.val:
                    return False, -1, -1
                min_ = left_min
                
            if root.right:
                right_bst, right_min, right_max = dfs(root.right)
                if (not right_bst) or right_min <= root.val:
                    return False, -1, -1
                max_ = right_max
        
            return True, min_, max_
            
        return dfs(root)[0]
            