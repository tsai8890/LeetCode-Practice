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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur != nullptr) {
            if (cur->val == val) {
                if (prev != nullptr) {
                    prev->next = cur->next;
                    cur = prev->next;
                }
                else {
                    head = cur->next;
                    cur = head;
                }
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }  
        return head;  
    }
};