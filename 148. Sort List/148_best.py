# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    """
        Title: 148. Sort List
        Time Complexity: O(Nlog(N))
        Algorithm: 
            1. Convert Linked list to Python list
            2. using built-in sort()
        
        Date: 07/13/2021 21:59
        Time: 172 ms  -- beat 93.78%
        Memory: 30.3 MB  -- beat 26.58%
    """

    def sortList(self, head: ListNode) -> ListNode:
        arr = []
        while head != None:
            arr.append(head)
            head = head.next
        
        arr.sort(key=lambda x: x.val)
        
        head = ListNode()
        ret_head = head
        for node in arr:
            head.next = node
            head = head.next
            
        head.next = None
        return ret_head.next