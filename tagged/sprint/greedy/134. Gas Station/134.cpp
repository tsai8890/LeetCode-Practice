#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            sum += (gas[i] - cost[i]);
        }
        
        if (sum < 0) {
            return -1;
        }
        
        int begin = -1;
        int remain = 0;
        for (int i = 0; i < n; i ++) {
            if (begin == -1) {
                begin = i;
            }
            
            if (remain + gas[i] - cost[i] >= 0) {
                remain += (gas[i] - cost[i]);
            }
            else {
                begin = -1;
                remain = 0;
            }
        }
        return begin;        
    }
};