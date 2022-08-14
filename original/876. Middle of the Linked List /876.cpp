#include <iostream>
using namespace std;

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

class Solution {
    /*
        Title: 876. Middle of the Linked List
        Time Complexity: O(N)
        Note:
            1. Two Pointer
            2. One fast pointer(two steps),
               one slow pointer(one step)

        Date: 12/07/2021 12:03			
        Time: 0 ms  -- beat 100.00%
        Memory: 7 MB  -- beat 70.66%
    */
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        while (!(ptr2 == nullptr || ptr2 -> next == nullptr)) {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next -> next;
        }
        return ptr1;
    }
};