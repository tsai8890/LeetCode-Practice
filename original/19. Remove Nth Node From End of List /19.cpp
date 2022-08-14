using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        this -> val = 0;
        this -> next = nullptr;
    }

    ListNode(int val) {
        this -> val = val;
        this -> next = nullptr;
    }

    ListNode(int val, ListNode* next) {
        this -> val = val;
        this -> next = next;
    }
};

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

class Solution {
    /*
        Title: 19. Remove Nth Node From End of List
        Time Complexity: O(N)
        Note:
            1. Two Pointer
            2. The two pointers keep the distance of n - 1
            3. Use the bef pointer to remove the node pointed by ptr1

        Date: 12/07/2021 12:26			
        Time: 0 ms  -- beat 100.00%
        Memory: 10.7 MB  -- beat 73.51%
    */
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        ListNode* bef = nullptr;
        
        for (int i = 0; i < n - 1; i ++) {
            ptr2 = ptr2 -> next;
        }
        
        while (ptr2 -> next != nullptr) {
            if (bef == nullptr)
                bef = head;
            else 
                bef = bef -> next;
            
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        
        if (bef == nullptr)
            head = ptr1 -> next;
        else 
            bef -> next = ptr1 -> next;
        return head;
    }
};