#include <vector>
#include <stack>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> daysToWait(n, 0);
        
        for (int i = 0; i < n; i ++) {
            if (!st.empty()) {
                while (!st.empty() && temperatures[i] > st.top().second) {
                    pair<int, int> curPair = st.top();
                    daysToWait[curPair.first] = i - curPair.first;
                    st.pop();
                }
            }
            st.push(make_pair(i, temperatures[i]));
        }
        return daysToWait;
    }
};