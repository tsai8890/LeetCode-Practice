#include <deque>

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int nLogs = logs.size();
        vector<int> res(n, 0);
        deque<pair<int, int>> dq;
        
        string log, type;
        int id, time;
        int j = 0;
        for (int i = 0; i < nLogs; i ++) {
            log = logs[i];

            j = 0;
            id = 0;
            time = 0;
            type.clear();

            while (log[j] != ':') {
                id = 10*id + (log[j++] - '0');
            }
            j++;
            
            while (log[j] != ':') {
                type += log[j++];
            }
            j++;
            
            while (j < log.length()) {
                time = 10*time + (log[j++]-'0');
            }
            
            if (type == "start") {
                dq.push_back(make_pair(id, time));
            }
            else {
                pair<int, int> topLog = dq.back();
                dq.pop_back();
                int duration = time - topLog.second + 1;
                res[topLog.first] += duration;
                if (!dq.empty()) {
                    res[dq.back().first] -= duration;
                }
            }
        }
        return res;
    }
};