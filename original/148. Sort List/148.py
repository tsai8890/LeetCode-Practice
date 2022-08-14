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
            1. Merge Sort
        
        Date: 07/13/2021 21:59
        Time: 700 ms  -- beat 8.59%
        Memory: 30.3 MB  -- beat 38.54%
    """
    def len_(self, head: ListNode):
        L = 1
        while head.next != None:
            L += 1
            head = head.next
        return L, head
    
    def get_item(self, head: ListNode, index: int):
        count = 0
        while head.next != None and count < index:
            head = head.next
            count += 1
        return head
    
    def merge(self, head1: ListNode, head2: ListNode) -> ListNode:
        new_head = ListNode()
        ret_head = new_head
        
        while head1 != None and head2 != None:
            if head1.val < head2.val:
                new_head.next = head1
                head1 = head1.next
            else:
                new_head.next = head2
                head2 = head2.next
                
            new_head = new_head.next
            new_head.next = None
        
        if head1 == None:
            new_head.next = head2
        else:
            new_head.next = head1
        
        return ret_head.next
    
    def merge_sort(self, head: ListNode) -> ListNode:
        L, end = self.len_(head)
        if L == 1:
            return head
        
        mid = self.get_item(head, (L-1) // 2)
        
        right = self.merge_sort(mid.next)
        mid.next = None
        left = self.merge_sort(head)
        
        return self.merge(left, right)
        
    def sortList(self, head: ListNode) -> ListNode:
        if head == None:
            return None
        
        else:
            return self.merge_sort(head)    