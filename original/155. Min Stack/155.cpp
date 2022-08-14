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

    Date: 12/28/2021 20:41							
    Time: 16 ms  -- beat 96.42%
    Memory: 16.3 MB  -- beat 92.36%
*/

class MinStack {
public:
    MinStack() {
        while (!st.empty()) {
            st.pop();
        }
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(make_pair(val, val));
        } else {
            int curMin = min(val, st.top().second);
            st.push(make_pair(val, curMin));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
private:
    stack<pair<int, int>> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */