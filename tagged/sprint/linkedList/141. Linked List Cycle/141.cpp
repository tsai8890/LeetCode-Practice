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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return false;
        }

        ListNode* fast = head->next->next;
        ListNode* slow = head->next;

        while (true) {
            if (fast->next == nullptr || fast->next->next == nullptr) {
                return false;
            }
            if (fast == slow) {
                return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
    }
};