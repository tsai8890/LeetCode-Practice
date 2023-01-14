/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for (int i = 1; i < n; i ++) {
           fast = fast->next;
        }

        if (fast->next == nullptr) {
            return head->next;
        }

        ListNode* slow = head;
        ListNode* slowPrev = nullptr;
        while (fast->next != nullptr) {
            fast = fast->next;
            slowPrev = slow;
            slow = slow->next;
        }
        slowPrev->next = slow->next;
        return head;
    }
};