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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) {
            return nullptr;
        }

        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        int steps = 1;
        while (true) {
            if (!fast->next || !fast->next->next) {
                return nullptr;
            }
            if (fast == slow) {
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
            steps++;
        }

        fast = head;
        for (int i = 0; i < steps; i ++) {
            fast = fast->next;
        }

        slow = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};