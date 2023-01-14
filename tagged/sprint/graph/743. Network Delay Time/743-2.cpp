#include <utility>
#include <queue>
#include <vector>

#define Node pair<int,int>
#define Edge pair<int,int>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edge>> graph(n+1);
        for (auto& time: times) {
            graph[time[0]].push_back(make_pair(time[1], time[2]));
        }
        
        priority_queue<Node, vector<Node>, greater<Node>> pq;    
        pq.push(make_pair(0, k));
        vector<bool> visited(n+1, false);

        Node curNode;
        int maxTime = 0, count = 0;
        while (!pq.empty()) {
            curNode = pq.top();
            pq.pop();
            if (!visited[curNode.second]) {
                count += 1;
                visited[curNode.second] = true;
                maxTime = curNode.first;
                for (auto& edge: graph[curNode.second]) {
                    pq.push(make_pair(curNode.first + edge.second, edge.first));
                }
            }
        }
        return (count == n) ? maxTime : -1; 
    }
};