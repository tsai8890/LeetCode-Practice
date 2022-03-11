#include <vector>
using namespace std;

/*
    Title: 134. Gas Station
    Time Complexity: 
        1. O(n)

    Algorithm:
        1. Greedy

    Note:
        1. If we start from position i and end at position j,
           which means when we start from [i+1 ... j], we cannot
           reach the position behind j. 

    Date: 01/02/2022 03:20										
    Time: 48 ms  -- beat 79.28%
    Memory: 49.8 MB  -- beat 44.67%
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curPos = 0;
        while (curPos < gas.size()) {
            int add_steps = move(curPos, gas, cost);
            if (add_steps == gas.size())
                return curPos;
            else {
                curPos += add_steps + 1;
            }
        }
        return -1;
    }
    
    int move(int start, vector<int>& gas, vector<int>& cost) {
        if (gas[start] < cost[start])
            return 0;
        
        int remain_gas = gas[start] - cost[start];
        int steps = 0;
        
        while (steps < gas.size()) {
            int nextPos = (start+steps+1) % gas.size();
            if (remain_gas + gas[nextPos] >= cost[nextPos]) {
                remain_gas += gas[nextPos] - cost[nextPos];
                steps += 1;
            }
            else {
                break;
            }
        }
        return steps;
    }
};