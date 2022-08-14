#include <unordered_map>
using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        int nTasks = tasks.size(), curTask = 0;
        unordered_map<int, long long> hashMap;
        long long days = 1;

        while (curTask < nTasks) {
            int taskId = tasks[curTask];
            if (hashMap.find(taskId) == hashMap.end()) {
                hashMap[taskId] = days;
                days += 1;
            }
            else if (days - hashMap[taskId] >= space+1) {
                hashMap[taskId] = days;
                days += 1;
            }
            else {
                days = hashMap[taskId] + space + 1;
                hashMap[taskId] = days;
                days += 1;
            }
            curTask += 1;
        }
        return days-1;
    }
};