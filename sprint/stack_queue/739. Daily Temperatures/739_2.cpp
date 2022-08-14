#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> daysToWait(n, 0);
        
        for (int i = 0; i < n; i ++) {
            if (!st.empty()) {
                int topId;
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    topId = st.top();
                    daysToWait[topId] = i - topId;
                    st.pop();
                }
            }
            st.push(i);
        }
        return daysToWait;
    }
};