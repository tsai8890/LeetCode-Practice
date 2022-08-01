#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> daysToWait(n, -1);
        daysToWait.back() = 0;
        
        for (int i = n-2; i >= 0; i --) {
            int curPos = i+1;
            int temp = temperatures[i];

            while (true) {
                if (temp < temperatures[curPos]) {
                    daysToWait[i] = curPos - i;
                    break;
                }
                else {
                    if (daysToWait[curPos] == 0) {
                        daysToWait[i] = 0;
                        break;
                    }
                    curPos = curPos + daysToWait[curPos];
                }
            }
        }            
        return daysToWait;
    }
};