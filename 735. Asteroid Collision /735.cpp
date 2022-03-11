#include <stack>
#include <vector>
using namespace std;

class Solution {
    /*
        Title: 735. Asteroid Collision
        Time Complexity: O(N)
        Algorithm: 
            1. Stack
        
        Note:
            1. 碰到左右相撞，左右抵銷的，想到用stack，求你啦

        Date: 12/15/2021 19:34				
        Time: 8ms  -- beat 96.01%
        Memory: 17.7 MB  -- beat 57.53%
    */
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int i = 0; i < asteroids.size(); i ++) {
            if (st.empty()) {
                st.push(asteroids[i]);
                
            } else if (st.top() < 0) {
                st.push(asteroids[i]);
            
            } else if (st.top() > 0) {
                if (asteroids[i] > 0) {
                    st.push(asteroids[i]);
                    
                } else {
                    while (!st.empty()) {
                        if (st.top() < 0) 
                            break;
                        else if (st.top() > 0 && st.top() + asteroids[i] >= 0)
                            break;
                        else                         
                            st.pop();                        
                    }
                    
                    if (st.empty())
                        st.push(asteroids[i]);
                    else {
                        if (st.top() < 0)
                            st.push(asteroids[i]);
                        else {
                            if (st.top() == -asteroids[i]) {
                                st.pop();
                            }
                        }
                    }
                }
            }
        }
        
        int size = st.size() - 1;
        vector<int> res(st.size());
        while (!st.empty()) {
            res[size--] = st.top();
            st.pop();
        }
        return res;
    }
};