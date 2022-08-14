# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
        Title: 894. All Possible Full Binary Trees
        Time Complexity: O(N)
        Algorithm: 
            1. Divide & Conquer
        
        Date: 07/15/2021 21:07	
        Time: 564 ms -- beat 5.95%
        Memory: 14.2 MB  -- beat 47.81%
    """
    def allPossibleFBT(self, n: int) -> List[TreeNode]:
        
        if n == 1:
            return [TreeNode()]
        
        else:
            n -= 1
            ret_tree = []
            
            for i in range(1, n):
                left = self.allPossibleFBT(i)
                right = self.allPossibleFBT(n-i)

                for l in left:
                    for r in right:
                        root = ListNode()
                        root.left = l
                        root.right = r
                        
                        ret_tree.append(root)
            return ret_tree