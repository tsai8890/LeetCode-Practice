/*
    Title: 143. Reorder List
    Time Complexity: O(N)
    Algorithm: 
        1. Stack(Deque)
    
    Date: 10/04/2021 23:14		
    Time: 40 ms  -- beat 63.27%
    Memory: 18.2 MB  -- beat 46.85%
*/

#include <iostream>
#include <deque>
using namespace std;

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
        deque<int> deq;
        
        ListNode* tmp = head;
        while (tmp != nullptr) {
            deq.push_back(tmp -> val);
            tmp = tmp -> next;
        }
        
        int len = deq.size();
        if (len == 1) 
            return;
        
        ListNode* cur = head;
        for (int i = 0; i < len / 2; i ++) {
            cur -> val = deq.front();
            deq.pop_front();
            cur = cur -> next;
            
            cur -> val = deq.back();
            deq.pop_back();
            cur = cur -> next;
        }
        
        if (!deq.empty()) {
            cur -> val = deq.front();
            deq.pop_front();
        }
    }
};


