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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHead = head->next;

        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* tmp;
        while (true) {
            tmp = cur->next;
            cur->next = prev;
            if (tmp == nullptr || tmp->next == nullptr) {
                prev->next = tmp;
                break;
            }
            else {
                prev->next = tmp->next;
                prev = tmp;
                cur = tmp->next;
            }
        }
        return newHead;
    }
};