#include <stdio.h>
#include <vector>
using namespace std;

/*
    Title: 716. Max Stack
    Time Complexity: 
        1. push(), pop(), top(), peekMax(): O(1)
        2. popMax(): O(n)

    Algorithm:
        1. Stack

    Note: 
        1. Same techniques as the leetcode 155. Min Stack,
           using two stacks.

        2. There is a faster solution, not yet finished.

    Date: 01/01/2022 19:40									
    Time: 83 ms  -- beat 23.60%
    Memory: 36.3 MB  -- beat 86.96%
*/

class MaxStack {
public:
    MaxStack() {
        st.clear();
        max_st.clear();
        count = 0;
    }
    
    void push(int x) {
        if (st.empty() || x >= max_st.back()) {
            max_st.push_back(x);
        } 
        st.push_back(x);
    }
    
    int pop() {
        if (st.back() == max_st.back()) {
            max_st.pop_back();
        }
        int top = st.back();
        st.pop_back();
        return top;
    }
    
    int top() {
        return st.back();
    }
    
    int peekMax() {
        return max_st.back();
    }
    
    int popMax() {
        vector<int> tmp;
        while (st.back() != max_st.back()) {
            tmp.push_back(st.back());
            st.pop_back();
        }
        st.pop_back();
        
        int max_val = max_st.back();
        max_st.pop_back();
        while (!tmp.empty()) {
            push(tmp.back());
            tmp.pop_back();
        }
        return max_val;
    }
    
    void print() {
        for (auto item : st) {
            printf("%d ", item);
        }
        printf("\n");
        
        for (auto item : max_st) {
            printf("%d ", item);
        }
        printf("\n");
    }

private:
    vector<int> st;
    vector<int> max_st;
    int count = 0;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */