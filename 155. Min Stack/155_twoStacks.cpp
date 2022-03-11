#include <stack>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

/*
    Title: 155. Min Stack
    Time Complexity: 
        1. push: O(1)
        2. pop: O(1)
        3. getMin: O(1)

    Algorithm:
        1. Stack

    Note: 
        1. Use two stacks

    Date: 12/28/2021 21:03								
    Time: 16 ms  -- beat 96.42%
    Memory: 16.3 MB  -- beat 92.36%
*/

class MinStack {
public:
    MinStack() {
        while (!st.empty()) {
            st.pop();
        }
        
        while (!min_st.empty()) {
            min_st.pop();
        }
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            min_st.push(val);
        } else {
            if (val <= min_st.top()) {
                min_st.push(val);
            }
            st.push(val);
        }
    }
    
    void pop() {
        if (min_st.top() == st.top()) {
            min_st.pop();   
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
private:
    stack<int> st;
    stack<int> min_st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */