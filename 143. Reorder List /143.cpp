#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    /*
        Title: 143. Reorder List
        Time Complexity: O(N)
        Algorithm: 
            1. No, but efficient
        
        Date: 12/23/2021 03:11		
        Time: 24 ms  -- beat 99.91%
        Memory: 19.1 MB  -- beat 10.08%
    */
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> node_arr;
        ListNode* cur = head;
        while (cur != nullptr) {
            node_arr.push_back(cur);
            cur = cur -> next;
        }
        
        ListNode* last_node;
        for (int i = 0; i < node_arr.size() / 2; i ++) {
            if (i != 0)
                last_node -> next = node_arr[i];
                
            node_arr[i] -> next = node_arr[node_arr.size()-i-1];
            last_node = node_arr[node_arr.size()-i-1];
        }
        
        if (node_arr.size() % 2 == 0) {
            last_node -> next = nullptr;
        } else {
            last_node -> next = node_arr[node_arr.size() / 2];
            node_arr[node_arr.size() / 2] -> next = nullptr;
        }
//         if (!head->next || !head->next->next) {
//             return;
//         }
        
//         ListNode* fp = head, *sp = head;
//         while (fp && fp->next) {
//             fp = fp -> next -> next;
//             sp = sp -> next;
//         }
//         fp = head;
        
//         ListNode *prev = nullptr, *next;
//         while (sp) {
//             next = sp -> next;
//             sp -> next = prev;
//             prev = sp;
//             sp = next;
//         }
//         sp = prev;
        
//         while (sp -> next) {
//             ListNode* next_fp = fp -> next;
//             ListNode* next_sp = sp -> next;
//             fp -> next = sp;
//             sp -> next = next_fp;
//             fp = next_fp;
//             sp = next_sp;
//         }
    }
};