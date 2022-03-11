/*
    ## It's a beautiful and efficient code 
    copied from other user's submission.
    
    Title: 143. Reorder List
    Time Complexity: O(N)
    Algorithm: 
        1. No, but efficient
    
    Date: 10/04/2021 23:27		
    Time: 32 ms  -- beat 95.75%
    Memory: 17.6 MB  -- beat 96.76%
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next){return;}
        ListNode* fp = head, *sp= head;
        while(fp && fp->next){
            fp = fp->next->next;
            sp = sp->next;
        }
        fp = head;
        ListNode* prev = NULL, *next = NULL;
        while(sp){
            next = sp->next;
            sp->next = prev;
            prev = sp;
            sp = next;
        }
        sp = prev;
        ListNode* next_fp = NULL, *next_sp = NULL;
        while(fp->next && sp->next){
            next_fp = fp->next;
            next_sp = sp->next;
            fp->next = sp;
            sp->next = next_fp;
            fp = next_fp;
            sp = next_sp;
        }
    }
};