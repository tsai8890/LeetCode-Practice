/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 1;
        ListNode* curA = headA;
        while (curA != nullptr) {
            curA = curA->next;
            lenA ++;
        }

        int lenB = 1;
        ListNode* curB = headB;
        while (curB != nullptr) {
            curB = curB->next;
            lenB ++;
        }

        ListNode* fast = (lenA > lenB) ? headA : headB;
        ListNode* slow = (lenA > lenB) ? headB : headA;
        int diff = (lenA > lenB) ? (lenA - lenB) : (lenB - lenA);
        for (int i = 0; i < diff; i ++) {
            fast = fast->next;
        }

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};