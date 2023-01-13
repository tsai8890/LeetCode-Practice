#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

class MyLinkedList {
public:
    MyLinkedList() {
        nNodes = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int index) {
        if (index < 0 || index > nNodes-1) {
            return -1;
        }
        else {
            ListNode* cur = head;
            for (int i = 0; i < index; i ++) {
                cur = cur->next;
            }
            return cur->val;
        }
    }
    
    void addAtHead(int val) {
        ListNode* newHead = (ListNode*)(malloc(sizeof(ListNode)));
        newHead->val = val;
        newHead->next = head;
        head = newHead;

        if (nNodes == 0) {
            tail = head;
        }
        nNodes++;
    }
    
    void addAtTail(int val) {
        ListNode* newTail = (ListNode*)(malloc(sizeof(ListNode)));
        newTail->val = val;
        newTail->next = nullptr;
        if (nNodes == 0) {
            head = newTail;
        }
        else {
            tail->next = newTail;
        }
        tail = newTail;
        nNodes++;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
        }
        else if (index == nNodes) {
            addAtTail(val);
        }
        else if (0 < index && index <= nNodes-1) {
            ListNode* cur = head;
            ListNode* prev = nullptr;
            for (int i = 0; i < index; i ++) {
                prev = cur;
                cur = cur->next;
            }
            ListNode* newNode = (ListNode*)(malloc(sizeof(ListNode)));
            newNode->val = val;
            prev->next = newNode;
            newNode->next = cur;
            nNodes ++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index == 0) {
            ListNode* headNext = head->next;
            free(head);
            head = headNext;
            nNodes --;
        }
        else if (0 < index && index <= nNodes-1) {
            ListNode* cur = head;
            ListNode* prev = nullptr;
            for (int i = 0; i < index; i ++) {
                prev = cur;
                cur = cur->next;
            }

            prev->next = cur->next;
            if (index == nNodes-1) {
                tail = prev;
            }
            free(cur);
            nNodes --;
        }
    }

private:
    int nNodes;
    ListNode* head;
    ListNode* tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */