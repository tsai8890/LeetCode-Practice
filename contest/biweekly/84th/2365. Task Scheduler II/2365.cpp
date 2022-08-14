#include <unordered_map>
using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        int nTasks = tasks.size();
        unordered_map<int, long long> hashMap;
        long long days = 1;
        
        for (int i = 0; i < nTasks; i ++) {
            if (hashMap.find(tasks[i]) != hashMap.end()) {
                days = max(days, hashMap[tasks[i]]+space+1);
            }
            hashMap[tasks[i]] = days++;
        }
        return days-1;
    }
};